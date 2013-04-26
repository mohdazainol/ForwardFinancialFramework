'''
Created on 23 February 2013

'''
import os,time,subprocess,sys,time,math,
from ForwardFinancialFramework.Platforms.MulticoreCPU import MulticoreCPU_MonteCarlo

class OpenCLGPU_MonteCarlo(MulticoreCPU_MonteCarlo.MulticoreCPU_MonteCarlo):
  def __init__(self,derivative,paths,platform,reduce_underlyings=True):
    MulticoreCPU_MonteCarlo.MulticoreCPU_MonteCarlo.__init__(self,derivative,paths,platform,reduce_underlyings)
    
    self.utility_libraries.extend(["CL/cl.hpp"])
    self.activity_thread_name = "opencl_montecarlo_activity_thread"
  
  def generate_identifier(self): return ["//%s.c Generated by Monte Carlo Maxeler Solver"%self.output_file_name]
  
  def generate(self,override=True):
    #Generate C Host Code largely using Multicore C infrastructure
    MulticoreCPU_MonteCarlo.MulticoreCPU_MonteCarlo.generate(self,".c",override,verbose=False)
    
    #Generate OpenCL Kernel Code
    kernel_code_string = self.generate_kernel()
    self.generate_source(kernel_code_string,"_Kernel.cl")
  
  def generate_activity_thread(self):
    output_list = []

    output_list.append("//*MC OpenCL Activity Thread Function*")
    output_list.append("void * %s(void* thread_arg){"%self.activity_thread_name)
    output_list.append("struct thread_data* temp_data;")
    output_list.append("temp_data = (struct thread_data*) thread_arg;")
    
    #Put dispatch to OpenCL subsystem here
    
    output_list.append("//**Post-Kernel Calculations**")
    for d in range(len(self.derivative)): 
      output_list.append("double temp_total_%d=0;"%d)
      output_list.append("double temp_value_sqrd_%d=0;"%d)
    output_list.append("for(int i=0;i<paths;i++){")
    for d in self.derivative:
      index = self.derivative.index(d)
      output_list.append("temp_total_%d += values_out[i*%d+%d];"%(index,values_out*4,index))
      output_list.append("temp_value_sqrd_%d += pow(values_out[i*%d+%d],2);"%(index,values_out*4,index))
    output_list.append("}")
    
    output_list.append("//**Returning Result**")
    #output_list.append("printf(\"temp_total=%f\",temp_total_0);")
    for d in self.derivative: 
      output_list.append("temp_data->thread_result[%d] = temp_total_%d/instances;"%(self.derivative.index(d),self.derivative.index(d)))
      output_list.append("temp_data->thread_result_sqrd[%d] = temp_total_sqrd_%d;"%(self.derivative.index(d),self.derivative.index(d)))
    output_list.append("}")
    
    return output_list
  
  def generate_libraries(self):
    output_list = ["//*Libraries"]
    output_list.append("#define __STDC_FORMAT_MACROS")
    for u in self.utility_libraries: output_list.append("#include \"%s\";"%u)
    
    return output_list
  
  def generate_kernel(self,overide=True):
    #Changing to code generation directory
    os.chdir("..")
    os.chdir(self.platform.platform_directory())
      
    #Checking that the source code for the derivative and underlying is present
    for u in self.underlying: 
      if(not(os.path.exists("%s.c"%u.name)) or not(os.path.exists("%s.h"%u.name))): raise IOError, ("missing the source code for the underlying - %s.c or %s.h" % (u.name,u.name))
        
    for d in self.derivative:
      if(not(os.path.exists("%s.c"%d.name)) or not(os.path.exists("%s.h"%d.name))): raise IOError, ("missing the source code for the derivative - %s.c or %s.h" %  (d.name,d.name))
    
    
    
    os.chdir(self.platform.root_directory())
    os.chdir("bin")
    
    output_list = []
    
    return output_list
      
  def compile(self,override=True,cleanup=True):
    result = MulticoreCPU_MonteCarlo.MulticoreCPU_MonteCarlo.compile(self,overide)
      
    
      
    return result
  
      
  """def compile(self,override=True,cleanup=True):
    try:
      os.chdir("..")
      os.chdir(self.platform.platform_directory())
      
    except:
      os.chdir("bin")
      return "Maxeler Code directory doesn't exist!"
    
    if(override or not os.path.exists("hardware/%s/"%self.output_file_name)):
      #Hardware Build Process
      compile_cmd = ["make","build-hw","APP=%s"%self.output_file_name]
      hw_result = subprocess.check_output(compile_cmd)
      #subprocess.check_output(["rm -r ../../scratch/*"]) #cleaning up majority of HDL source code generated for synthesis
      #print hw_result
      
      #Host Code Compile
      compile_cmd = ["make","app-hw","APP=%s"%self.output_file_name]
      sw_result = subprocess.check_output(compile_cmd)
      #print sw_result
      
      os.chdir(self.platform.root_directory())
      os.chdir("bin")
      
      return (hw_result,sw_result)"""
      
  def execute(self,cleanup=False):
    try:
      os.chdir("..")
      os.chdir(self.platform.platform_directory())
      
    except:
      os.chdir("bin")
      return "OpenCL code directory doesn't exist!"
    
    run_cmd = ["./%s"%self.output_file_name]
    for k in self.solver_metadata.keys(): run_cmd.append(str(self.solver_metadata[k]))
    
    index = 0
    for u_a in self.underlying_attributes:
        for a in u_a: run_cmd.append(str(self.underlying[index].__dict__[a])) #mirrors generation code to preserve order of variable loading
        index += 1
    
    index = 0
    for o_a in self.derivative_attributes: 
        for a in o_a: run_cmd.append(str(self.derivative[index].__dict__[a]))
        index +=1
    
    start = time.time() #Wall-time is measured by framework, not the generated application to measure overhead in calling code
    #print run_cmd
    results = subprocess.check_output(run_cmd)
    finish = time.time()
    
    results = results.split("\n")[:-1]
    results.append((finish-start)*1000000)
    
    os.chdir(self.platform.root_directory())
    os.chdir("bin")
    
    if(cleanup): self.cleanup()
    
    return results
    
    
  """def generate_java_source(self,code_string,name_extension=""):
    os.chdir("..")
    os.chdir(self.platform.platform_directory())
    
    output_file = open("%s%s.java"%(self.output_file_name,name_extension),"w")
    tab_count = 0;
    for c_s in code_string:
        if("*" in c_s and "//" in c_s): output_file.write("\n") #Insert a blank line if the line is a comment section
        for i in range(tab_count): output_file.write("\t")	#Tabify the code
        output_file.write("%s\n"%c_s)
            
        if("{" in c_s): tab_count = tab_count+1
        if("}" in c_s): tab_count = max(tab_count-1,0)
    output_file.close()
    
    os.chdir(self.platform.root_directory())
    os.chdir("bin")"""