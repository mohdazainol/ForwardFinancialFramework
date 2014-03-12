# 
# Synthesis run script generated by Vivado
# 

set_msg_config -id {HDL 9-1061} -limit 100000
set_msg_config -id {HDL 9-1654} -limit 100000
create_project -in_memory -part xc7z020clg484-1
set_property target_language Verilog [current_project]
set_param project.compositeFile.enableAutoGeneration 0
add_files /home/sf306/phd_codebase/FPL2014/F3_VivadoHLS/hls_prj/F3_VivadoHLS_core/impl/vhdl/project.runs/vivado_activity_thread_ap_fcmp_1_no_dsp_synth_1/vivado_activity_thread_ap_fcmp_1_no_dsp.dcp
set_property used_in_implementation false [get_files /home/sf306/phd_codebase/FPL2014/F3_VivadoHLS/hls_prj/F3_VivadoHLS_core/impl/vhdl/project.runs/vivado_activity_thread_ap_fcmp_1_no_dsp_synth_1/vivado_activity_thread_ap_fcmp_1_no_dsp.dcp]
set_property use_blackbox_stub false [get_files /home/sf306/phd_codebase/FPL2014/F3_VivadoHLS/hls_prj/F3_VivadoHLS_core/impl/vhdl/project.runs/vivado_activity_thread_ap_fcmp_1_no_dsp_synth_1/vivado_activity_thread_ap_fcmp_1_no_dsp.dcp]
add_files /home/sf306/phd_codebase/FPL2014/F3_VivadoHLS/hls_prj/F3_VivadoHLS_core/impl/vhdl/project.runs/vivado_activity_thread_ap_faddfsub_3_full_dsp_synth_1/vivado_activity_thread_ap_faddfsub_3_full_dsp.dcp
set_property used_in_implementation false [get_files /home/sf306/phd_codebase/FPL2014/F3_VivadoHLS/hls_prj/F3_VivadoHLS_core/impl/vhdl/project.runs/vivado_activity_thread_ap_faddfsub_3_full_dsp_synth_1/vivado_activity_thread_ap_faddfsub_3_full_dsp.dcp]
set_property use_blackbox_stub false [get_files /home/sf306/phd_codebase/FPL2014/F3_VivadoHLS/hls_prj/F3_VivadoHLS_core/impl/vhdl/project.runs/vivado_activity_thread_ap_faddfsub_3_full_dsp_synth_1/vivado_activity_thread_ap_faddfsub_3_full_dsp.dcp]
add_files /home/sf306/phd_codebase/FPL2014/F3_VivadoHLS/hls_prj/F3_VivadoHLS_core/impl/vhdl/project.runs/vivado_activity_thread_ap_fmul_2_max_dsp_synth_1/vivado_activity_thread_ap_fmul_2_max_dsp.dcp
set_property used_in_implementation false [get_files /home/sf306/phd_codebase/FPL2014/F3_VivadoHLS/hls_prj/F3_VivadoHLS_core/impl/vhdl/project.runs/vivado_activity_thread_ap_fmul_2_max_dsp_synth_1/vivado_activity_thread_ap_fmul_2_max_dsp.dcp]
set_property use_blackbox_stub false [get_files /home/sf306/phd_codebase/FPL2014/F3_VivadoHLS/hls_prj/F3_VivadoHLS_core/impl/vhdl/project.runs/vivado_activity_thread_ap_fmul_2_max_dsp_synth_1/vivado_activity_thread_ap_fmul_2_max_dsp.dcp]
add_files /home/sf306/phd_codebase/FPL2014/F3_VivadoHLS/hls_prj/F3_VivadoHLS_core/impl/vhdl/project.runs/vivado_activity_thread_ap_fexp_7_full_dsp_synth_1/vivado_activity_thread_ap_fexp_7_full_dsp.dcp
set_property used_in_implementation false [get_files /home/sf306/phd_codebase/FPL2014/F3_VivadoHLS/hls_prj/F3_VivadoHLS_core/impl/vhdl/project.runs/vivado_activity_thread_ap_fexp_7_full_dsp_synth_1/vivado_activity_thread_ap_fexp_7_full_dsp.dcp]
set_property use_blackbox_stub false [get_files /home/sf306/phd_codebase/FPL2014/F3_VivadoHLS/hls_prj/F3_VivadoHLS_core/impl/vhdl/project.runs/vivado_activity_thread_ap_fexp_7_full_dsp_synth_1/vivado_activity_thread_ap_fexp_7_full_dsp.dcp]
read_verilog {
  /home/sf306/phd_codebase/FPL2014/F3_VivadoHLS/hls_prj/F3_VivadoHLS_core/impl/vhdl/project.srcs/sources_1/ip/vivado_activity_thread_ap_fcmp_1_no_dsp/vivado_activity_thread_ap_fcmp_1_no_dsp_stub.v
  /home/sf306/phd_codebase/FPL2014/F3_VivadoHLS/hls_prj/F3_VivadoHLS_core/impl/vhdl/project.srcs/sources_1/ip/vivado_activity_thread_ap_faddfsub_3_full_dsp/vivado_activity_thread_ap_faddfsub_3_full_dsp_stub.v
  /home/sf306/phd_codebase/FPL2014/F3_VivadoHLS/hls_prj/F3_VivadoHLS_core/impl/vhdl/project.srcs/sources_1/ip/vivado_activity_thread_ap_fmul_2_max_dsp/vivado_activity_thread_ap_fmul_2_max_dsp_stub.v
  /home/sf306/phd_codebase/FPL2014/F3_VivadoHLS/hls_prj/F3_VivadoHLS_core/impl/vhdl/project.srcs/sources_1/ip/vivado_activity_thread_ap_fexp_7_full_dsp/vivado_activity_thread_ap_fexp_7_full_dsp_stub.v
}
read_vhdl {
  /home/sf306/phd_codebase/FPL2014/F3_VivadoHLS/hls_prj/F3_VivadoHLS_core/impl/vhdl/vivado_activity_thread_fmul_32ns_32ns_32_4_max_dsp.vhd
  /home/sf306/phd_codebase/FPL2014/F3_VivadoHLS/hls_prj/F3_VivadoHLS_core/impl/vhdl/vivado_activity_thread_fexp_32ns_32ns_32_9_full_dsp.vhd
  /home/sf306/phd_codebase/FPL2014/F3_VivadoHLS/hls_prj/F3_VivadoHLS_core/impl/vhdl/vivado_activity_thread_fcmp_32ns_32ns_1_3.vhd
  /home/sf306/phd_codebase/FPL2014/F3_VivadoHLS/hls_prj/F3_VivadoHLS_core/impl/vhdl/vivado_activity_thread_faddfsub_32ns_32ns_32_5_full_dsp.vhd
  /home/sf306/phd_codebase/FPL2014/F3_VivadoHLS/hls_prj/F3_VivadoHLS_core/impl/vhdl/vivado_activity_thread.vhd
}
read_xdc /home/sf306/phd_codebase/FPL2014/F3_VivadoHLS/hls_prj/F3_VivadoHLS_core/impl/vhdl/vivado_activity_thread.xdc
set_property used_in_implementation false [get_files /home/sf306/phd_codebase/FPL2014/F3_VivadoHLS/hls_prj/F3_VivadoHLS_core/impl/vhdl/vivado_activity_thread.xdc]

read_xdc dont_buffer.xdc
set_property used_in_implementation false [get_files dont_buffer.xdc]
set_param synth.vivado.isSynthRun true
set_property webtalk.parent_dir /home/sf306/phd_codebase/FPL2014/F3_VivadoHLS/hls_prj/F3_VivadoHLS_core/impl/vhdl/project.data/wt [current_project]
set_property parent.project_dir /home/sf306/phd_codebase/FPL2014/F3_VivadoHLS/hls_prj/F3_VivadoHLS_core/impl/vhdl [current_project]
synth_design -top vivado_activity_thread -part xc7z020clg484-1 -no_lc -no_iobuf -mode out_of_context
write_checkpoint vivado_activity_thread.dcp
report_utilization -file vivado_activity_thread_utilization_synth.rpt -pb vivado_activity_thread_utilization_synth.pb
