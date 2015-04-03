'''
Created on 30 October 2012

'''
import os,time,subprocess,sys,time,math,multiprocessing #,numpy
from ForwardFinancialFramework.Platforms.MulticoreCPU import MulticoreCPU_MonteCarlo
from ForwardFinancialFramework.Underlyings import Underlying
from ForwardFinancialFramework.Derivatives import Option
from ForwardFinancialFramework.Solvers.MonteCarlo import MonteCarlo
import MaxelerFPGA

class MaxelerFPGA_MonteCarlo(MulticoreCPU_MonteCarlo.MulticoreCPU_MonteCarlo):
  c_slow = False
  delay = 10
  pipelining = 1
  instances=1
  
  def __init__(self,derivative,paths,platform,points=4096,reduce_underlyings=True,instance_paths=None,c_slow=None,pipelining=None,instances=None):
    self.c_slow = c_slow
    self.pipelining = pipelining
    self.instances = instances
    
    MulticoreCPU_MonteCarlo.MulticoreCPU_MonteCarlo.__init__(self,derivative,paths,platform,reduce_underlyings)
    self.delay = self.get_delay()

    self.solver_metadata["instances"] = self.instances
    if (not(instance_paths) and self.c_slow): self.solver_metadata["instance_paths"] = 1000*((self.delay-self.delay%1000)/1000+1) #rounding up the number of paths to the nearest 1000
    elif(not(instance_paths)): self.solver_metadata["instance_paths"] = 1000 #this gives us plenty of time to do the necessary accumulation on the CPU
    else: self.solver_metadata["instance_paths"] = instance_paths #using the specified value
    self.solver_metadata["path_points"] = points
    self.solver_metadata["delay"] = self.delay
        
    self.iterations = int(self.solver_metadata["paths"]/self.solver_metadata["instance_paths"]) #calculating the number of iterations required of the kernel
    
    #self.utility_libraries = ["stdio.h","stdlib.h","stdint.h","pthread.h","MaxCompilerRT.h","sys/time.h","sys/resource.h","gauss.h"] #"mersenne_twister_seeding.h"
    self.utility_libraries += ["Maxfiles.h","MaxSLiCInterface.h","gauss.h"]    

    self.activity_thread_name = "maxeler_montecarlo_activity_thread"
    self.floating_point_format = "float"
    
  def set_default_parameters(self):
    if not(self.pipelining): self.pipelining = 1
    self.delay = self.get_delay()
    if not(self.instances):
      heston_count = 0
      black_scholes_count = 0
      underlying_count = 0
      for d in self.derivative:
	for u in d.underlying:
	  if("heston" in u.name): heston_count += 1
	  elif("black_scholes" in u.name): black_scholes_count += 1
	  else: underlying_count += 1
	
      self.instances = max(1,20/(heston_count*2.2 + black_scholes_count + underlying_count))
      
    if not(self.c_slow): self.c_slow = True  

  def generate_name(self):
    self.set_default_parameters()
    MonteCarlo.MonteCarlo.generate_name(self) 
    #self.set_default_parameters()
    #print("_cslow_%s_pipe_%d_insts_%d_delay_%d"%(str(self.c_slow),self.pipelining,self.instances,self.delay))
    self.output_file_name += "_cslow_%s_pipe_%d_insts_%d_delay_%d_board_%s"%(str(self.c_slow),self.pipelining,self.instances,self.delay,self.platform.board)
  
  def generate_identifier(self): return ["//%s.c Generated by Monte Carlo Maxeler Solver"%self.output_file_name]
  
  def generate(self,override=True,verbose=False,debug=False):
    #Generate C Host Code largely using Multicore infrastructure
    MulticoreCPU_MonteCarlo.MulticoreCPU_MonteCarlo.generate(self,"_Host_Code.c",override,verbose=verbose,debug=debug)
    
    #Generate Maxeler Kernel Code
    kernel_code_string = self.generate_kernel()
    self.generate_source(kernel_code_string,"_Kernel.maxj")
    if(debug): print "Generated %s/%s_Kernel.maxj"%(self.platform.absolute_platform_directory(),self.output_file_name)    

    #Generate Maxeler Manager Code
    manager_code_string = self.generate_manager()
    self.generate_source(manager_code_string,"_Manager.maxj")
    if(debug): print "Generated %s/%s_Manager.maxj"%(self.platform.absolute_platform_directory(),self.output_file_name)

    #Generate Maxeler Makefile
    #self.generate_makefile()
  
  def generate_seeding_function(self):
    output_list = []
    
    output_list.append("void rng_seeding(int index,uint32_t seed,rng_state_t *state){")
    output_list.append("state->s1 = 2 + seed;")
    output_list.append("state->s2 = 8 + seed;")
    output_list.append("state->s3 = 16 + seed;")
    output_list.append("state->offset = offset;")
    output_list.append("__random32(state);")
    output_list.append("}")
    
    return output_list
  
  def generate_activity_thread(self):
    output_list = []

    output_list.append("//*MC Maxeler Activity Thread Function*")
    output_list.append("void * %s(void* thread_arg){"%self.activity_thread_name)
    output_list.append("struct thread_data* temp_data;")
    output_list.append("temp_data = (struct thread_data*) thread_arg;")  
    
    output_list.append("//**Creating kernel IO variables**")
    output_list.append("uint32_t *seeds_in;")
    #output_list.append("long *temp_seeds,*temp_seeds2;")
    output_list.append("float *values_out;")
    
    seeds_in = len(self.underlying)*2 #math.ceil(float(len(self.underlying))/2) #Making sure seeds in is in increments of 128 bits (groups of 4 x 32 bit variables)
    values_out = math.ceil(float(len(self.derivative))/2) #Making sure values are in increments of 128 bits

    output_list.append("seeds_in = malloc(%d*instance_paths*sizeof(uint32_t));"%(int(seeds_in*4)))
    output_list.append("values_out = malloc(%d*instance_paths*sizeof(float));"%(int(values_out*4)))
    #output_list.append("posix_memalign(&seeds_in,%d,sizeof(uint32_t)*%d);"%(seeds_in*4,self.iterations*seeds_in*4))
    #output_list.append("posix_memalign(&values_out,%d,sizeof(float)*%d);"%(values_out*4,self.iterations*values_out*4))
    
    for d in range(len(self.derivative)): 
      output_list.append("long double temp_total_%d=0;"%d)
      output_list.append("long double temp_value_sqrd_%d=0;"%d)
    
    output_list.append("//**Generating initial random seed**")
    output_list.append("uint32_t initial_seed = temp_data->thread_rng_seed;") #%%((uint32_t)pow(2,31)-%d);"%(seeds_in*self.iterations)) #Start the seeds off at some random point
    output_list.append("rng_state_t temp_state_x,temp_state_y;")
    #output_list.append("srand48(start.tv_nsec);")
    
    output_list.append("int loops = ceil(((float)paths)/instance_paths/instances);");
    output_list.append("if(loops==0) loops = 1;")
    output_list.append("unsigned int paths_count = 0;")
    output_list.append("for (i=0;i < loops;++i){")
    
    output_list.append("//**Populating Seed Array(s)**")
    for index,u in enumerate(self.underlying):
    	
	output_list.append("for (j=0;j<(instance_paths);++j){")
	#output_list.append("initial_seed = (uint32_t)(drand48()*pow(2,32)-16);");
	output_list.append("ctrng_seed(10,initial_seed,&temp_state_x);")
	output_list.append("seeds_in[j+%d*8*instance_paths] = temp_state_x.s1;"%index)
	output_list.append("seeds_in[j+1*instance_paths+%d*8*instance_paths] = temp_state_x.s2;"%index)
	output_list.append("seeds_in[j+2*instance_paths+%d*8*instance_paths] = temp_state_x.s3;"%index)
	output_list.append("seeds_in[j+3*instance_paths+%d*8*instance_paths] = temp_state_x.offset;"%index)
	
	#output_list.append("initial_seed = (uint32_t)(drand48()*pow(2,32)-16);");
	output_list.append("initial_seed = __random32(&temp_state_x);");
	output_list.append("ctrng_seed(10,initial_seed,&temp_state_y);")
	output_list.append("seeds_in[j+4*instance_paths+%d*8*instance_paths] = temp_state_y.s1;"%index)
	output_list.append("seeds_in[j+5*instance_paths+%d*8*instance_paths] = temp_state_y.s2;"%index)
	output_list.append("seeds_in[j+6*instance_paths+%d*8*instance_paths] = temp_state_y.s3;"%index)
	output_list.append("seeds_in[j+7*instance_paths+%d*8*instance_paths] = temp_state_y.offset;"%index)
	output_list.append("initial_seed = __random32(&temp_state_y);");
	output_list.append("}")
	
    
    output_list.append("//**Running on the FPGA**")
    output_list.append("%s("%self.output_file_name)
    output_list.append("//****Scaler Attributes****") 
    temp_list = []
    for index,u_a in enumerate(sorted(self.underlying_attributes)):
        for a in u_a:
            attribute = "%s_%d_%s," % (self.underlying[index].name,index,a)
	    temp_list += [attribute]
            #output_list.append("max_set_scalar_input_f(device,\"%s_Kernel.%s\",%s,FPGA_A);"%(self.output_file_name,attribute,attribute))
    
    for index,o_a in enumerate(sorted(self.derivative_attributes)):
        for a in o_a:
            attribute = "%s_%d_%s," % (self.derivative[index].name,index,a)
            temp_list += [attribute]
	    #output_list.append("max_set_scalar_input_f(device,\"%s_Kernel.%s\",%s,FPGA_A);"%(self.output_file_name,attribute,attribute))
    output_list += sorted(temp_list)    

    output_list.append("//****Inputs and Output****") 
    for index in range(len(self.underlying)*8): output_list.append("&(seeds_in[%d*instance_paths]),"%(index))
    for index in range(len(self.derivative)*2): output_list.append("&(values_out[%d*instance_paths]),"%(index))
    output_list[-1] = "%s"%output_list[-1][:-1] #removing the final comma
    output_list.append(");")
    
    output_list.append("//**Post-Kernel Aggregation**")
    output_list.append("for (j=0;(j<(instance_paths)&&(paths_count<paths));++j){")
    for index,d in enumerate(self.derivative):
      output_list.append("temp_total_%d += values_out[j+%d*instance_paths*2];"%(index,index))
      output_list.append("temp_value_sqrd_%d += values_out[j+instance_paths*1+%d*instance_paths*2];"%(index,index))
      output_list.append("paths_count += %d;"%self.instances)
    output_list.append("}")
    
      #output_list.append("if(values_out[i*%d+%d]){printf(\"%%d - %%f\\n\",i,values_out[i*%d+%d]);}"%(values_out*4,index,values_out*4,index))
    
    #for d in self.derivative:
      #index = self.derivative.index(d)
      #output_list.append("double temp_sample_std_dev_%d = pow((temp_value_sqrd_%d/temp_data->thread_paths-pow(temp_total_%d/temp_data->thread_paths,2))/(temp_data->thread_paths-1),0.5);"%(index,index,index))
      #output_list.append("double temp_sample_std_error_%d = temp_sample_std_dev_%d/pow(temp_data->thread_paths,0.5);"%(index,index))
      
    output_list.append("}")

    output_list.append("//**Returning Result**")
    #output_list.append("printf(\"temp_total=%f\",temp_total_0);")
    for d in self.derivative: 
      output_list.append("temp_data->thread_result[%d] = temp_total_%d;"%(self.derivative.index(d),self.derivative.index(d)))
      output_list.append("temp_data->thread_result_sqrd[%d] = temp_value_sqrd_%d;"%(self.derivative.index(d),self.derivative.index(d)))
    output_list.append("}")
    
    return output_list
  
  def generate_libraries(self):
    output_list = ["//*Libraries"]
    output_list.append("#define __STDC_FORMAT_MACROS")
    for u in self.utility_libraries: output_list.append("#include \"%s\""%u)
    
    return output_list
 
  def generate_kernel(self,overide=True):
    #Changing to code generation directory
    #os.chdir("..")
    #os.chdir(self.platform.platform_directory())
      
    #Checking that the source code for the derivative and underlying is present
    #for u in self.underlying:
      #if(not(os.path.exists("%s/%s.java"%(self.platform.absolute_platform_directory(),u.name)))): raise IOError, ("missing the source code for the underlying - %s.java" % (u.name))
      #if(not(os.path.exists("%s_parameters.java"%u.name))): raise IOError, ("missing the source code for the underlying parameter set - %s_parameters.java" % (u.name))
    #for d in self.derivative:
      #if(not(os.path.exists("%s/%s.java"%(self.platform.absolute_platform_directory(),d.name)))): raise IOError, ("missing the source code for the derivative - %s.java" %  (d.name))
      #if(not(os.path.exists("%s_parameters.java"%d.name))): raise IOError, ("missing the source code for the derivative parameter set - %s_parameters.java" %  (d.name))
    
    #os.chdir(self.platform.root_directory())
    #os.chdir("bin")
    
    output_list = []
    
    #Package Declaration
    #output_list.append("package mc_solver_maxeler;")
    
    #Maxeler Library Imports
    output_list.append("import com.maxeler.maxcompiler.v2.kernelcompiler.Kernel;")
    output_list.append("import com.maxeler.maxcompiler.v2.kernelcompiler.KernelParameters;")
    #output_list.append("import com.maxeler.maxcompiler.v2.kernelcompiler.stdlib.Accumulator;")
    output_list.append("import com.maxeler.maxcompiler.v2.kernelcompiler.stdlib.KernelMath;")
    #output_list.append("import com.maxeler.maxcompiler.v2.kernelcompiler.stdlib.Reductions;")
    output_list.append("import com.maxeler.maxcompiler.v2.kernelcompiler.stdlib.core.CounterChain;")
    #output_list.append("import com.maxeler.maxcompiler.v2.kernelcompiler.types.base.DFEFix;")
    #output_list.append("import com.maxeler.maxcompiler.v2.kernelcompiler.types.base.DFEFix.SignMode;")
    #output_list.append("import com.maxeler.maxcompiler.v2.kernelcompiler.types.base.DFEFloat;")
    output_list.append("import com.maxeler.maxcompiler.v2.kernelcompiler.types.base.DFEVar;")
    output_list.append("import com.maxeler.maxcompiler.v2.kernelcompiler.types.composite.DFEArray;")
    #output_list.append("import com.maxeler.maxcompiler.v2.kernelcompiler.types.composite.DFEArrayType;")
    
    #Class Declaration
    output_list.append("public class %s_Kernel extends MC_Solver_Maxeler_Base_Kernel {"%self.output_file_name)
    
    #Type Declarations
    output_list.append("//*Type Declarations*\n")
    #output_list.append("dfeFloat inputFloatType = Kernel.hwFloat(8, 24);")
    #output_list.append("dfeFloat inputDoubleType = Kernel.hwFloat(8, 24);")
    #output_list.append("dfeFix accumType = Kernel.hwFix(32,32,SignMode.TWOSCOMPLEMENT);")
    seeds_in = math.ceil(float(len(self.underlying))/2)*4 #Making sure seeds_in is in increments of 128 bits
    #output_list.append("DFEArrayType<DFEVar> inputArrayType = new DFEArrayType<DFEVar>(Kernel.dfeUInt(32),%d);"% (int(seeds_in)))
    values_out = math.ceil(float(len(self.derivative))/2)*4 #Making sure values_out are in increments of 128 bits
    #output_list.append("DFEArrayType<DFEVar> outputArrayType = new DFEArrayType<DFEVar>(inputFloatType,%d);" % values_out)
    
    #Class Constructor Declaration and call to parent class constructor
    output_list.append("//*Kernel Class*\n")
    output_list.append("public %s_Kernel(KernelParameters parameters,int instance_paths,int path_points,int instances,int delay){"%self.output_file_name)
    output_list.append("super(parameters,instance_paths,path_points,instances,delay);")
    
    #Counters
    output_list.append("//**Counters**\n")
    output_list.append("CounterChain chain = control.count.makeCounterChain();")
    
    if(self.c_slow):
      #output_list.append("DFEVar pp = chain.addCounter(this.path_points/%d+%d,1).cast(dfeUInt(32));"%(self.pipelining,self.pipelining)) #Path Points is the outer loop so as to implement a C-Slow architecture
      output_list.append("DFEVar pp = chain.addCounter(this.path_points+1,%d).cast(dfeUInt(32));"%(self.pipelining)) #Path Points is the outer loop so as to implement a C-Slow architecture
      output_list.append("DFEVar p = chain.addCounter(this.instance_paths,1).cast(dfeUInt(32));")
      output_list.append("DFEVar d = p;") #Just make the delay counter equal to the path counter - it functions as the same thing
    else:
      output_list.append("DFEVar p = chain.addCounter(this.instance_paths,1).cast(dfeUInt(32));")
      #output_list.append("DFEVar pp = chain.addCounter(this.path_points/%d+%d-1,1).cast(dfeUInt(32));"%(self.pipelining,self.pipelining))
      output_list.append("DFEVar pp = chain.addCounter(this.path_points+1,%d).cast(dfeUInt(32));"%(self.pipelining)) #Path Points is the outer loop so as to implement a C-Slow architecture
      output_list.append("DFEVar d = chain.addCounter(this.delay,1);")
    
    #Scaler Inputs
    output_list.append("//**Scaler Inputs**\n")
    #output_list.append("//***Underlying Attributes***\n")
    temp_list = []
    for index,u_a in enumerate(sorted(self.underlying_attributes)):
        for a in u_a:
            temp_attribute_name = "%s_%d_%s" % (self.underlying[index].name,index,a)
            temp_list += ["DFEVar %s = (io.scalarInput(\"%s\", inputFloatType));"%(temp_attribute_name,temp_attribute_name)]
        index += 1
    
    #output_list.append("//***Derivative Attributes***")
    for index,o_a in enumerate(sorted(self.derivative_attributes)):
        for a in o_a:
            temp_attribute_name = "%s_%d_%s" % (self.derivative[index].name,index,a)
            temp_list += ["DFEVar %s = (io.scalarInput(\"%s\", inputFloatType));"%(temp_attribute_name,temp_attribute_name)]
    
    output_list += sorted(temp_list)        

    output_list.append("//**Random Seed Input**\n")
    
    input_condition = "pp.eq(0)&d.eq(0)"
    if(self.c_slow): input_condition = "pp.eq(0)"

    for index in range(len(self.underlying)*8):
	output_list.append("DFEVar seeds_in_%d = io.input(\"seeds_in_%d\",Kernel.dfeUInt(32),%s);"%(index,index,input_condition))
 
    for index,d in enumerate(self.derivative): 
	output_list.append("DFEVar accumulate_%d = this.constant.var(this.inputDoubleType,0.0);"%index)
	output_list.append("DFEVar accumulate_sqrd_%d = this.constant.var(this.inputDoubleType,0.0);"%index)
	
	output_list.append("DFEVar delta_time_%d = %s_%d_time_period/this.path_points;"%(index,d.name,index))
	
    output_list.append("//**Parallelism Loop**")
    output_list.append("for (int i=0;i<this.instances;i++){")
    
    output_list.append("//***Underlying and Derivative Declaration(s)***")
    for index,d in enumerate(self.derivative):
      #Creating the parameter object
      temp_string = "%s_parameters %s_%d_parameters = new %s_parameters(this" % (d.name,d.name,index,d.name)
      for d_a in self.derivative_attributes[index][:-1]: temp_string = ("%s,%s_%d_%s"%(temp_string,d.name,index,d_a))
      temp_string = "%s,%s_%d_%s);"%(temp_string,d.name,index,self.derivative_attributes[index][-1])
      
      output_list.append(temp_string)
      
    for index,u in enumerate(self.underlying):
      #Creating the parameter object
      temp_string = "%s_parameters %s_%d_parameters = new %s_parameters(this" % (u.name,u.name,index,u.name)
      for u_a in self.underlying_attributes[index][:-1]: temp_string = ("%s,%s_%d_%s"%(temp_string,u.name,index,u_a))
      temp_string = "%s,%s_%d_%s);"%(temp_string,u.name,index,self.underlying_attributes[index][-1])
      
      output_list.append(temp_string)
    
    temp_path_call_underlying = []
    temp_path_call_derivative = []
    for pipe in range(self.pipelining):
      output_list.append("//***Pipeline Stage %d***"%pipe)
      rng_index = 0
      for index,u in enumerate(self.underlying):
	#If there is a random number generator, this needs to be created and linked to the input seeds
	if("heston" in u.name or "black_scholes" in u.name):
	  #output_list.append("%s_%d_parameters.seed = input_array[%d*2];"%(u.name,index,rng_index))
	  #output_list.append("%s_%d_parameters.seed2 = input_array[%d*2+1];"%(u.name,index,rng_index))
	  
	  cycle_length = "this.instance_paths*(this.path_points+1)*this.delay"
	  if(self.c_slow): cycle_length = "this.instance_paths*(this.path_points+1)"
	  output_list.append("CombinedTauswortheRNG %s_%d_x_%d = new CombinedTauswortheRNG(this,%s,seeds_in_%d,seeds_in_%d+i,seeds_in_%d+i,seeds_in_%d);"%(u.name,index,pipe,cycle_length,index*8,index*8+1,index*8+2,index*8+3))
	  output_list.append("CombinedTauswortheRNG %s_%d_y_%d = new CombinedTauswortheRNG(this,%s,seeds_in_%d,seeds_in_%d+i,seeds_in_%d+i,seeds_in_%d);"%(u.name,index,pipe,cycle_length,index*8+4,index*8+5,index*8+6,index*8+7))
	  
	  output_list.append("%s %s_%d_%d = new %s(this,%s_%d_x_%d,%s_%d_y_%d,pp,p,d,%s_%d_parameters);"%(u.name,u.name,index,pipe,u.name,u.name,index,pipe,u.name,index,pipe,u.name,index))
	  
	
	else: output_list.append("%s %s_%d_%d = new %s(this,pp,p,d,%s_%d_parameters);"%(u.name,u.name,index,pipe,u.name,u.name,index))
	
	output_list.append("%s_%d_%d.path_init();"%(u.name,index,pipe))
	
      for index,d in enumerate(self.derivative):
	
	
	output_list.append("%s %s_%d_%d = new %s(this,pp,p,d,this.constant.var(true),%s_%d_parameters);"%(d.name,d.name,index,pipe,d.name,d.name,index))
	output_list.append("%s_%d_%d.path_init();"%(d.name,index,pipe)) #path initialisation
	#output_list.append("DFEVar delta_time_%d = %s_%d.delta_time;"%(index,d.name,index))
      
      output_list.append("//***Path Initialisation and Path Calls***")
      
      for d_index,d in enumerate(self.derivative):
	for u_index,u in enumerate(d.underlying):
	  if("%s_%d_%d"%(u.name,u_index,pipe) not in temp_path_call_underlying): #checking to see if this path has not been called already
	    #if("points" in self.derivative_attributes[d_index]): output_list.append("%s_%d.path(%s_%d.delta_time);"%(u.name,u_index,d.name,d_index)) #Calling the path function
	    #else: output_list.append("%s_%d.path(%s_%d.delta_time/%d);"%(u.name,u_index,d.name,d_index,self.solver_metadata["path_points"])) #Calling the path function
	    output_list.append("%s_%d_%d.path(delta_time_%d);"%(u.name,u_index,pipe,d_index)) #Calling the path function
	    
	    temp_path_call_underlying.append("%s_%d_%d"%(u.name,u_index,pipe))
      
	    output_list.append("DFEVar temp_price_%d_%d = (%s_%d_%d.parameters.current_price*KernelMath.exp(%s_%d_%d.gamma));"%(u_index,pipe,u.name,u_index,pipe,u.name,u_index,pipe))
	  	  
	  output_list.append("%s_%d_%d.path(temp_price_%d_%d,%s_%d_%d.time);"%(d.name,d_index,pipe,u_index,pipe,u.name,u_index,pipe))
	  
	temp_path_call_derivative.append("%s_%d_%d"%(d.name,d_index,pipe))
	
      
    output_list.append("//***Path Connect Calls***")
    for index,tpc in enumerate(temp_path_call_underlying): #this is fairly dodgy - TODO improve
      if(int(tpc[-1])>0): #connect each point in the pipeline to the value that proceeded it
	output_list.append("%s.connect_path(true,%s%d.new_gamma,%s%d.new_time);"%(tpc,tpc[:-1],int(tpc[-1])-1,tpc[:-1],int(tpc[-1])-1))
	if("heston" in tpc): output_list[-1] = "%s,%s%d.new_volatility);"%(output_list[-1][:-2],tpc[:-1],int(tpc[-1])-1)
      else: #loop back to the end for the first value in the pipeline
	output_list.append("%s.connect_path(false,%s%d.new_gamma,%s%d.new_time);"%(tpc,tpc[:-1],self.pipelining-1,tpc[:-1],self.pipelining-1))
	if("heston" in tpc): output_list[-1] = "%s,%s%d.new_volatility);"%(output_list[-1][:-2],tpc[:-1],self.pipelining-1)	

    for index,tpc in enumerate(temp_path_call_derivative):
      if(int(tpc[-1])>0): #connect each point in the pipeline to the value that proceeded it
	output_list.append("%s.connect_path(true);"%tpc)
	if("asian" in tpc): output_list[-1] = "%s,%s%d.new_average);"%(output_list[-1][:-2],tpc[:-1],int(tpc[-1])-1)
	if("barrier" in tpc): output_list[-1] = "%s,%s%d.new_barrier_event);"%(output_list[-1][:-2],tpc[:-1],int(tpc[-1])-1)
      else: #loop back to the end for the first value in the pipeline
	output_list.append("%s.connect_path(false);"%tpc)
	if("asian" in tpc): output_list[-1] = "%s,%s%d.new_average);"%(output_list[-1][:-2],tpc[:-1],self.pipelining-1)
	if("barrier" in tpc): output_list[-1] = "%s,%s%d.new_barrier_event);"%(output_list[-1][:-2],tpc[:-1],self.pipelining-1)
	    
	 
    output_list.append("//***Path Payoff and Accumulate Calls***") 
    for index,d in enumerate(self.derivative):
      #We're only interested in the payoff for the last path step 
      output_list.append("DFEVar payoff_%d = %s_%d_%d.payoff(temp_price_%d_%d);"%(d_index,d.name,d_index,self.pipelining-1,self.underlying.index(d.underlying[0]),self.pipelining-1))
      #output_list.append("DFEVar loopAccumulate_%d = accum.makeAccumulator(payoff_%d.cast(accumType), ap);"%(d_index,d_index))
      output_list.append("accumulate_%d += payoff_%d;"%(d_index,d_index))
      output_list.append("accumulate_sqrd_%d += payoff_%d*payoff_%d;"%(d_index,d_index,d_index))
    
    output_list.append("}") #End of parallelism loop
    
    output_list.append("//**Copying Outputs to Output array and outputing it**")
    #output_list.append("DFEArray<DFEVar> output_array = outputArrayType.newInstance(this);")
    
    output_condition = "pp.eq(this.path_points-1)&d.eq(0)"
    if(self.c_slow): output_condition = "pp.eq(this.path_points-1)"

    for index,d in enumerate(self.derivative):
      output_list.append("io.output(\"values_out_%d\",(accumulate_%d).cast(this.inputFloatType),this.inputFloatType,%s);"%(index*2,index,output_condition))
      output_list.append("io.output(\"values_out_%d\",(accumulate_sqrd_%d).cast(this.inputFloatType),this.inputFloatType,%s);"%(index*2+1,index,output_condition))
       
    output_list.append("}")
    output_list.append("}")
    
    return output_list
    
  def generate_manager(self):
    output_list = []
    
    #Package Declaration
    #output_list.append("package mc_solver_maxeler;")
    
    #Maxeler Library imports
    output_list.append("import com.maxeler.maxcompiler.v2.managers.engine_interfaces.CPUTypes;")
    output_list.append("import com.maxeler.maxcompiler.v2.managers.engine_interfaces.EngineInterface;")
    output_list.append("import com.maxeler.maxcompiler.v2.managers.engine_interfaces.InterfaceParam;")
    output_list.append("import com.maxeler.maxcompiler.v2.managers.custom.CustomManager;")
    output_list.append("import com.maxeler.maxcompiler.v2.managers.custom.blocks.KernelBlock;")
    output_list.append("import com.maxeler.maxcompiler.v2.build.EngineParameters;")
    output_list.append("import com.maxeler.maxcompiler.v2.kernelcompiler.KernelConfiguration;")  
    output_list.append("import com.maxeler.maxcompiler.v2.managers.custom.ManagerClock;")    
    output_list.append("import com.maxeler.maxcompiler.v2.managers.BuildConfig;")

    #Class declaration
    output_list.append("public class %s_Manager extends CustomManager{"%self.output_file_name)
    
    #Kernel Variable Setting
    output_list.append("private static final int instance_paths = %d;"%self.solver_metadata["instance_paths"])
    output_list.append("private static final int path_points = %d;"%self.solver_metadata["path_points"])
    output_list.append("private static final int instances = %d;"%self.solver_metadata["instances"])
    
    if(self.c_slow): output_list.append("private static int delay = instance_paths;")
    else: output_list.append("private static int delay = %d;"%self.delay)
    
    #Manager Declaration
    output_list.append("%s_Manager(EngineParameters ep){"%self.output_file_name)
    output_list.append("super(ep);")    

    #Optimisation Options
    output_list.append("KernelConfiguration currKConf = getCurrentKernelConfig();")
    output_list.append("currKConf.optimization.setUseGlobalClockBuffer(true);")
    output_list.append("currKConf.optimization.setTriAddsEnabled(true);")
    output_list.append("currKConf.optimization.setDSPMulAddChainBehavior(KernelConfiguration.OptimizationOptions.DSPMulAddChainBehaviour.OPTIMISE);")
    
    #Setting the clock
    clock_rate = 200
    if(self.platform.board!="max3"): clock_rate = 180 
 
    output_list.append("ManagerClock clock = generateStreamClock(\"%s_clock\",%d);"%self.output_file_name,clock_rate)
    output_list.append("pushDefaultClock(clock);")        
    
    #Kernel Declaration and parameter setting
    output_list.append("KernelBlock k = addKernel(new %s_Kernel(makeKernelParameters(\"%s_Kernel\"),instance_paths,path_points,instances,delay));"%(self.output_file_name,self.output_file_name))

    for index,u in enumerate(self.underlying): 
	for k in range(8):
		output_list.append("k.getInput(\"seeds_in_%d\") <== addStreamFromCPU(\"seeds_in_%d\");"%(index*8+k,index*8+k))   
    
    for index,d in enumerate(self.derivative): 
	output_list.append("addStreamToCPU(\"values_out_%d\") <== k.getOutput(\"values_out_%d\");"%(index*2,index*2))
	output_list.append("addStreamToCPU(\"values_out_%d\") <== k.getOutput(\"values_out_%d\");"%(index*2+1,index*2+1))
    
    """
    output_list.append("m.addMaxFileConstant(\"instance_paths\", instance_paths);")
    output_list.append("m.addMaxFileConstant(\"path_points\", path_points);")
    output_list.append("m.addMaxFileConstant(\"instances\", instances);")
    output_list.append("m.addMaxFileConstant(\"delay\", delay);")
    """

    #Build Configuration
    output_list.append("BuildConfig c = new BuildConfig(BuildConfig.Level.FULL_BUILD);")
    output_list.append("c.setBuildEffort(BuildConfig.Effort.HIGH);")  #LOW,MEDIUM,HIGH,VERY_HIGH
    output_list.append("c.setEnableTimingAnalysis(true);")
    output_list.append("c.setMPPRCostTableSearchRange(1,100);")
    threads = int(math.ceil(multiprocessing.cpu_count()))
    if(threads>6): threads = 6
    output_list.append("c.setMPPRParallelism(%d);"%threads) #This has to be done carefully, as it takes a *lot* of RAM
    output_list.append("setBuildConfig(c);")
    #output_list.append("m.build();")
    output_list.append("}")#Closing off Manager decleration

    #Interface Decleration
    output_list.append("private static EngineInterface interfaceDefault(){") 
    output_list.append("EngineInterface engine_interface = new EngineInterface();")
    
    output_list.append("CPUTypes inType = CPUTypes.UINT32;")
    output_list.append("int inSize = inType.sizeInBytes();")
    output_list.append("CPUTypes outType = CPUTypes.FLOAT;")
    output_list.append("int outSize = outType.sizeInBytes();") 

    #output_list.append("InterfaceParam inN = engine_interface.addParam(\"N\", CPUTypes.INT);")
    #output_list.append("InterfaceParam inSizeBytes = instance_paths * inSize;")
    #output_list.append("InterfaceParam outSizeBytes = instance_paths * outSize;")

    if(self.c_slow):
    	output_list.append("engine_interface.setTicks(\"%s_Kernel\",instance_paths*(path_points+1));"%self.output_file_name)
    else:
    	output_list.append("engine_interface.setTicks(\"%s_Kernel\",instance_paths*(path_points/%d+1)*delay);"%self.output_file_name)
    
    for index,u in enumerate(self.underlying): 
	for k in range(8): output_list.append("engine_interface.setStream(\"seeds_in_%d\", inType, inSize*instance_paths);"%(index*8+k))
    for index,d in enumerate(self.derivative): 
    	output_list.append("engine_interface.setStream(\"values_out_%d\", outType, outSize*instance_paths);"%(index*2))
    	output_list.append("engine_interface.setStream(\"values_out_%d\", outType, outSize*instance_paths);"%(index*2+1))
    output_list.append("return engine_interface;")
    
    output_list.append("}")

    #main
    output_list.append("public static void main(String[] args){")
    output_list.append("%s_Manager manager = new %s_Manager(new EngineParameters(args));"%(self.output_file_name,self.output_file_name))
    output_list.append("manager.createSLiCinterface(interfaceDefault());")
    output_list.append("manager.build();")
    output_list.append("}")
    

    output_list.append("}")#Closing off Class decleration
    
    return output_list
   
  def compile(self,override=True,cleanup=True,debug=True):
    
    if(override):
      #Hardware Build Process
      compile_cmd = ["make","-C","%s/../build"%self.platform.absolute_platform_directory(),"build","APP=%s"%self.output_file_name]
      if(self.platform.board!="max3"): compile_cmd += ["MAX3=false"]  
    
      compile_string = ""
      for c_c in compile_cmd: compile_string += " %s"%c_c
      if(debug): print compile_string
      
      hw_result = subprocess.check_output(compile_cmd)
      #hw_result = []   

      #subprocess.check_output(["rm -r ../../scratch/*"]) #cleaning up majority of HDL source code generated for synthesis
      #print hw_result
      
      #Host Code Compile
      sw_result = []
      """
      compile_cmd = ["make","-C",self.platform.absolute_platform_directory(),"app-hw","APP=%s"%self.output_file_name]
      
      compile_string = ""
      for c_c in compile_cmd: compile_string += " %s"%(c_c)
      if(debug): print compile_string
      
      try: sw_result = subprocess.check_output(compile_cmd)
      except: pass
      #print sw_result
      """
      #os.chdir(self.platform.root_directory())
      #os.chdir("bin")
      
      return hw_result
       
  #def execute(self,cleanup=False,debug=False):
  """
    try:
      os.chdir("..")
      os.chdir(self.platform.platform_directory())
      
    except:
      os.chdir("bin")
      return "Maxeler Code directory doesn't exist!"
    """
  
  """
    run_cmd = ["%s/%sRun"%(self.platform.absolute_platform_directory(),self.output_file_name)]
    for k in sorted(self.solver_metadata): run_cmd += [str(self.solver_metadata[k])]
    
    for index,u_a in enumerate(self.underlying_attributes):
        for a in u_a: run_cmd.append(str(self.underlying[index].__dict__[a])) #mirrors generation code to preserve order of variable loading
    
    for index,o_a in enumerate(self.derivative_attributes): 
        for a in o_a: run_cmd.append(str(self.derivative[index].__dict__[a]))
    
    run_string = ""
    for r_c in run_cmd: run_string += " %s"%(r_c)
    if(debug): print run_string
    
    start = time.time() #Wall-time is measured by framework, not the generated application to measure overhead in calling code
    results = subprocess.check_output(run_cmd)
    finish = time.time()
    
    results = results.split("\n")[:-1]
    results.append((finish-start)*1000000)
    
    #os.chdir(self.platform.root_directory())
    #os.chdir("bin")
    
    if(cleanup): self.cleanup()
    
    return results
    """
  
  def trial_run(self,paths,steps,redudancy=10,paths_start=0,stepping="linear"):
      accuracy = []
      latency = []
      accuracy_var = []
      latency_var = []

      path_set = numpy.arange(max(paths_start,paths),max(paths_start,paths)+paths*steps,paths)
      if(stepping=="power"):
	multiplier = (steps)**(1.0/(steps))
	path_set = paths*(multiplier**numpy.arange(1,steps+1))
    
      for p in path_set: #Trial Runs to generate data needed for predicition functions
	self.solver_metadata["paths"] = p
	temp_latency = []
	temp_error = []
	for i in range(redudancy):
	  self.dummy_run()
	  execution_output = self.execute()#solver.execute()
	  
	  #latency.append((float(execution_output[-1])-float(execution_output[-2]),float(execution_output[-2]))) #(setup_time,activity_time)
	  temp_latency.append(float(execution_output[-1]))
	  
	  value = 0.0
	  temp_temp_error = []
	  for i,e_o in enumerate(execution_output[:-3]):
	    if(not i%2): value = float(e_o) + 0.00000000000001
	    else: temp_temp_error.append(float(e_o)) #temp_error.append(float(e_o)/value*100) #percentage relative error
	    
	  #print execution_output[:-3]
	  temp_error.append(max(temp_temp_error))
	
	#print p
	#print temp_error
	#print temp_latency
	#print numpy.mean(temp_error)
	#print "\n"
	accuracy.append(numpy.mean(temp_error))
	accuracy_var.append(numpy.var(temp_error))
	latency.append(numpy.mean(temp_latency))
	latency_var.append(numpy.var(temp_latency))

      return [accuracy,latency,accuracy_var,latency_var,path_set]
    
  def dummy_run(self):
      rfir = 0.1
      current_price = 100
      time_period = 1.0
      call = 1.0
      strike_price = 100
      paths = 1000
      
      underlying = [Underlying.Underlying(rfir,current_price)]
      option = [Option.Option(underlying,time_period,call,strike_price)]
      #platform = MaxelerFPGA.MaxelerFPGA(remote=self.platform.remote,ssh_alias=self.platform.ssh_alias)
      
      delay = self.solver_metadata["delay"]
      mc_solver = MaxelerFPGA_MonteCarlo(option,paths,self.platform,instances=1) #because we can do recursive calls like this
      #mc_solver.generate()
      #compile_output = mc_solver.compile() #assume this has been done already
      
      #delay = 25
      mc_solver.execute()
      self.solver_metadata["delay"] = delay
      
  def get_delay(self):
    delay = 13*self.pipelining 
    
    for d in self.derivative:
      for u in d.underlying:
	if("black_scholes" in u.name): delay = 25*self.pipelining
	if("heston" in u.name): delay = 176*self.pipelining
	
    return delay
