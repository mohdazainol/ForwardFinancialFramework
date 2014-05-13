# This file is automatically generated.
# It contains project source information necessary for synthesis and implementation.

# Block Designs: bd/zynq_system/zynq_system.bd
set_property DONT_TOUCH TRUE [get_cells -hier -filter {REF_NAME==zynq_system || ORIG_REF_NAME==zynq_system}]

# IP: bd/zynq_system/ip/zynq_system_processing_system7_0_0/zynq_system_processing_system7_0_0.xci
set_property DONT_TOUCH TRUE [get_cells -hier -filter {REF_NAME==zynq_system_processing_system7_0_0 || ORIG_REF_NAME==zynq_system_processing_system7_0_0}]

# IP: bd/zynq_system/ip/zynq_system_vivado_activity_thread_0_0/zynq_system_vivado_activity_thread_0_0.xci
set_property DONT_TOUCH TRUE [get_cells -hier -filter {REF_NAME==zynq_system_vivado_activity_thread_0_0 || ORIG_REF_NAME==zynq_system_vivado_activity_thread_0_0}]

# IP: bd/zynq_system/ip/zynq_system_processing_system7_0_axi_periph_0_0/zynq_system_processing_system7_0_axi_periph_0.xci
set_property DONT_TOUCH TRUE [get_cells -hier -filter {REF_NAME==zynq_system_processing_system7_0_axi_periph_0 || ORIG_REF_NAME==zynq_system_processing_system7_0_axi_periph_0}]

# IP: bd/zynq_system/ip/zynq_system_rst_processing_system7_0_50M_0_0/zynq_system_rst_processing_system7_0_50M_0.xci
set_property DONT_TOUCH TRUE [get_cells -hier -filter {REF_NAME==zynq_system_rst_processing_system7_0_50M_0 || ORIG_REF_NAME==zynq_system_rst_processing_system7_0_50M_0}]

# IP: bd/zynq_system/ip/zynq_system_axi_mem_intercon_1/zynq_system_axi_mem_intercon_1.xci
set_property DONT_TOUCH TRUE [get_cells -hier -filter {REF_NAME==zynq_system_axi_mem_intercon_1 || ORIG_REF_NAME==zynq_system_axi_mem_intercon_1}]

# IP: bd/zynq_system/ip/zynq_system_auto_pc_4_0/zynq_system_auto_pc_4.xci
set_property DONT_TOUCH TRUE [get_cells -hier -filter {REF_NAME==zynq_system_auto_pc_4 || ORIG_REF_NAME==zynq_system_auto_pc_4}]

# IP: bd/zynq_system/ip/zynq_system_auto_pc_5/zynq_system_auto_pc_5.xci
set_property DONT_TOUCH TRUE [get_cells -hier -filter {REF_NAME==zynq_system_auto_pc_5 || ORIG_REF_NAME==zynq_system_auto_pc_5}]

# XDC: bd/zynq_system/ip/zynq_system_processing_system7_0_0/zynq_system_processing_system7_0_0.xdc
set_property DONT_TOUCH TRUE [get_cells [split [join [get_cells -hier -filter {REF_NAME==zynq_system_processing_system7_0_0 || ORIG_REF_NAME==zynq_system_processing_system7_0_0}] {/inst }]/inst ]]

# XDC: bd/zynq_system/ip/zynq_system_vivado_activity_thread_0_0/constraints/vivado_activity_thread_ooc.xdc

# XDC: bd/zynq_system/ip/zynq_system_rst_processing_system7_0_50M_0_0/zynq_system_rst_processing_system7_0_50M_0.xdc
set_property DONT_TOUCH TRUE [get_cells [split [join [get_cells -hier -filter {REF_NAME==zynq_system_rst_processing_system7_0_50M_0 || ORIG_REF_NAME==zynq_system_rst_processing_system7_0_50M_0}] {/U0 }]/U0 ]]

# XDC: bd/zynq_system/ip/zynq_system_rst_processing_system7_0_50M_0_0/zynq_system_rst_processing_system7_0_50M_0_ooc.xdc

# XDC: bd/zynq_system/ip/zynq_system_rst_processing_system7_0_50M_0_0/zynq_system_rst_processing_system7_0_50M_0_board.xdc
#dup# set_property DONT_TOUCH TRUE [get_cells [split [join [get_cells -hier -filter {REF_NAME==zynq_system_rst_processing_system7_0_50M_0 || ORIG_REF_NAME==zynq_system_rst_processing_system7_0_50M_0}] {/U0 }]/U0 ]]

# XDC: bd/zynq_system/ip/zynq_system_auto_pc_4_0/zynq_system_auto_pc_4_ooc.xdc

# XDC: bd/zynq_system/ip/zynq_system_auto_pc_5/zynq_system_auto_pc_5_ooc.xdc

# XDC: bd/zynq_system/zynq_system_ooc.xdc
