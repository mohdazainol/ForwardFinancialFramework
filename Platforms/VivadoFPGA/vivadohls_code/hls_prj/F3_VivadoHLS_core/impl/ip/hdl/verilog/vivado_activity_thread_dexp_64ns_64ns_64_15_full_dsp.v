// ==============================================================
// File generated by Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC
// Version: 2013.4
// Copyright (C) 2013 Xilinx Inc. All rights reserved.
// 
// ==============================================================


`timescale 1ns/1ps

module vivado_activity_thread_dexp_64ns_64ns_64_15_full_dsp
#(parameter
    ID         = 8,
    NUM_STAGE  = 15,
    din0_WIDTH = 64,
    din1_WIDTH = 64,
    dout_WIDTH = 64
)(
    input  wire                  clk,
    input  wire                  reset,
    input  wire                  ce,
    input  wire [din0_WIDTH-1:0] din0,
    input  wire [din1_WIDTH-1:0] din1,
    output wire [dout_WIDTH-1:0] dout
);
//------------------------Local signal-------------------
wire                  aclk;
wire                  aclken;
wire                  a_tvalid;
wire [63:0]           a_tdata;
wire                  r_tvalid;
wire [63:0]           r_tdata;
reg  [din1_WIDTH-1:0] din1_buf1;
//------------------------Instantiation------------------
vivado_activity_thread_ap_dexp_13_full_dsp vivado_activity_thread_ap_dexp_13_full_dsp_u (
    .aclk                 ( aclk ),
    .aclken               ( aclken ),
    .s_axis_a_tvalid      ( a_tvalid ),
    .s_axis_a_tdata       ( a_tdata ),
    .m_axis_result_tvalid ( r_tvalid ),
    .m_axis_result_tdata  ( r_tdata )
);
//------------------------Body---------------------------
assign aclk     = clk;
assign aclken   = ce;
assign a_tvalid = 1'b1;
assign a_tdata  = din1_buf1;
assign dout     = r_tdata;

always @(posedge clk) begin
    if (ce) begin
        din1_buf1 <= din1;
    end
end

endmodule
