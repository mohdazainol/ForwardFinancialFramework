'''
Created on 30 October 2012

'''
import os,time,subprocess,sys,time,math,multiprocessing,numpy
from ForwardFinancialFramework.Platforms.MulticoreCPU import MulticoreCPU_MonteCarlo
from ForwardFinancialFramework.Underlyings import Underlying
from ForwardFinancialFramework.Derivatives import Option
import MaxelerFPGA

class MaxelerFPGA_MonteCarlo(MulticoreCPU_MonteCarlo.MulticoreCPU_MonteCarlo):
  def __init__(self,derivative,paths,platform,points=4096,reduce_underlyings=True):
    MulticoreCPU_MonteCarlo.MulticoreCPU_MonteCarlo.__init__(self,derivative,paths,platform,reduce_underlyings)
    
    self.solver_metadata["instances"] = self.platform.instances #Number of instances set by the platform
    self.solver_metadata["instance_paths"] = 10000 #setting the number of paths per instance
    self.solver_metadata["path_points"] = points
    self.iterations = int(self.solver_metadata["paths"]/self.solver_metadata["instance_paths"]) #calculating the number of iterations required of the kernel
    
    self.utility_libraries = ["stdio.h","stdlib.h","stdint.h","pthread.h","MaxCompilerRT.h","sys/time.h","sys/resource.h","mersenne_twister_seeding.h"]
    
    self.activity_thread_name = "maxeler_montecarlo_activity_thread"
    self.floating_point_format = "float"
  
  def generate_identifier(self): return ["//%s.c Generated by Monte Carlo Maxeler Solver"%self.output_file_name]
  
  def generate(self,override=True):
    #Generate C Host Code largely using Multicore infrastructure
    MulticoreCPU_MonteCarlo.MulticoreCPU_MonteCarlo.generate(self,"_Host_Code.c",override,verbose=False)
    
    #Generate Maxeler Kernel Code
    kernel_code_string = self.generate_kernel()
    self.generate_source(kernel_code_string,"_Kernel.java")
    
    #Generate Maxeler HW Builder Code
    hw_builder_code_string = self.generate_hw_builder()
    self.generate_source(hw_builder_code_string,"_HW_Builder.java")
    
    #Generate Maxeler Makefile
    #self.generate_makefile()
  
  def generate_activity_thread(self):
    output_list = []

    output_list.append("//*MC Maxeler Activity Thread Function*")
    output_list.append("void * %s(void* thread_arg){"%self.activity_thread_name)
    output_list.append("struct thread_data* temp_data;")
    output_list.append("temp_data = (struct thread_data*) thread_arg;")
    output_list.append("//**Creating Maxeler Variables, opening and configuring the FPGA**")
    output_list.append("char *device_name = \"/dev/maxeler0\";") #TODO
    output_list.append("max_maxfile_t* maxfile;")
    output_list.append("max_device_handle_t* device;")
    output_list.append("maxfile = max_maxfile_init_%s();"%self.output_file_name)
    output_list.append("device = max_open_device(maxfile, device_name);")
    output_list.append("max_set_terminate_on_error(device);")
    
    output_list.append("//**Creating kernel IO variables**")
    output_list.append("uint32_t *seeds_in;")
    output_list.append("long *temp_seeds,*temp_seeds2;")
    output_list.append("float *values_out;")
    
    seeds_in = math.ceil(float(len(self.underlying))/2) #Making sure seeds in is in increments of 128 bits (groups of 4 x 32 bit variables)
    values_out = math.ceil(float(len(self.derivative))/2) #Making sure values are in increments of 128 bits

    output_list.append("seeds_in = malloc(%d*instance_paths*sizeof(uint32_t));"%(int(seeds_in*4)))
    output_list.append("values_out = malloc(%d*instance_paths*sizeof(float));"%(int(values_out*4)))
    #output_list.append("posix_memalign(&seeds_in,%d,sizeof(uint32_t)*%d);"%(seeds_in*4,self.iterations*seeds_in*4))
    #output_list.append("posix_memalign(&values_out,%d,sizeof(float)*%d);"%(values_out*4,self.iterations*values_out*4))
    
    for d in range(len(self.derivative)): 
      output_list.append("double temp_total_%d=0;"%d)
      output_list.append("double temp_value_sqrd_%d=0;"%d)
    
    output_list.append("//**Generating initial random seed**")
    output_list.append("uint32_t initial_seed;") #%%((uint32_t)pow(2,31)-%d);"%(seeds_in*self.iterations)) #Start the seeds off at some random point
    output_list.append("srand48(start.tv_nsec);")
    
    output_list.append("int loops = ceil(paths/instance_paths/instances);");
    output_list.append("if(loops==0) loops = 1;")
    output_list.append("for (i=0;i < loops;++i){")
    
    output_list.append("//**Populating Seed Array(s)**")
    for index,u in enumerate(self.underlying):
    	output_list.append("initial_seed = (uint32_t)(drand48()*pow(2,32));");
    	output_list.append("temp_seeds = getSeeds(initial_seed);")
    	output_list.append("for (j=0;j<(624);++j) seeds_in[j*%d + %d*2] = ((uint32_t) temp_seeds[j]);"%(seeds_in*4,index))
	output_list.append("initial_seed = (uint32_t)(drand48()*pow(2,32));");
    	output_list.append("temp_seeds2 = getSeeds(initial_seed);")
	output_list.append("for (j=0;j<(624);++j) seeds_in[j*%d + %d*2 +1] = ((uint32_t) temp_seeds2[j]);"%(seeds_in*4,index))
    
    output_list.append("//**Streaming data to/from FPGA**")
    output_list.append("//***Setting Scaler(Parameters) Values***")
    output_list.append("//****Underlying Attributes****")
    index = 0
    for u_a in self.underlying_attributes:
        for a in u_a:
            attribute = "%s_%d_%s" % (self.underlying[index].name,index,a)
            output_list.append("max_set_scalar_input_f(device,\"%s_Kernel.%s\",%s,FPGA_A);"%(self.output_file_name,attribute,attribute))
        index += 1
    
    output_list.append("//****Derivative Attributes****")
    index = 0
    for o_a in self.derivative_attributes:
        for a in o_a:
            attribute = "%s_%d_%s" % (self.derivative[index].name,index,a)
            output_list.append("max_set_scalar_input_f(device,\"%s_Kernel.%s\",%s,FPGA_A);"%(self.output_file_name,attribute,attribute))
        index += 1
        
    output_list.append("//***Streaming IO Data to FPGA and Running Kernel***")
    output_list.append("max_run(device,")
    output_list.append("max_input(\"seeds_in\",seeds_in, %d*instance_paths*sizeof(uint32_t)),"%(4*seeds_in))
    output_list.append("max_output(\"values_out\", values_out, %d*instance_paths*sizeof(float)),"%(4*values_out))
    output_list.append("max_runfor(\"%s_Kernel\",instance_paths*(path_points+1)),"%(self.output_file_name))
    output_list.append("max_end());")
    
    output_list.append("//**Post-Kernel Aggregation**")
    output_list.append("for (j=0;(j<(instance_paths*%d))&&((j<paths*%d));j = j + %d){"%(values_out*4,values_out*4,values_out*4))
    for index,d in enumerate(self.derivative):
      output_list.append("temp_total_%d += values_out[j+2*%d];"%(index,index))
      output_list.append("temp_value_sqrd_%d += values_out[j+2*%d+1];"%(index,index))
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
    os.chdir("..")
    os.chdir(self.platform.platform_directory())
      
    #Checking that the source code for the derivative and underlying is present
    for u in self.underlying:
      if(not(os.path.exists("%s.java"%u.name))): raise IOError, ("missing the source code for the underlying - %s.java" % (u.name))
      #if(not(os.path.exists("%s_parameters.java"%u.name))): raise IOError, ("missing the source code for the underlying parameter set - %s_parameters.java" % (u.name))
    for d in self.derivative:
      if(not(os.path.exists("%s.java"%d.name))): raise IOError, ("missing the source code for the derivative - %s.java" %  (d.name))
      #if(not(os.path.exists("%s_parameters.java"%d.name))): raise IOError, ("missing the source code for the derivative parameter set - %s_parameters.java" %  (d.name))
    
    os.chdir(self.platform.root_directory())
    os.chdir("bin")
    
    output_list = []
    
    #Package Declaration
    output_list.append("package mc_solver_maxeler;")
    
    #Maxeler Library Imports
    output_list.append("import com.maxeler.maxcompiler.v2.kernelcompiler.Kernel;")
    output_list.append("import com.maxeler.maxcompiler.v2.kernelcompiler.KernelParameters;")
    output_list.append("import com.maxeler.maxcompiler.v2.kernelcompiler.stdlib.Accumulator;")
    output_list.append("import com.maxeler.maxcompiler.v2.kernelcompiler.stdlib.KernelMath;")
    output_list.append("import com.maxeler.maxcompiler.v2.kernelcompiler.stdlib.Reductions;")
    output_list.append("import com.maxeler.maxcompiler.v2.kernelcompiler.stdlib.core.CounterChain;")
    output_list.append("import com.maxeler.maxcompiler.v2.kernelcompiler.types.base.DFEFix;")
    output_list.append("import com.maxeler.maxcompiler.v2.kernelcompiler.types.base.DFEFix.SignMode;")
    output_list.append("import com.maxeler.maxcompiler.v2.kernelcompiler.types.base.DFEFloat;")
    output_list.append("import com.maxeler.maxcompiler.v2.kernelcompiler.types.base.DFEVar;")
    output_list.append("import com.maxeler.maxcompiler.v2.kernelcompiler.types.composite.DFEArray;")
    output_list.append("import com.maxeler.maxcompiler.v2.kernelcompiler.types.composite.DFEArrayType;")
    
    #Class Declaration
    output_list.append("public class %s_Kernel extends MC_Solver_Maxeler_Base_Kernel {"%self.output_file_name)
    
    #Type Declarations
    output_list.append("//*Type Declarations*\n")
    #output_list.append("dfeFloat inputFloatType = Kernel.hwFloat(8, 24);")
    #output_list.append("dfeFloat inputDoubleType = Kernel.hwFloat(8, 24);")
    #output_list.append("dfeFix accumType = Kernel.hwFix(32,32,SignMode.TWOSCOMPLEMENT);")
    seeds_in = math.ceil(float(len(self.underlying))/2)*4 #Making sure seeds_in is in increments of 128 bits
    output_list.append("DFEArrayType<DFEVar> inputArrayType = new DFEArrayType<DFEVar>(Kernel.dfeUInt(32),%d);"% (int(seeds_in)))
    values_out = math.ceil(float(len(self.derivative))/2)*4 #Making sure values_out are in increments of 128 bits
    output_list.append("DFEArrayType<DFEVar> outputArrayType = new DFEArrayType<DFEVar>(inputFloatType,%d);" % values_out)
    
    #Class Constructor Declaration and call to parent class constructor
    output_list.append("//*Kernel Class*\n")
    output_list.append("public %s_Kernel(KernelParameters parameters,int instance_paths,int path_points,int instances){"%self.output_file_name)
    output_list.append("super(parameters,instance_paths,path_points,instances);")
    
    #Counters
    output_list.append("//**Counters**\n")
    output_list.append("CounterChain chain = control.count.makeCounterChain();")
    output_list.append("DFEVar pp = chain.addCounter(this.path_points+1,1);") #Path Points is the outer loop so as to implement a C-Slow architecture
    output_list.append("DFEVar p = chain.addCounter(this.instance_paths,1);")
    
    #Scaler Inputs
    output_list.append("//**Scaler Inputs**\n")
    output_list.append("//***Underlying Attributes***\n")
    for index,u_a in enumerate(self.underlying_attributes):
        for a in u_a:
            temp_attribute_name = "%s_%d_%s" % (self.underlying[index].name,index,a)
            output_list.append("DFEVar %s = (io.scalarInput(\"%s\", inputFloatType));"%(temp_attribute_name,temp_attribute_name))
        index += 1
    
    output_list.append("//***Derivative Attributes***")
    for index,o_a in enumerate(self.derivative_attributes):
        for a in o_a:
            temp_attribute_name = "%s_%d_%s" % (self.derivative[index].name,index,a)
            output_list.append("DFEVar %s = (io.scalarInput(\"%s\", inputFloatType));"%(temp_attribute_name,temp_attribute_name))
        
    output_list.append("//**Random Seed Input**\n")
    output_list.append("DFEArray<DFEVar> input_array = io.input(\"seeds_in\",inputArrayType,(pp.eq(0)));")
    #for index,u in enumerate(self.underlying):
      #output_list.append("DFEVar seeds_in_%d = input_array[%d];"% (index,index))
    
    for index,d in enumerate(self.derivative): 
	output_list.append("DFEVar accumulate_%d = this.constant.var(this.inputDoubleType,0.0);"%index)
	output_list.append("DFEVar accumulate_sqrd_%d = this.constant.var(this.inputDoubleType,0.0);"%index)
    output_list.append("//**Parallelism Loop**")
    output_list.append("for (int i=0;i<this.instances;i++){")
    
    output_list.append("//***Underlying Declaration(s)***")
    rng_index = 0
    for index,u in enumerate(self.underlying):
      
      #Creating the parameter object
      temp_string = "%s_parameters %s_%d_parameters = new %s_parameters(this" % (u.name,u.name,index,u.name)
      for u_a in self.underlying_attributes[index][:-1]: temp_string = ("%s,%s_%d_%s"%(temp_string,u.name,index,u_a))
      temp_string = "%s,%s_%d_%s);"%(temp_string,u.name,index,self.underlying_attributes[index][-1])
      
      output_list.append(temp_string)
      output_list.append("%s %s_%d = new %s(this,pp,p,%s_%d_parameters);"%(u.name,u.name,index,u.name,u.name,index))
      if("heston" in u.name or "black_scholes" in u.name):
	output_list.append("%s_%d_parameters.seed = input_array[%d*2];"%(u.name,index,rng_index))
	output_list.append("%s_%d_parameters.seed2 = input_array[%d*2+1];"%(u.name,index,rng_index))
	rng_index += 1
      output_list.append("%s_%d.path_init();"%(u.name,index))
      
    output_list.append("//***Derivative Declaration(s)***")
    for index,d in enumerate(self.derivative):
      
      #Creating the parameter object
      temp_string = "%s_parameters %s_%d_parameters = new %s_parameters(this" % (d.name,d.name,index,d.name)
      for d_a in self.derivative_attributes[index][:-1]: temp_string = ("%s,%s_%d_%s"%(temp_string,d.name,index,d_a))
      temp_string = "%s,%s_%d_%s);"%(temp_string,d.name,index,self.derivative_attributes[index][-1])
      
      output_list.append(temp_string)
      output_list.append("%s %s_%d = new %s(this,pp,p,this.constant.var(true),%s_%d_parameters);"%(d.name,d.name,index,d.name,d.name,index))
      output_list.append("%s_%d.path_init();"%(d.name,index)) #path initialisation
      #output_list.append("DFEVar delta_time_%d = %s_%d.delta_time;"%(index,d.name,index))
      
    output_list.append("//***Path Initialisation, Path, Payoff Calls and Accumulation***")
    
    temp_path_call = []
    for d in self.derivative:
      d_index = self.derivative.index(d)
      for u in d.underlying:
        u_index = self.underlying.index(u)
        if("%s_%d"%(u.name,u_index) not in temp_path_call): #checking to see if this path has not been called already
          if("points" in self.derivative_attributes[d_index]): output_list.append("%s_%d.path(%s_%d.delta_time);"%(u.name,u_index,d.name,d_index)) #Calling the path function
	  else: output_list.append("%s_%d.path(%s_%d.delta_time/%d);"%(u.name,u_index,d.name,d_index,self.solver_metadata["path_points"])) #Calling the path function
          output_list.append("%s_%d.connect_path();"%(u.name,u_index))
          temp_path_call.append("%s_%d"%(u.name,u_index))
    
          output_list.append("DFEVar temp_price_%d = (%s_%d.parameters.current_price*KernelMath.exp(%s_%d.gamma));"%(u_index,u.name,u_index,u.name,u_index))
        
        output_list.append("%s_%d.path(temp_price_%d,%s_%d.time);"%(d.name,d_index,u_index,u.name,u_index))
        output_list.append("%s_%d.connect_path();"%(d.name,d_index))
        output_list.append("DFEVar payoff_%d = %s_%d.payoff(temp_price_%d);"%(d_index,d.name,d_index,u_index))
        #output_list.append("DFEVar loopAccumulate_%d = accum.makeAccumulator(payoff_%d.cast(accumType), ap);"%(d_index,d_index))
        output_list.append("accumulate_%d += payoff_%d;"%(d_index,d_index))
	output_list.append("accumulate_sqrd_%d += payoff_%d*payoff_%d;"%(d_index,d_index,d_index))
    
    output_list.append("}") #End of parallelism loop
    
    output_list.append("//**Copying Outputs to Output array and outputing it**")
    output_list.append("DFEArray<DFEVar> output_array = outputArrayType.newInstance(this);")
    for index,d in enumerate(self.derivative):
      output_list.append("output_array[%d] <== (accumulate_%d).cast(inputFloatType);"%(index*2,index))
      output_list.append("output_array[%d] <== (accumulate_sqrd_%d).cast(inputFloatType);"%(index*2+1,index))
      
    for i in range(len(self.derivative)*2,int(values_out)): output_list.append("output_array[%d] <== this.constant.var(inputFloatType,0.0);"%i)
    
    #output_list.append("io.output(\"values_out\", output_array ,outputArrayType,p.eq(this.instance_paths-1)&pp.eq(this.path_points-1));")
    output_list.append("io.output(\"values_out\", output_array ,outputArrayType,pp.eq(this.path_points));")
    output_list.append("}")
    output_list.append("}")
    
    return output_list
    
  def generate_hw_builder(self):
    output_list = []
    
    #Package Declaration
    output_list.append("package mc_solver_maxeler;")
    
    #Maxeler Library imports
    output_list.append("import static config.BoardModel.BOARDMODEL;")
    output_list.append("import com.maxeler.maxcompiler.v2.kernelcompiler.Kernel;")
    output_list.append("import com.maxeler.maxcompiler.v2.managers.BuildConfig;")
    output_list.append("import com.maxeler.maxcompiler.v2.managers.standard.Manager;")
    output_list.append("import com.maxeler.maxcompiler.v2.managers.standard.Manager.IOType;")
    
    #Class declaration
    output_list.append("public class %s_HW_Builder {"%self.output_file_name)
    
    #Kernel Variable Setting
    output_list.append("private static int instance_paths = %d;"%self.solver_metadata["instance_paths"])
    output_list.append("private static int path_points = %d;"%self.solver_metadata["path_points"])
    output_list.append("private static int instances = %d;"%self.solver_metadata["instances"])
    
    #Main Method
    output_list.append("public static void main(String[] args) {")
    #Manager Declaration
    output_list.append("Manager m = new Manager(\"%s\", BOARDMODEL);"%self.output_file_name)
    #Kernel Declaration and parameter setting
    output_list.append("Kernel k = new %s_Kernel(m.makeKernelParameters(\"%s_Kernel\"),instance_paths,path_points,instances);"%(self.output_file_name,self.output_file_name))
    output_list.append("m.setKernel(k);")
    output_list.append("m.setIO(IOType.ALL_PCIE);")
    output_list.append("m.addMaxFileConstant(\"instance_paths\", instance_paths);")
    output_list.append("m.addMaxFileConstant(\"path_points\", path_points);")
    output_list.append("m.addMaxFileConstant(\"instances\", instances);")
    output_list.append("m.setClockFrequency(150);")
    #Build Configuration
    output_list.append("BuildConfig c = new BuildConfig(BuildConfig.Level.FULL_BUILD);")
    output_list.append("c.setBuildEffort(BuildConfig.Effort.MEDIUM);")  #LOW,MEDIUM,HIGH,VERY_HIGH
    output_list.append("c.setEnableTimingAnalysis(true);")
    output_list.append("c.setMPPRCostTableSearchRange(1,100);")
    threads = int(math.ceil(multiprocessing.cpu_count()))
    if(threads>5): threads = 5
    output_list.append("c.setMPPRParallelism(%d);"%threads) #This has to be done carefully, as it takes a *lot* of RAM
    output_list.append("m.setBuildConfig(c);")
    output_list.append("m.build();")
    output_list.append("}")#Closing off Main Method
    output_list.append("}")#Closing off Class decleration
    
    return output_list
  
  def generate_makefile(self):
    os.chdir("..")
    os.chdir(self.platform.platform_directory())
    
    makefile = open("Makefile","w")
    makefile.write("BASEDIR=../..\n")
    makefile.write("PACKAGE=mc_solver_maxeler\n")
    makefile.write("APP=dummy\n")#%self.output_file_name)
    makefile.write("HWMAXFILE=$(APP).max\n")
    #makefile.write("HOSTSIMMAXFILE=$(APP)_Host_Sim.max")
    makefile.write("HWBUILDER=$(APP)_HW_Builder.java\n")
    #makefile.write("HOSTSIMBUILDER=$(APP)_Host_Sim_Builder.java")
    #makefile.write("SIMRUNNER=$(APP)_Sim_Runner.java")
    makefile.write("HOSTCODE=$(APP)_Host_Code.c\n")
    makefile.write("KERNELCODE=$(APP)_Kernel.java\n")
    makefile.write("CFLAGS+=-DFP_t=%s\n\n"%self.floating_point_format)
    
    """makefile.write("nullstring :=\n")
    makefile.write("space := $(nullstring)\n")
    makefile.write("MAXCOMPILERDIR_QUOTE:=$(subst $(space),\ ,$(MAXCOMPILERDIR))\n")
    makefile.write("include $(MAXCOMPILERDIR_QUOTE)/lib/Makefile.include\n")
    makefile.write("ifndef MAXCOMPILERDIR\n")
    makefile.write("\t$(error MAXCOMPILERDIR environment variable is not set)\n")
    makefile.write("endif\n")
    makefile.write("nullstring :=\n")
    makefile.write("space := $(nullstring) # a space at the end\n")
    makefile.write("MAXCOMPILERDIR_QUOTE:=$(subst $(space),\\ ,$(MAXCOMPILERDIR))\n")"""
    makefile.write("include $(MAXCOMPILERDIR)/lib/Makefile.include\n")
    makefile.write("include $(MAXCOMPILERDIR)/examples/common/Makefile.include\n")
    #makefile.write("include $(MAXCOMPILERDIR_QUOTE)/examples/common/Makefile.include\n")
    makefile.close()
    
    os.chdir(self.platform.root_directory())
    os.chdir("bin")
    
  def compile(self,override=True,cleanup=True,debug=True):
    try:
      os.chdir("..")
      os.chdir(self.platform.platform_directory())
      
    except:
      os.chdir("bin")
      return "Maxeler Code directory doesn't exist!"
    
    if(override or not os.path.exists("hardware/%s/"%self.output_file_name)):
      #Hardware Build Process
      compile_cmd = ["make","build-hw","APP=%s"%self.output_file_name]
      
      compile_string = ""
      for c_c in compile_cmd: compile_string = "%s %s"%(compile_string,c_c)
      if(debug): print compile_string
      
      hw_result = subprocess.check_output(compile_cmd)
   
      #subprocess.check_output(["rm -r ../../scratch/*"]) #cleaning up majority of HDL source code generated for synthesis
      #print hw_result
      
      #Host Code Compile
      #compile_cmd = ["FP_t=%s"%self.floating_point_format, "make","app-hw","APP=%s"%self.output_file_name]
      compile_cmd = ["make","app-hw","APP=%s"%self.output_file_name]
      
      compile_string = ""
      for c_c in compile_cmd: compile_string = "%s %s"%(compile_string,c_c)
      if(debug): print compile_string
      
      sw_result = subprocess.check_output(compile_cmd)
      #print sw_result
      
      os.chdir(self.platform.root_directory())
      os.chdir("bin")
      
      return (hw_result,sw_result)
      
  
  """def populate_model(self,base_trial_paths,trial_steps):
      derivative_backup = self.derivative[:]
      underlying_backup = self.underlying[:]
      
      for d in derivative_backup:
	self.derivative = [d]
	self.setup_underlyings(True)
	self.generate()
	#self.compile()
	
	trial_run_results = self.trial_run(base_trial_paths,trial_steps,self)
	accuracy = trial_run_results[0]
	latency = trial_run_results[1]
	
	latency_coefficients = self.generate_latency_prediction_function_coefficients(base_trial_paths,trial_steps,latency)
	accuracy_coefficients = self.generate_accuracy_prediction_function_coefficients(base_trial_paths,trial_steps,accuracy)
	
	d.latency_model_coefficients.extend(latency_coefficients)
	d.accuracy_model_coefficients.extend(accuracy_coefficients)
	
      if(len(derivative_backup)>len(underlying_backup)): #Checking to see if there are any shared underlyings
	for u in underlying_backup:
	    temp_derivatives = []
	    for d in derivative_backup:
		if(d.underlying[0]==u):
		  temp_derivatives.append(d)
		    
	    if(len(temp_derivatives)>1): #If there are derivatives that share underlyings
		for i in range(2**len(temp_derivatives)):
		    count = 0
		    for b in bin(i)[2:]:
			if(b=="1"): count = count+1
			
		    derivatives=[]
		    if(count>1):
			#for index in range(count): derivatives.append(temp_derivatives[index]) #Get those underlyings together
			self.derivative = temp_derivatives
			self.setup_underlyings(True)
			self.generate()
			#self.compile()
			
			trial_run_results = self.trial_run(base_trial_paths,trial_steps,self) #Run the trial for that grouping of underlyings
			accuracy = trial_run_results[0]
			latency = trial_run_results[1]
	
			latency_coefficients = self.generate_latency_prediction_function_coefficients(base_trial_paths,trial_steps,latency)
			accuracy_coefficients = self.generate_accuracy_prediction_function_coefficients(base_trial_paths,trial_steps,accuracy)
	
			name = "%s"%temp_derivatives[0].name[:2]
			for t_d in temp_derivatives[1:]: name = "%s_%s"%(name,t_d.name[:2])
	
			u.latency_model_coefficients["%s"%name] = latency_coefficients
			u.accuracy_model_coefficients["%s"%name] = accuracy_coefficients
		    
	    
    
      self.derivative = derivative_backup
      self.underlying = underlying_backup
      
      self.latency_model = self.generate_aggregate_latency_model()
      self.accuracy_model = self.generate_aggregate_accuracy_model()"""
      
  """def populate_model(self,base_trial_paths,trial_steps):
      derivative_backup = self.derivative[:]
      underlying_backup = self.underlying[:]
      
      for d in derivative_backup:
	self.derivative = [d]
	self.setup_underlyings(True)
	self.generate()
	#self.compile() #assumes that compilation has already been done
	
	trial_run_results = self.trial_run(base_trial_paths,trial_steps,self)
	accuracy = trial_run_results[0]
	latency = trial_run_results[1]
	
	latency_coefficients = self.generate_latency_prediction_function_coefficients(base_trial_paths,trial_steps,latency)
	accuracy_coefficients = self.generate_accuracy_prediction_function_coefficients(base_trial_paths,trial_steps,accuracy)
	
	d.latency_model_coefficients.extend(latency_coefficients)
	d.accuracy_model_coefficients.extend(accuracy_coefficients)
    
      self.derivative = derivative_backup
      self.underlying = underlying_backup
      
      self.latency_model = self.generate_aggregate_latency_model()
      self.accuracy_model = self.generate_aggregate_accuracy_model()"""
  
  def execute(self,cleanup=False,debug=False):
    try:
      os.chdir("..")
      os.chdir(self.platform.platform_directory())
      
    except:
      os.chdir("bin")
      return "Maxeler Code directory doesn't exist!"
    
    run_cmd = ["./%sRun"%self.output_file_name]
    for k in self.solver_metadata.keys(): run_cmd.append(str(self.solver_metadata[k]))
    
    index = 0
    for u_a in self.underlying_attributes:
        for a in u_a: run_cmd.append(str(self.underlying[index].__dict__[a])) #mirrors generation code to preserve order of variable loading
        index += 1
    
    index = 0
    for o_a in self.derivative_attributes: 
        for a in o_a: run_cmd.append(str(self.derivative[index].__dict__[a]))
        index +=1
    
    run_string = ""
    for r_c in run_cmd: run_string = "%s %s"%(run_string,r_c)
    if(debug): print run_string
    
    start = time.time() #Wall-time is measured by framework, not the generated application to measure overhead in calling code
    results = subprocess.check_output(run_cmd)
    finish = time.time()
    
    results = results.split("\n")[:-1]
    results.append((finish-start)*1000000)
    
    os.chdir(self.platform.root_directory())
    os.chdir("bin")
    
    if(cleanup): self.cleanup()
    
    return results
  
  def trial_run(self,paths,steps,redudancy=10,paths_start=0):
    accuracy = []
    latency = []
    accuracy_var = []
    latency_var = []

    path_set = numpy.arange(max(paths_start,paths),max(paths_start,paths)+paths*steps,paths)
    for p in path_set: #Trial Runs to generate data needed for predicition functions
      self.solver_metadata["paths"] = p
      temp_latency = []
      temp_error = []
      for i in range(redudancy):
	self.dummy_run()
	execution_output = solver.execute()
	
	#latency.append((float(execution_output[-1])-float(execution_output[-2]),float(execution_output[-2]))) #(setup_time,activity_time)
	temp_latency.append(float(execution_output[-1]))
	
	temp_temp_error = []
	value = 0.0
	for i,e_o in enumerate(execution_output[:-3]):
	  if(not i%2): value = float(e_o)+0.00000000000001
	  else: temp_temp_error.append(float(e_o)) #temp_error.append(float(e_o)/value*100) #percentage relative error
	  
	temp_error.append(max(temp_temp_error))
      
      accuracy.append(numpy.mean(temp_error))
      accuracy_var.append(numpy.var(temp_error))
      latency.append(numpy.mean(temp_latency))
      latency_var.append(numpy.var(temp_latency))

    return [accuracy,latency,accuracy_var,latency_var]
    
  def dummy_run(self):
      rfir = 0.1
      current_price = 100
      time_period = 1.0
      call = 1.0
      strike_price = 100
      paths = 1000
      
      underlying = [Underlying.Underlying(rfir,current_price)]
      option = [Option.Option(underlying,time_period,call,strike_price)]
      platform = MaxelerFPGA.MaxelerFPGA()
      mc_solver = MaxelerFPGA_MonteCarlo(option,paths,platform) #because we can do recursive calls like this
      #mc_solver.generate()
      #compile_output = mc_solver.compile() #assume this has been done already
      mc_solver.execute()
