'''
Created on 30 October 2012

'''
import os,time,subprocess,sys,time,math,ForwardFinancialFramework.Platforms.MulticoreCPU

class MonteCarlo_Multicore(MulicoreCPU_MonteCarlo.MulticoreCPU_MonteCarlo):
  def __init__(self,derivative,paths,platform,reduce_underlyings=True):
    self.__init__(self,derivative,paths,platform,reduce_underlyings)
    
  
  def generate_activity_thread(self):
    return ""
  
  def maxeler_code_generate(self,overide=True):
	#Changing to code generation directory
        try: os.chdir("../Solvers/MonteCarlo/maxeler_code")
        except: print "Maxeler Code directory doesn't exist!"
        
        #Checking that the source code for the derivative and underlying is present
        for u in self.underlying:
            if(not(os.path.exists("%s.java"%u.name))): raise IOError, ("missing the source code for the underlying - %s.java" % (u.name))
            if(not(os.path.exists("%s_parameters.java"%u.name))): raise IOError, ("missing the source code for the underlying parameter set - %s_parameters.java" % (u.name))
        for d in self.derivative:
            if(not(os.path.exists("%s.java"%d.name))): raise IOError, ("missing the source code for the derivative - %s.java" %  (d.name))
            if(not(os.path.exists("%s_parameters.java"%d.name))): raise IOError, ("missing the source code for the derivative parameter set - %s_parameters.java" %  (d.name))
        
        if(overide or not os.path.exists("%s_maxeler_host.c"%self.output_file_name)): self.maxeler_host_code_generate()
        if(overide or not os.path.exists("%s_maxeler_kernel.java"%self.output_file_name)): self.maxeler_kernel_code_generate()
        if(overide or not os.path.exists("%s_maxeler_hw_builder.java"%self.output_file_name)): self.maxeler_hw_builder_code_generate()
        
    def maxeler_host_code_generate(self):
	 #Opening the output file for editing
	output_file = open("%s_maxeler_host.c"%self.output_file_name,"w")
	output_file.write("//%s - %s_maxeler_host.c\n"%(self.name,self.output_file_name))
	output_file.write("//Generated by F^3 Monte Carlo Solver\n\n")
	
	#Library imports
	output_file.write("//\t*Libraries*\n")
	output_file.write("#define __STDC_FORMAT_MACROS\n#include <stdio.h>\n#include <stdlib.h>\n#include <stdint.h>\n#include <MaxCompilerRT.h>\n")
	output_file.write("\n")
	
	#Solver Metadata
	output_file.write("//\t*Solver Metadata*\n")
	output_file.write("\n")
	
	#Device Interaction Variables
    
    def maxeler_kernel_code_generate(self):
	pass
      
    def maxeler_hw_builder_code_generate(self):
	pass
    
    def maxeler_compile(self,overide=True):
	pass
    
    def maxeler_execute(self):
	results = []
      
	return results