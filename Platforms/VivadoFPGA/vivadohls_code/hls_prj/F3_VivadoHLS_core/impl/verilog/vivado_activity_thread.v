// ==============================================================
// RTL generated by Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC
// Version: 2013.4
// Copyright (C) 2013 Xilinx Inc. All rights reserved.
// 
// ===========================================================

`timescale 1 ns / 1 ps 

(* CORE_GENERATION_INFO="vivado_activity_thread,hls_ip_2013_4,{HLS_INPUT_TYPE=c,HLS_INPUT_FLOAT=1,HLS_INPUT_FIXED=0,HLS_INPUT_PART=xc7z045ffg900-2,HLS_INPUT_CLOCK=10.000000,HLS_INPUT_ARCH=others,HLS_SYN_CLOCK=8.750000,HLS_SYN_LAT=305018,HLS_SYN_TPT=none,HLS_SYN_MEM=0,HLS_SYN_DSP=0,HLS_SYN_FF=0,HLS_SYN_LUT=0}" *)

module vivado_activity_thread (
        ap_clk,
        ap_rst,
        ap_start,
        ap_done,
        ap_idle,
        ap_ready,
        a_req_din,
        a_req_full_n,
        a_req_write,
        a_rsp_empty_n,
        a_rsp_read,
        a_address,
        a_datain,
        a_dataout,
        a_size,
        kernel_u_a_0_rfir,
        kernel_u_a_0_current_price,
        kernel_u_a_0_volatility,
        kernel_u_a_0_initial_volatility,
        kernel_u_a_0_volatility_volatility,
        kernel_u_a_0_rho,
        kernel_u_a_0_kappa,
        kernel_u_a_0_theta,
        kernel_u_a_0_correlation_matrix_0_0,
        kernel_u_a_0_correlation_matrix_0_1,
        kernel_u_a_0_correlation_matrix_1_0,
        kernel_u_a_0_correlation_matrix_1_1,
        kernel_o_a_0_second_barrier,
        kernel_o_a_0_barrier,
        kernel_o_a_0_out,
        kernel_o_a_0_down,
        kernel_o_a_0_strike_price,
        kernel_o_a_0_time_period,
        kernel_o_a_0_call,
        kernel_o_a_0_points,
        seed_0_s1,
        seed_0_s2,
        seed_0_s3,
        seed_0_offset,
        thread_result_0
);

input   ap_clk;
input   ap_rst;
input   ap_start;
output   ap_done;
output   ap_idle;
output   ap_ready;
output   a_req_din;
input   a_req_full_n;
output   a_req_write;
input   a_rsp_empty_n;
output   a_rsp_read;
output  [31:0] a_address;
input  [31:0] a_datain;
output  [31:0] a_dataout;
output  [31:0] a_size;
input  [31:0] kernel_u_a_0_rfir;
input  [31:0] kernel_u_a_0_current_price;
input  [31:0] kernel_u_a_0_volatility;
input  [31:0] kernel_u_a_0_initial_volatility;
input  [31:0] kernel_u_a_0_volatility_volatility;
input  [31:0] kernel_u_a_0_rho;
input  [31:0] kernel_u_a_0_kappa;
input  [31:0] kernel_u_a_0_theta;
input  [31:0] kernel_u_a_0_correlation_matrix_0_0;
input  [31:0] kernel_u_a_0_correlation_matrix_0_1;
input  [31:0] kernel_u_a_0_correlation_matrix_1_0;
input  [31:0] kernel_u_a_0_correlation_matrix_1_1;
input  [31:0] kernel_o_a_0_second_barrier;
input  [31:0] kernel_o_a_0_barrier;
input  [31:0] kernel_o_a_0_out;
input  [31:0] kernel_o_a_0_down;
input  [31:0] kernel_o_a_0_strike_price;
input  [31:0] kernel_o_a_0_time_period;
input  [31:0] kernel_o_a_0_call;
input  [31:0] kernel_o_a_0_points;
input  [31:0] seed_0_s1;
input  [31:0] seed_0_s2;
input  [31:0] seed_0_s3;
input  [31:0] seed_0_offset;
input  [31:0] thread_result_0;

reg ap_done;
reg ap_idle;
reg ap_ready;
reg a_req_din;
reg a_req_write;
reg   [5:0] ap_CS_fsm = 6'b000000;
reg   [9:0] indvar_reg_253;
wire   [31:0] grp_fu_265_p2;
reg   [31:0] reg_304;
reg   [0:0] tmp_7_reg_439;
wire   [31:0] grp_fu_275_p2;
reg   [31:0] delta_time_0_reg_398;
wire   [63:0] grp_fu_284_p1;
reg   [63:0] tmp_8_reg_429;
wire   [31:0] grp_fu_270_p2;
reg   [31:0] tmp_i_reg_434;
wire   [0:0] tmp_7_fu_308_p2;
wire   [9:0] p_1_fu_320_p2;
reg   [9:0] p_1_reg_447;
reg   [31:0] a_addr_reg_452;
wire   [0:0] exitcond1_fu_314_p2;
wire   [63:0] grp_fu_294_p2;
reg   [63:0] spot_price_0_0_in_reg_457;
wire   [31:0] grp_fu_281_p1;
reg   [31:0] spot_price_0_reg_462;
wire   [3:0] pp_1_fu_351_p2;
reg   [3:0] pp_1_reg_471;
reg   [31:0] u_v_0_gamma_reg_476;
reg   [63:0] tmp_4_reg_482;
wire   [63:0] grp_fu_299_p2;
wire   [0:0] exitcond2_fu_370_p2;
reg   [0:0] exitcond2_reg_492;
reg    ap_reg_ppiten_pp0_it0 = 1'b0;
reg    ap_reg_ppiten_pp0_it1 = 1'b0;
reg   [0:0] ap_reg_ppstg_exitcond2_reg_492_pp0_it1;
reg    ap_sig_bdd_179;
reg    ap_reg_ppiten_pp0_it2 = 1'b0;
wire   [9:0] indvar_next_fu_376_p2;
wire   [0:0] isIter0_fu_387_p2;
reg   [0:0] isIter0_reg_506;
reg   [0:0] ap_reg_ppstg_isIter0_reg_506_pp0_it1;
wire   [31:0] thread_result_buff_q0;
reg   [31:0] thread_result_buff_load_reg_510;
reg   [9:0] thread_result_buff_address0;
reg    thread_result_buff_ce0;
reg    thread_result_buff_we0;
wire   [31:0] thread_result_buff_d0;
reg   [9:0] p_reg_206;
reg   [63:0] tmp_pn_reg_218;
reg   [31:0] u_v_gamma_read_assign_reg_230;
reg   [3:0] pp_reg_242;
wire   [63:0] tmp_2_fu_365_p1;
wire   [63:0] tmp_3_fu_382_p1;
wire   [63:0] tmp_5_fu_335_p1;
reg   [31:0] grp_fu_265_p0;
reg   [31:0] grp_fu_265_p1;
wire   [31:0] grp_fu_270_p0;
wire   [31:0] grp_fu_270_p1;
wire   [31:0] grp_fu_275_p0;
wire   [31:0] grp_fu_275_p1;
wire   [63:0] grp_fu_281_p0;
reg   [31:0] grp_fu_284_p0;
wire   [31:0] grp_fu_288_p0;
wire   [31:0] grp_fu_288_p1;
wire   [63:0] grp_fu_294_p0;
wire   [63:0] grp_fu_294_p1;
wire   [63:0] grp_fu_299_p1;
wire   [0:0] grp_fu_288_p2;
wire   [29:0] tmp_fu_326_p4;
reg   [1:0] grp_fu_265_opcode;
wire   [0:0] exitcond_fu_345_p2;
wire    grp_fu_265_ce;
wire    grp_fu_270_ce;
wire    grp_fu_275_ce;
wire    grp_fu_281_ce;
wire    grp_fu_284_ce;
wire    grp_fu_288_ce;
wire   [4:0] grp_fu_288_opcode;
wire    grp_fu_294_ce;
wire   [63:0] grp_fu_299_p0;
wire    grp_fu_299_ce;
reg   [5:0] ap_NS_fsm;
parameter    ap_const_logic_1 = 1'b1;
parameter    ap_const_logic_0 = 1'b0;
parameter    ap_ST_st1_fsm_0 = 6'b000000;
parameter    ap_ST_st2_fsm_1 = 6'b1;
parameter    ap_ST_st3_fsm_2 = 6'b10;
parameter    ap_ST_st4_fsm_3 = 6'b11;
parameter    ap_ST_st5_fsm_4 = 6'b100;
parameter    ap_ST_st6_fsm_5 = 6'b101;
parameter    ap_ST_st7_fsm_6 = 6'b110;
parameter    ap_ST_st8_fsm_7 = 6'b111;
parameter    ap_ST_st9_fsm_8 = 6'b1000;
parameter    ap_ST_st10_fsm_9 = 6'b1001;
parameter    ap_ST_st11_fsm_10 = 6'b1010;
parameter    ap_ST_st12_fsm_11 = 6'b1011;
parameter    ap_ST_st13_fsm_12 = 6'b1100;
parameter    ap_ST_st14_fsm_13 = 6'b1101;
parameter    ap_ST_st15_fsm_14 = 6'b1110;
parameter    ap_ST_st16_fsm_15 = 6'b1111;
parameter    ap_ST_st17_fsm_16 = 6'b10000;
parameter    ap_ST_st18_fsm_17 = 6'b10001;
parameter    ap_ST_st19_fsm_18 = 6'b10010;
parameter    ap_ST_st20_fsm_19 = 6'b10011;
parameter    ap_ST_st21_fsm_20 = 6'b10100;
parameter    ap_ST_st22_fsm_21 = 6'b10101;
parameter    ap_ST_st23_fsm_22 = 6'b10110;
parameter    ap_ST_st24_fsm_23 = 6'b10111;
parameter    ap_ST_st25_fsm_24 = 6'b11000;
parameter    ap_ST_st26_fsm_25 = 6'b11001;
parameter    ap_ST_st27_fsm_26 = 6'b11010;
parameter    ap_ST_st28_fsm_27 = 6'b11011;
parameter    ap_ST_st29_fsm_28 = 6'b11100;
parameter    ap_ST_st30_fsm_29 = 6'b11101;
parameter    ap_ST_st31_fsm_30 = 6'b11110;
parameter    ap_ST_st32_fsm_31 = 6'b11111;
parameter    ap_ST_st33_fsm_32 = 6'b100000;
parameter    ap_ST_st34_fsm_33 = 6'b100001;
parameter    ap_ST_st35_fsm_34 = 6'b100010;
parameter    ap_ST_st36_fsm_35 = 6'b100011;
parameter    ap_ST_st37_fsm_36 = 6'b100100;
parameter    ap_ST_st38_fsm_37 = 6'b100101;
parameter    ap_ST_st39_fsm_38 = 6'b100110;
parameter    ap_ST_st40_fsm_39 = 6'b100111;
parameter    ap_ST_st41_fsm_40 = 6'b101000;
parameter    ap_ST_st42_fsm_41 = 6'b101001;
parameter    ap_ST_st43_fsm_42 = 6'b101010;
parameter    ap_ST_st44_fsm_43 = 6'b101011;
parameter    ap_ST_st45_fsm_44 = 6'b101100;
parameter    ap_ST_st46_fsm_45 = 6'b101101;
parameter    ap_ST_st47_fsm_46 = 6'b101110;
parameter    ap_ST_st48_fsm_47 = 6'b101111;
parameter    ap_ST_st49_fsm_48 = 6'b110000;
parameter    ap_ST_st50_fsm_49 = 6'b110001;
parameter    ap_ST_pp0_stg0_fsm_50 = 6'b110010;
parameter    ap_ST_st54_fsm_51 = 6'b110011;
parameter    ap_const_lv1_0 = 1'b0;
parameter    ap_const_lv10_0 = 10'b0000000000;
parameter    ap_const_lv64_3FF0000000000000 = 64'b11111111110000000000000000000000000000000000000000000000000000;
parameter    ap_const_lv32_0 = 32'b00000000000000000000000000000000;
parameter    ap_const_lv4_0 = 4'b0000;
parameter    ap_const_lv32_3E8 = 32'b1111101000;
parameter    ap_const_lv32_41200000 = 32'b1000001001000000000000000000000;
parameter    ap_const_lv1_1 = 1'b1;
parameter    ap_const_lv10_3E8 = 10'b1111101000;
parameter    ap_const_lv10_1 = 10'b1;
parameter    ap_const_lv32_2 = 32'b10;
parameter    ap_const_lv32_1F = 32'b11111;
parameter    ap_const_lv4_A = 4'b1010;
parameter    ap_const_lv4_1 = 4'b1;
parameter    ap_const_lv2_0 = 2'b00;
parameter    ap_const_lv2_1 = 2'b1;
parameter    ap_const_lv5_1 = 5'b1;
parameter    ap_const_lv64_1 = 64'b1;
parameter    ap_true = 1'b1;


vivado_activity_thread_thread_result_buff #(
    .DataWidth( 32 ),
    .AddressRange( 1000 ),
    .AddressWidth( 10 ))
thread_result_buff_U(
    .clk( ap_clk ),
    .reset( ap_rst ),
    .address0( thread_result_buff_address0 ),
    .ce0( thread_result_buff_ce0 ),
    .we0( thread_result_buff_we0 ),
    .d0( thread_result_buff_d0 ),
    .q0( thread_result_buff_q0 )
);

vivado_activity_thread_faddfsub_32ns_32ns_32_4_full_dsp #(
    .ID( 1 ),
    .NUM_STAGE( 4 ),
    .din0_WIDTH( 32 ),
    .din1_WIDTH( 32 ),
    .dout_WIDTH( 32 ))
vivado_activity_thread_faddfsub_32ns_32ns_32_4_full_dsp_U1(
    .clk( ap_clk ),
    .reset( ap_rst ),
    .din0( grp_fu_265_p0 ),
    .din1( grp_fu_265_p1 ),
    .opcode( grp_fu_265_opcode ),
    .ce( grp_fu_265_ce ),
    .dout( grp_fu_265_p2 )
);

vivado_activity_thread_fmul_32ns_32ns_32_3_max_dsp #(
    .ID( 2 ),
    .NUM_STAGE( 3 ),
    .din0_WIDTH( 32 ),
    .din1_WIDTH( 32 ),
    .dout_WIDTH( 32 ))
vivado_activity_thread_fmul_32ns_32ns_32_3_max_dsp_U2(
    .clk( ap_clk ),
    .reset( ap_rst ),
    .din0( grp_fu_270_p0 ),
    .din1( grp_fu_270_p1 ),
    .ce( grp_fu_270_ce ),
    .dout( grp_fu_270_p2 )
);

vivado_activity_thread_fdiv_32ns_32ns_32_12 #(
    .ID( 3 ),
    .NUM_STAGE( 12 ),
    .din0_WIDTH( 32 ),
    .din1_WIDTH( 32 ),
    .dout_WIDTH( 32 ))
vivado_activity_thread_fdiv_32ns_32ns_32_12_U3(
    .clk( ap_clk ),
    .reset( ap_rst ),
    .din0( grp_fu_275_p0 ),
    .din1( grp_fu_275_p1 ),
    .ce( grp_fu_275_ce ),
    .dout( grp_fu_275_p2 )
);

vivado_activity_thread_fptrunc_64ns_32_3 #(
    .ID( 4 ),
    .NUM_STAGE( 3 ),
    .din0_WIDTH( 64 ),
    .dout_WIDTH( 32 ))
vivado_activity_thread_fptrunc_64ns_32_3_U4(
    .clk( ap_clk ),
    .reset( ap_rst ),
    .din0( grp_fu_281_p0 ),
    .ce( grp_fu_281_ce ),
    .dout( grp_fu_281_p1 )
);

vivado_activity_thread_fpext_32ns_64_3 #(
    .ID( 5 ),
    .NUM_STAGE( 3 ),
    .din0_WIDTH( 32 ),
    .dout_WIDTH( 64 ))
vivado_activity_thread_fpext_32ns_64_3_U5(
    .clk( ap_clk ),
    .reset( ap_rst ),
    .din0( grp_fu_284_p0 ),
    .ce( grp_fu_284_ce ),
    .dout( grp_fu_284_p1 )
);

vivado_activity_thread_fcmp_32ns_32ns_1_3 #(
    .ID( 6 ),
    .NUM_STAGE( 3 ),
    .din0_WIDTH( 32 ),
    .din1_WIDTH( 32 ),
    .dout_WIDTH( 1 ))
vivado_activity_thread_fcmp_32ns_32ns_1_3_U6(
    .clk( ap_clk ),
    .reset( ap_rst ),
    .din0( grp_fu_288_p0 ),
    .din1( grp_fu_288_p1 ),
    .ce( grp_fu_288_ce ),
    .opcode( grp_fu_288_opcode ),
    .dout( grp_fu_288_p2 )
);

vivado_activity_thread_dmul_64ns_64ns_64_5_max_dsp #(
    .ID( 7 ),
    .NUM_STAGE( 5 ),
    .din0_WIDTH( 64 ),
    .din1_WIDTH( 64 ),
    .dout_WIDTH( 64 ))
vivado_activity_thread_dmul_64ns_64ns_64_5_max_dsp_U7(
    .clk( ap_clk ),
    .reset( ap_rst ),
    .din0( grp_fu_294_p0 ),
    .din1( grp_fu_294_p1 ),
    .ce( grp_fu_294_ce ),
    .dout( grp_fu_294_p2 )
);

vivado_activity_thread_dexp_64ns_64ns_64_15_full_dsp #(
    .ID( 8 ),
    .NUM_STAGE( 15 ),
    .din0_WIDTH( 64 ),
    .din1_WIDTH( 64 ),
    .dout_WIDTH( 64 ))
vivado_activity_thread_dexp_64ns_64ns_64_15_full_dsp_U8(
    .clk( ap_clk ),
    .reset( ap_rst ),
    .din0( grp_fu_299_p0 ),
    .din1( grp_fu_299_p1 ),
    .ce( grp_fu_299_ce ),
    .dout( grp_fu_299_p2 )
);



/// the current state (ap_CS_fsm) of the state machine. ///
always @ (posedge ap_clk)
begin : ap_ret_ap_CS_fsm
    if (ap_rst == 1'b1) begin
        ap_CS_fsm <= ap_ST_st1_fsm_0;
    end else begin
        ap_CS_fsm <= ap_NS_fsm;
    end
end

/// ap_reg_ppiten_pp0_it0 assign process. ///
always @ (posedge ap_clk)
begin : ap_ret_ap_reg_ppiten_pp0_it0
    if (ap_rst == 1'b1) begin
        ap_reg_ppiten_pp0_it0 <= ap_const_logic_0;
    end else begin
        if (((ap_ST_pp0_stg0_fsm_50 == ap_CS_fsm) & ~(ap_sig_bdd_179 & (ap_const_logic_1 == ap_reg_ppiten_pp0_it2)) & ~(ap_const_lv1_0 == exitcond2_fu_370_p2))) begin
            ap_reg_ppiten_pp0_it0 <= ap_const_logic_0;
        end else if (((ap_ST_st16_fsm_15 == ap_CS_fsm) & ~(ap_const_lv1_0 == exitcond1_fu_314_p2))) begin
            ap_reg_ppiten_pp0_it0 <= ap_const_logic_1;
        end
    end
end

/// ap_reg_ppiten_pp0_it1 assign process. ///
always @ (posedge ap_clk)
begin : ap_ret_ap_reg_ppiten_pp0_it1
    if (ap_rst == 1'b1) begin
        ap_reg_ppiten_pp0_it1 <= ap_const_logic_0;
    end else begin
        if (((ap_ST_pp0_stg0_fsm_50 == ap_CS_fsm) & ~(ap_sig_bdd_179 & (ap_const_logic_1 == ap_reg_ppiten_pp0_it2)) & (ap_const_lv1_0 == exitcond2_fu_370_p2))) begin
            ap_reg_ppiten_pp0_it1 <= ap_const_logic_1;
        end else if ((((ap_ST_st16_fsm_15 == ap_CS_fsm) & ~(ap_const_lv1_0 == exitcond1_fu_314_p2)) | ((ap_ST_pp0_stg0_fsm_50 == ap_CS_fsm) & ~(ap_sig_bdd_179 & (ap_const_logic_1 == ap_reg_ppiten_pp0_it2)) & ~(ap_const_lv1_0 == exitcond2_fu_370_p2)))) begin
            ap_reg_ppiten_pp0_it1 <= ap_const_logic_0;
        end
    end
end

/// ap_reg_ppiten_pp0_it2 assign process. ///
always @ (posedge ap_clk)
begin : ap_ret_ap_reg_ppiten_pp0_it2
    if (ap_rst == 1'b1) begin
        ap_reg_ppiten_pp0_it2 <= ap_const_logic_0;
    end else begin
        if (((ap_ST_pp0_stg0_fsm_50 == ap_CS_fsm) & ~(ap_sig_bdd_179 & (ap_const_logic_1 == ap_reg_ppiten_pp0_it2)))) begin
            ap_reg_ppiten_pp0_it2 <= ap_reg_ppiten_pp0_it1;
        end else if (((ap_ST_st16_fsm_15 == ap_CS_fsm) & ~(ap_const_lv1_0 == exitcond1_fu_314_p2))) begin
            ap_reg_ppiten_pp0_it2 <= ap_const_logic_0;
        end
    end
end

/// assign process. ///
always @(posedge ap_clk)
begin
    if (((ap_ST_st16_fsm_15 == ap_CS_fsm) & ~(ap_const_lv1_0 == exitcond1_fu_314_p2))) begin
        indvar_reg_253 <= ap_const_lv10_0;
    end else if (((ap_ST_pp0_stg0_fsm_50 == ap_CS_fsm) & (ap_const_logic_1 == ap_reg_ppiten_pp0_it0) & ~(ap_sig_bdd_179 & (ap_const_logic_1 == ap_reg_ppiten_pp0_it2)) & (ap_const_lv1_0 == exitcond2_fu_370_p2))) begin
        indvar_reg_253 <= indvar_next_fu_376_p2;
    end
end

/// assign process. ///
always @(posedge ap_clk)
begin
    if ((ap_ST_st50_fsm_49 == ap_CS_fsm)) begin
        p_reg_206 <= p_1_reg_447;
    end else if ((ap_ST_st15_fsm_14 == ap_CS_fsm)) begin
        p_reg_206 <= ap_const_lv10_0;
    end
end

/// assign process. ///
always @(posedge ap_clk)
begin
    if ((ap_ST_st45_fsm_44 == ap_CS_fsm)) begin
        pp_reg_242 <= pp_1_reg_471;
    end else if (((ap_ST_st16_fsm_15 == ap_CS_fsm) & (ap_const_lv1_0 == exitcond1_fu_314_p2))) begin
        pp_reg_242 <= ap_const_lv4_0;
    end
end

/// assign process. ///
always @(posedge ap_clk)
begin
    if ((ap_ST_st45_fsm_44 == ap_CS_fsm)) begin
        tmp_pn_reg_218 <= grp_fu_299_p2;
    end else if (((ap_ST_st16_fsm_15 == ap_CS_fsm) & (ap_const_lv1_0 == exitcond1_fu_314_p2))) begin
        tmp_pn_reg_218 <= ap_const_lv64_3FF0000000000000;
    end
end

/// assign process. ///
always @(posedge ap_clk)
begin
    if ((ap_ST_st45_fsm_44 == ap_CS_fsm)) begin
        u_v_gamma_read_assign_reg_230 <= u_v_0_gamma_reg_476;
    end else if (((ap_ST_st16_fsm_15 == ap_CS_fsm) & (ap_const_lv1_0 == exitcond1_fu_314_p2))) begin
        u_v_gamma_read_assign_reg_230 <= ap_const_lv32_0;
    end
end

/// assign process. ///
always @(posedge ap_clk)
begin
    if (((ap_ST_st16_fsm_15 == ap_CS_fsm) & ~(ap_const_lv1_0 == exitcond1_fu_314_p2))) begin
        a_addr_reg_452[0] <= tmp_5_fu_335_p1[0];
a_addr_reg_452[1] <= tmp_5_fu_335_p1[1];
a_addr_reg_452[2] <= tmp_5_fu_335_p1[2];
a_addr_reg_452[3] <= tmp_5_fu_335_p1[3];
a_addr_reg_452[4] <= tmp_5_fu_335_p1[4];
a_addr_reg_452[5] <= tmp_5_fu_335_p1[5];
a_addr_reg_452[6] <= tmp_5_fu_335_p1[6];
a_addr_reg_452[7] <= tmp_5_fu_335_p1[7];
a_addr_reg_452[8] <= tmp_5_fu_335_p1[8];
a_addr_reg_452[9] <= tmp_5_fu_335_p1[9];
a_addr_reg_452[10] <= tmp_5_fu_335_p1[10];
a_addr_reg_452[11] <= tmp_5_fu_335_p1[11];
a_addr_reg_452[12] <= tmp_5_fu_335_p1[12];
a_addr_reg_452[13] <= tmp_5_fu_335_p1[13];
a_addr_reg_452[14] <= tmp_5_fu_335_p1[14];
a_addr_reg_452[15] <= tmp_5_fu_335_p1[15];
a_addr_reg_452[16] <= tmp_5_fu_335_p1[16];
a_addr_reg_452[17] <= tmp_5_fu_335_p1[17];
a_addr_reg_452[18] <= tmp_5_fu_335_p1[18];
a_addr_reg_452[19] <= tmp_5_fu_335_p1[19];
a_addr_reg_452[20] <= tmp_5_fu_335_p1[20];
a_addr_reg_452[21] <= tmp_5_fu_335_p1[21];
a_addr_reg_452[22] <= tmp_5_fu_335_p1[22];
a_addr_reg_452[23] <= tmp_5_fu_335_p1[23];
a_addr_reg_452[24] <= tmp_5_fu_335_p1[24];
a_addr_reg_452[25] <= tmp_5_fu_335_p1[25];
a_addr_reg_452[26] <= tmp_5_fu_335_p1[26];
a_addr_reg_452[27] <= tmp_5_fu_335_p1[27];
a_addr_reg_452[28] <= tmp_5_fu_335_p1[28];
a_addr_reg_452[29] <= tmp_5_fu_335_p1[29];
    end
end

/// assign process. ///
always @(posedge ap_clk)
begin
    if (((ap_ST_pp0_stg0_fsm_50 == ap_CS_fsm) & ~(ap_sig_bdd_179 & (ap_const_logic_1 == ap_reg_ppiten_pp0_it2)))) begin
        ap_reg_ppstg_exitcond2_reg_492_pp0_it1 <= exitcond2_reg_492;
        ap_reg_ppstg_isIter0_reg_506_pp0_it1 <= isIter0_reg_506;
    end
end

/// assign process. ///
always @(posedge ap_clk)
begin
    if ((ap_ST_st12_fsm_11 == ap_CS_fsm)) begin
        delta_time_0_reg_398 <= grp_fu_275_p2;
    end
end

/// assign process. ///
always @(posedge ap_clk)
begin
    if (((ap_ST_pp0_stg0_fsm_50 == ap_CS_fsm) & (ap_const_logic_1 == ap_reg_ppiten_pp0_it0) & ~(ap_sig_bdd_179 & (ap_const_logic_1 == ap_reg_ppiten_pp0_it2)))) begin
        exitcond2_reg_492 <= exitcond2_fu_370_p2;
    end
end

/// assign process. ///
always @(posedge ap_clk)
begin
    if (((ap_ST_pp0_stg0_fsm_50 == ap_CS_fsm) & (ap_const_logic_1 == ap_reg_ppiten_pp0_it0) & ~(ap_sig_bdd_179 & (ap_const_logic_1 == ap_reg_ppiten_pp0_it2)) & (ap_const_lv1_0 == exitcond2_fu_370_p2))) begin
        isIter0_reg_506 <= isIter0_fu_387_p2;
    end
end

/// assign process. ///
always @(posedge ap_clk)
begin
    if ((ap_ST_st16_fsm_15 == ap_CS_fsm)) begin
        p_1_reg_447 <= p_1_fu_320_p2;
    end
end

/// assign process. ///
always @(posedge ap_clk)
begin
    if ((ap_ST_st24_fsm_23 == ap_CS_fsm)) begin
        pp_1_reg_471 <= pp_1_fu_351_p2;
        spot_price_0_reg_462 <= grp_fu_281_p1;
    end
end

/// assign process. ///
always @(posedge ap_clk)
begin
    if ((((ap_ST_st49_fsm_48 == ap_CS_fsm) & ~(tmp_7_reg_439 == ap_const_lv1_0)) | ((ap_ST_st49_fsm_48 == ap_CS_fsm) & (tmp_7_reg_439 == ap_const_lv1_0)))) begin
        reg_304 <= grp_fu_265_p2;
    end
end

/// assign process. ///
always @(posedge ap_clk)
begin
    if ((ap_ST_st21_fsm_20 == ap_CS_fsm)) begin
        spot_price_0_0_in_reg_457 <= grp_fu_294_p2;
    end
end

/// assign process. ///
always @(posedge ap_clk)
begin
    if (((ap_ST_pp0_stg0_fsm_50 == ap_CS_fsm) & (ap_const_logic_1 == ap_reg_ppiten_pp0_it1) & ~(ap_sig_bdd_179 & (ap_const_logic_1 == ap_reg_ppiten_pp0_it2)) & (ap_const_lv1_0 == exitcond2_reg_492))) begin
        thread_result_buff_load_reg_510 <= thread_result_buff_q0;
    end
end

/// assign process. ///
always @(posedge ap_clk)
begin
    if ((ap_ST_st30_fsm_29 == ap_CS_fsm)) begin
        tmp_4_reg_482 <= grp_fu_284_p1;
    end
end

/// assign process. ///
always @(posedge ap_clk)
begin
    if ((ap_ST_st15_fsm_14 == ap_CS_fsm)) begin
        tmp_7_reg_439 <= tmp_7_fu_308_p2;
        tmp_8_reg_429 <= grp_fu_284_p1;
        tmp_i_reg_434 <= grp_fu_270_p2;
    end
end

/// assign process. ///
always @(posedge ap_clk)
begin
    if ((ap_ST_st27_fsm_26 == ap_CS_fsm)) begin
        u_v_0_gamma_reg_476 <= grp_fu_265_p2;
    end
end

/// a_req_din assign process. ///
always @ (ap_CS_fsm or ap_reg_ppstg_exitcond2_reg_492_pp0_it1 or ap_sig_bdd_179 or ap_reg_ppiten_pp0_it2 or ap_reg_ppstg_isIter0_reg_506_pp0_it1)
begin
    if ((((ap_ST_pp0_stg0_fsm_50 == ap_CS_fsm) & (ap_const_lv1_0 == ap_reg_ppstg_exitcond2_reg_492_pp0_it1) & (ap_const_logic_1 == ap_reg_ppiten_pp0_it2) & ~(ap_sig_bdd_179 & (ap_const_logic_1 == ap_reg_ppiten_pp0_it2)) & ~(ap_const_lv1_0 == ap_reg_ppstg_isIter0_reg_506_pp0_it1)) | ((ap_ST_pp0_stg0_fsm_50 == ap_CS_fsm) & (ap_const_lv1_0 == ap_reg_ppstg_exitcond2_reg_492_pp0_it1) & (ap_const_logic_1 == ap_reg_ppiten_pp0_it2) & ~(ap_sig_bdd_179 & (ap_const_logic_1 == ap_reg_ppiten_pp0_it2))))) begin
        a_req_din = ap_const_logic_1;
    end else begin
        a_req_din = ap_const_logic_0;
    end
end

/// a_req_write assign process. ///
always @ (ap_CS_fsm or ap_reg_ppstg_exitcond2_reg_492_pp0_it1 or ap_sig_bdd_179 or ap_reg_ppiten_pp0_it2 or ap_reg_ppstg_isIter0_reg_506_pp0_it1)
begin
    if ((((ap_ST_pp0_stg0_fsm_50 == ap_CS_fsm) & (ap_const_lv1_0 == ap_reg_ppstg_exitcond2_reg_492_pp0_it1) & (ap_const_logic_1 == ap_reg_ppiten_pp0_it2) & ~(ap_sig_bdd_179 & (ap_const_logic_1 == ap_reg_ppiten_pp0_it2)) & ~(ap_const_lv1_0 == ap_reg_ppstg_isIter0_reg_506_pp0_it1)) | ((ap_ST_pp0_stg0_fsm_50 == ap_CS_fsm) & (ap_const_lv1_0 == ap_reg_ppstg_exitcond2_reg_492_pp0_it1) & (ap_const_logic_1 == ap_reg_ppiten_pp0_it2) & ~(ap_sig_bdd_179 & (ap_const_logic_1 == ap_reg_ppiten_pp0_it2))))) begin
        a_req_write = ap_const_logic_1;
    end else begin
        a_req_write = ap_const_logic_0;
    end
end

/// ap_done assign process. ///
always @ (ap_CS_fsm)
begin
    if ((ap_ST_st54_fsm_51 == ap_CS_fsm)) begin
        ap_done = ap_const_logic_1;
    end else begin
        ap_done = ap_const_logic_0;
    end
end

/// ap_idle assign process. ///
always @ (ap_start or ap_CS_fsm)
begin
    if ((~(ap_const_logic_1 == ap_start) & (ap_ST_st1_fsm_0 == ap_CS_fsm))) begin
        ap_idle = ap_const_logic_1;
    end else begin
        ap_idle = ap_const_logic_0;
    end
end

/// ap_ready assign process. ///
always @ (ap_CS_fsm)
begin
    if ((ap_ST_st54_fsm_51 == ap_CS_fsm)) begin
        ap_ready = ap_const_logic_1;
    end else begin
        ap_ready = ap_const_logic_0;
    end
end

/// grp_fu_265_opcode assign process. ///
always @ (ap_CS_fsm or tmp_7_reg_439 or exitcond_fu_345_p2)
begin
    if (((~(tmp_7_reg_439 == ap_const_lv1_0) & (ap_ST_st46_fsm_45 == ap_CS_fsm)) | ((tmp_7_reg_439 == ap_const_lv1_0) & (ap_ST_st46_fsm_45 == ap_CS_fsm)))) begin
        grp_fu_265_opcode = ap_const_lv2_1;
    end else if (((ap_ST_st24_fsm_23 == ap_CS_fsm) & (ap_const_lv1_0 == exitcond_fu_345_p2))) begin
        grp_fu_265_opcode = ap_const_lv2_0;
    end else begin
        grp_fu_265_opcode = 'bx;
    end
end

/// grp_fu_265_p0 assign process. ///
always @ (ap_CS_fsm or kernel_o_a_0_strike_price or tmp_7_reg_439 or tmp_i_reg_434 or spot_price_0_reg_462)
begin
    if (((tmp_7_reg_439 == ap_const_lv1_0) & (ap_ST_st46_fsm_45 == ap_CS_fsm))) begin
        grp_fu_265_p0 = kernel_o_a_0_strike_price;
    end else if ((~(tmp_7_reg_439 == ap_const_lv1_0) & (ap_ST_st46_fsm_45 == ap_CS_fsm))) begin
        grp_fu_265_p0 = spot_price_0_reg_462;
    end else if ((ap_ST_st24_fsm_23 == ap_CS_fsm)) begin
        grp_fu_265_p0 = tmp_i_reg_434;
    end else begin
        grp_fu_265_p0 = 'bx;
    end
end

/// grp_fu_265_p1 assign process. ///
always @ (ap_CS_fsm or kernel_o_a_0_strike_price or tmp_7_reg_439 or spot_price_0_reg_462 or u_v_gamma_read_assign_reg_230)
begin
    if (((tmp_7_reg_439 == ap_const_lv1_0) & (ap_ST_st46_fsm_45 == ap_CS_fsm))) begin
        grp_fu_265_p1 = spot_price_0_reg_462;
    end else if ((~(tmp_7_reg_439 == ap_const_lv1_0) & (ap_ST_st46_fsm_45 == ap_CS_fsm))) begin
        grp_fu_265_p1 = kernel_o_a_0_strike_price;
    end else if ((ap_ST_st24_fsm_23 == ap_CS_fsm)) begin
        grp_fu_265_p1 = u_v_gamma_read_assign_reg_230;
    end else begin
        grp_fu_265_p1 = 'bx;
    end
end

/// grp_fu_284_p0 assign process. ///
always @ (ap_CS_fsm or kernel_u_a_0_current_price or u_v_0_gamma_reg_476)
begin
    if ((ap_ST_st28_fsm_27 == ap_CS_fsm)) begin
        grp_fu_284_p0 = u_v_0_gamma_reg_476;
    end else if ((ap_ST_st13_fsm_12 == ap_CS_fsm)) begin
        grp_fu_284_p0 = kernel_u_a_0_current_price;
    end else begin
        grp_fu_284_p0 = 'bx;
    end
end

/// thread_result_buff_address0 assign process. ///
always @ (ap_CS_fsm or ap_reg_ppiten_pp0_it0 or tmp_2_fu_365_p1 or tmp_3_fu_382_p1)
begin
    if ((ap_ST_st50_fsm_49 == ap_CS_fsm)) begin
        thread_result_buff_address0 = tmp_2_fu_365_p1;
    end else if (((ap_ST_pp0_stg0_fsm_50 == ap_CS_fsm) & (ap_const_logic_1 == ap_reg_ppiten_pp0_it0))) begin
        thread_result_buff_address0 = tmp_3_fu_382_p1;
    end else begin
        thread_result_buff_address0 = 'bx;
    end
end

/// thread_result_buff_ce0 assign process. ///
always @ (ap_CS_fsm or ap_reg_ppiten_pp0_it0 or ap_sig_bdd_179 or ap_reg_ppiten_pp0_it2)
begin
    if ((((ap_ST_pp0_stg0_fsm_50 == ap_CS_fsm) & (ap_const_logic_1 == ap_reg_ppiten_pp0_it0) & ~(ap_sig_bdd_179 & (ap_const_logic_1 == ap_reg_ppiten_pp0_it2))) | (ap_ST_st50_fsm_49 == ap_CS_fsm))) begin
        thread_result_buff_ce0 = ap_const_logic_1;
    end else begin
        thread_result_buff_ce0 = ap_const_logic_0;
    end
end

/// thread_result_buff_we0 assign process. ///
always @ (ap_CS_fsm)
begin
    if ((ap_ST_st50_fsm_49 == ap_CS_fsm)) begin
        thread_result_buff_we0 = ap_const_logic_1;
    end else begin
        thread_result_buff_we0 = ap_const_logic_0;
    end
end
always @ (ap_start or ap_CS_fsm or exitcond1_fu_314_p2 or exitcond2_fu_370_p2 or ap_reg_ppiten_pp0_it0 or ap_reg_ppiten_pp0_it1 or ap_sig_bdd_179 or ap_reg_ppiten_pp0_it2 or exitcond_fu_345_p2)
begin
    case (ap_CS_fsm)
        ap_ST_st1_fsm_0 : 
            if (~(ap_start == ap_const_logic_0)) begin
                ap_NS_fsm = ap_ST_st2_fsm_1;
            end else begin
                ap_NS_fsm = ap_ST_st1_fsm_0;
            end
        ap_ST_st2_fsm_1 : 
            ap_NS_fsm = ap_ST_st3_fsm_2;
        ap_ST_st3_fsm_2 : 
            ap_NS_fsm = ap_ST_st4_fsm_3;
        ap_ST_st4_fsm_3 : 
            ap_NS_fsm = ap_ST_st5_fsm_4;
        ap_ST_st5_fsm_4 : 
            ap_NS_fsm = ap_ST_st6_fsm_5;
        ap_ST_st6_fsm_5 : 
            ap_NS_fsm = ap_ST_st7_fsm_6;
        ap_ST_st7_fsm_6 : 
            ap_NS_fsm = ap_ST_st8_fsm_7;
        ap_ST_st8_fsm_7 : 
            ap_NS_fsm = ap_ST_st9_fsm_8;
        ap_ST_st9_fsm_8 : 
            ap_NS_fsm = ap_ST_st10_fsm_9;
        ap_ST_st10_fsm_9 : 
            ap_NS_fsm = ap_ST_st11_fsm_10;
        ap_ST_st11_fsm_10 : 
            ap_NS_fsm = ap_ST_st12_fsm_11;
        ap_ST_st12_fsm_11 : 
            ap_NS_fsm = ap_ST_st13_fsm_12;
        ap_ST_st13_fsm_12 : 
            ap_NS_fsm = ap_ST_st14_fsm_13;
        ap_ST_st14_fsm_13 : 
            ap_NS_fsm = ap_ST_st15_fsm_14;
        ap_ST_st15_fsm_14 : 
            ap_NS_fsm = ap_ST_st16_fsm_15;
        ap_ST_st16_fsm_15 : 
            if (~(ap_const_lv1_0 == exitcond1_fu_314_p2)) begin
                ap_NS_fsm = ap_ST_pp0_stg0_fsm_50;
            end else begin
                ap_NS_fsm = ap_ST_st17_fsm_16;
            end
        ap_ST_st17_fsm_16 : 
            ap_NS_fsm = ap_ST_st18_fsm_17;
        ap_ST_st18_fsm_17 : 
            ap_NS_fsm = ap_ST_st19_fsm_18;
        ap_ST_st19_fsm_18 : 
            ap_NS_fsm = ap_ST_st20_fsm_19;
        ap_ST_st20_fsm_19 : 
            ap_NS_fsm = ap_ST_st21_fsm_20;
        ap_ST_st21_fsm_20 : 
            ap_NS_fsm = ap_ST_st22_fsm_21;
        ap_ST_st22_fsm_21 : 
            ap_NS_fsm = ap_ST_st23_fsm_22;
        ap_ST_st23_fsm_22 : 
            ap_NS_fsm = ap_ST_st24_fsm_23;
        ap_ST_st24_fsm_23 : 
            if (~(ap_const_lv1_0 == exitcond_fu_345_p2)) begin
                ap_NS_fsm = ap_ST_st46_fsm_45;
            end else begin
                ap_NS_fsm = ap_ST_st25_fsm_24;
            end
        ap_ST_st25_fsm_24 : 
            ap_NS_fsm = ap_ST_st26_fsm_25;
        ap_ST_st26_fsm_25 : 
            ap_NS_fsm = ap_ST_st27_fsm_26;
        ap_ST_st27_fsm_26 : 
            ap_NS_fsm = ap_ST_st28_fsm_27;
        ap_ST_st28_fsm_27 : 
            ap_NS_fsm = ap_ST_st29_fsm_28;
        ap_ST_st29_fsm_28 : 
            ap_NS_fsm = ap_ST_st30_fsm_29;
        ap_ST_st30_fsm_29 : 
            ap_NS_fsm = ap_ST_st31_fsm_30;
        ap_ST_st31_fsm_30 : 
            ap_NS_fsm = ap_ST_st32_fsm_31;
        ap_ST_st32_fsm_31 : 
            ap_NS_fsm = ap_ST_st33_fsm_32;
        ap_ST_st33_fsm_32 : 
            ap_NS_fsm = ap_ST_st34_fsm_33;
        ap_ST_st34_fsm_33 : 
            ap_NS_fsm = ap_ST_st35_fsm_34;
        ap_ST_st35_fsm_34 : 
            ap_NS_fsm = ap_ST_st36_fsm_35;
        ap_ST_st36_fsm_35 : 
            ap_NS_fsm = ap_ST_st37_fsm_36;
        ap_ST_st37_fsm_36 : 
            ap_NS_fsm = ap_ST_st38_fsm_37;
        ap_ST_st38_fsm_37 : 
            ap_NS_fsm = ap_ST_st39_fsm_38;
        ap_ST_st39_fsm_38 : 
            ap_NS_fsm = ap_ST_st40_fsm_39;
        ap_ST_st40_fsm_39 : 
            ap_NS_fsm = ap_ST_st41_fsm_40;
        ap_ST_st41_fsm_40 : 
            ap_NS_fsm = ap_ST_st42_fsm_41;
        ap_ST_st42_fsm_41 : 
            ap_NS_fsm = ap_ST_st43_fsm_42;
        ap_ST_st43_fsm_42 : 
            ap_NS_fsm = ap_ST_st44_fsm_43;
        ap_ST_st44_fsm_43 : 
            ap_NS_fsm = ap_ST_st45_fsm_44;
        ap_ST_st45_fsm_44 : 
            ap_NS_fsm = ap_ST_st17_fsm_16;
        ap_ST_st46_fsm_45 : 
            ap_NS_fsm = ap_ST_st47_fsm_46;
        ap_ST_st47_fsm_46 : 
            ap_NS_fsm = ap_ST_st48_fsm_47;
        ap_ST_st48_fsm_47 : 
            ap_NS_fsm = ap_ST_st49_fsm_48;
        ap_ST_st49_fsm_48 : 
            ap_NS_fsm = ap_ST_st50_fsm_49;
        ap_ST_st50_fsm_49 : 
            ap_NS_fsm = ap_ST_st16_fsm_15;
        ap_ST_pp0_stg0_fsm_50 : 
            if ((~((ap_ST_pp0_stg0_fsm_50 == ap_CS_fsm) & (ap_const_logic_1 == ap_reg_ppiten_pp0_it2) & ~(ap_sig_bdd_179 & (ap_const_logic_1 == ap_reg_ppiten_pp0_it2)) & ~(ap_const_logic_1 == ap_reg_ppiten_pp0_it1)) & ~((ap_const_logic_1 == ap_reg_ppiten_pp0_it0) & ~(ap_sig_bdd_179 & (ap_const_logic_1 == ap_reg_ppiten_pp0_it2)) & ~(ap_const_lv1_0 == exitcond2_fu_370_p2) & ~(ap_const_logic_1 == ap_reg_ppiten_pp0_it1)))) begin
                ap_NS_fsm = ap_ST_pp0_stg0_fsm_50;
            end else if ((((ap_ST_pp0_stg0_fsm_50 == ap_CS_fsm) & (ap_const_logic_1 == ap_reg_ppiten_pp0_it2) & ~(ap_sig_bdd_179 & (ap_const_logic_1 == ap_reg_ppiten_pp0_it2)) & ~(ap_const_logic_1 == ap_reg_ppiten_pp0_it1)) | ((ap_const_logic_1 == ap_reg_ppiten_pp0_it0) & ~(ap_sig_bdd_179 & (ap_const_logic_1 == ap_reg_ppiten_pp0_it2)) & ~(ap_const_lv1_0 == exitcond2_fu_370_p2) & ~(ap_const_logic_1 == ap_reg_ppiten_pp0_it1)))) begin
                ap_NS_fsm = ap_ST_st54_fsm_51;
            end else begin
                ap_NS_fsm = ap_ST_pp0_stg0_fsm_50;
            end
        ap_ST_st54_fsm_51 : 
            ap_NS_fsm = ap_ST_st1_fsm_0;
        default : 
            ap_NS_fsm = 'bx;
    endcase
end
assign a_address = a_addr_reg_452;
assign a_dataout = thread_result_buff_load_reg_510;
assign a_rsp_read = ap_const_logic_0;
assign a_size = ap_const_lv32_3E8;

/// ap_sig_bdd_179 assign process. ///
always @ (a_req_full_n or ap_reg_ppstg_exitcond2_reg_492_pp0_it1)
begin
    ap_sig_bdd_179 = ((a_req_full_n == ap_const_logic_0) & (ap_const_lv1_0 == ap_reg_ppstg_exitcond2_reg_492_pp0_it1));
end
assign exitcond1_fu_314_p2 = (p_reg_206 == ap_const_lv10_3E8? 1'b1: 1'b0);
assign exitcond2_fu_370_p2 = (indvar_reg_253 == ap_const_lv10_3E8? 1'b1: 1'b0);
assign exitcond_fu_345_p2 = (pp_reg_242 == ap_const_lv4_A? 1'b1: 1'b0);
assign grp_fu_265_ce = ap_const_logic_1;
assign grp_fu_270_ce = ap_const_logic_1;
assign grp_fu_270_p0 = kernel_u_a_0_rfir;
assign grp_fu_270_p1 = delta_time_0_reg_398;
assign grp_fu_275_ce = ap_const_logic_1;
assign grp_fu_275_p0 = kernel_o_a_0_time_period;
assign grp_fu_275_p1 = ap_const_lv32_41200000;
assign grp_fu_281_ce = ap_const_logic_1;
assign grp_fu_281_p0 = spot_price_0_0_in_reg_457;
assign grp_fu_284_ce = ap_const_logic_1;
assign grp_fu_288_ce = ap_const_logic_1;
assign grp_fu_288_opcode = ap_const_lv5_1;
assign grp_fu_288_p0 = kernel_o_a_0_call;
assign grp_fu_288_p1 = ap_const_lv32_0;
assign grp_fu_294_ce = ap_const_logic_1;
assign grp_fu_294_p0 = tmp_8_reg_429;
assign grp_fu_294_p1 = tmp_pn_reg_218;
assign grp_fu_299_ce = ap_const_logic_1;
assign grp_fu_299_p0 = ap_const_lv64_1;
assign grp_fu_299_p1 = tmp_4_reg_482;
assign indvar_next_fu_376_p2 = (indvar_reg_253 + ap_const_lv10_1);
assign isIter0_fu_387_p2 = (indvar_reg_253 == ap_const_lv10_0? 1'b1: 1'b0);
assign p_1_fu_320_p2 = (p_reg_206 + ap_const_lv10_1);
assign pp_1_fu_351_p2 = (pp_reg_242 + ap_const_lv4_1);
assign thread_result_buff_d0 = ((tmp_7_reg_439)? reg_304: reg_304);
assign tmp_2_fu_365_p1 = $unsigned(p_reg_206);
assign tmp_3_fu_382_p1 = $unsigned(indvar_reg_253);
assign tmp_5_fu_335_p1 = $unsigned(tmp_fu_326_p4);
assign tmp_7_fu_308_p2 = (grp_fu_288_p2 ^ ap_const_lv1_1);
assign tmp_fu_326_p4 = {{thread_result_0[ap_const_lv32_1F : ap_const_lv32_2]}};
always @ (posedge ap_clk)
begin
    a_addr_reg_452[31:30] <= 2'b00;
end



endmodule //vivado_activity_thread

