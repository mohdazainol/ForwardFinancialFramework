// ==============================================================
// RTL generated by Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC
// Version: 2013.4
// Copyright (C) 2013 Xilinx Inc. All rights reserved.
// 
// ===========================================================

#include "vivado_activity_thread.h"
#include "AESL_pkg.h"

using namespace std;

namespace ap_rtl {

const sc_logic vivado_activity_thread::ap_const_logic_1 = sc_dt::Log_1;
const sc_logic vivado_activity_thread::ap_const_logic_0 = sc_dt::Log_0;
const sc_lv<6> vivado_activity_thread::ap_ST_st1_fsm_0 = "000000";
const sc_lv<6> vivado_activity_thread::ap_ST_st2_fsm_1 = "1";
const sc_lv<6> vivado_activity_thread::ap_ST_st3_fsm_2 = "10";
const sc_lv<6> vivado_activity_thread::ap_ST_st4_fsm_3 = "11";
const sc_lv<6> vivado_activity_thread::ap_ST_st5_fsm_4 = "100";
const sc_lv<6> vivado_activity_thread::ap_ST_st6_fsm_5 = "101";
const sc_lv<6> vivado_activity_thread::ap_ST_st7_fsm_6 = "110";
const sc_lv<6> vivado_activity_thread::ap_ST_st8_fsm_7 = "111";
const sc_lv<6> vivado_activity_thread::ap_ST_st9_fsm_8 = "1000";
const sc_lv<6> vivado_activity_thread::ap_ST_st10_fsm_9 = "1001";
const sc_lv<6> vivado_activity_thread::ap_ST_st11_fsm_10 = "1010";
const sc_lv<6> vivado_activity_thread::ap_ST_st12_fsm_11 = "1011";
const sc_lv<6> vivado_activity_thread::ap_ST_st13_fsm_12 = "1100";
const sc_lv<6> vivado_activity_thread::ap_ST_st14_fsm_13 = "1101";
const sc_lv<6> vivado_activity_thread::ap_ST_st15_fsm_14 = "1110";
const sc_lv<6> vivado_activity_thread::ap_ST_st16_fsm_15 = "1111";
const sc_lv<6> vivado_activity_thread::ap_ST_st17_fsm_16 = "10000";
const sc_lv<6> vivado_activity_thread::ap_ST_st18_fsm_17 = "10001";
const sc_lv<6> vivado_activity_thread::ap_ST_st19_fsm_18 = "10010";
const sc_lv<6> vivado_activity_thread::ap_ST_st20_fsm_19 = "10011";
const sc_lv<6> vivado_activity_thread::ap_ST_st21_fsm_20 = "10100";
const sc_lv<6> vivado_activity_thread::ap_ST_st22_fsm_21 = "10101";
const sc_lv<6> vivado_activity_thread::ap_ST_st23_fsm_22 = "10110";
const sc_lv<6> vivado_activity_thread::ap_ST_st24_fsm_23 = "10111";
const sc_lv<6> vivado_activity_thread::ap_ST_st25_fsm_24 = "11000";
const sc_lv<6> vivado_activity_thread::ap_ST_st26_fsm_25 = "11001";
const sc_lv<6> vivado_activity_thread::ap_ST_st27_fsm_26 = "11010";
const sc_lv<6> vivado_activity_thread::ap_ST_st28_fsm_27 = "11011";
const sc_lv<6> vivado_activity_thread::ap_ST_st29_fsm_28 = "11100";
const sc_lv<6> vivado_activity_thread::ap_ST_st30_fsm_29 = "11101";
const sc_lv<6> vivado_activity_thread::ap_ST_st31_fsm_30 = "11110";
const sc_lv<6> vivado_activity_thread::ap_ST_st32_fsm_31 = "11111";
const sc_lv<6> vivado_activity_thread::ap_ST_st33_fsm_32 = "100000";
const sc_lv<6> vivado_activity_thread::ap_ST_st34_fsm_33 = "100001";
const sc_lv<6> vivado_activity_thread::ap_ST_st35_fsm_34 = "100010";
const sc_lv<6> vivado_activity_thread::ap_ST_st36_fsm_35 = "100011";
const sc_lv<6> vivado_activity_thread::ap_ST_st37_fsm_36 = "100100";
const sc_lv<6> vivado_activity_thread::ap_ST_st38_fsm_37 = "100101";
const sc_lv<6> vivado_activity_thread::ap_ST_st39_fsm_38 = "100110";
const sc_lv<6> vivado_activity_thread::ap_ST_st40_fsm_39 = "100111";
const sc_lv<6> vivado_activity_thread::ap_ST_st41_fsm_40 = "101000";
const sc_lv<6> vivado_activity_thread::ap_ST_st42_fsm_41 = "101001";
const sc_lv<6> vivado_activity_thread::ap_ST_st43_fsm_42 = "101010";
const sc_lv<6> vivado_activity_thread::ap_ST_st44_fsm_43 = "101011";
const sc_lv<6> vivado_activity_thread::ap_ST_st45_fsm_44 = "101100";
const sc_lv<6> vivado_activity_thread::ap_ST_st46_fsm_45 = "101101";
const sc_lv<6> vivado_activity_thread::ap_ST_st47_fsm_46 = "101110";
const sc_lv<6> vivado_activity_thread::ap_ST_st48_fsm_47 = "101111";
const sc_lv<32> vivado_activity_thread::ap_const_lv32_3F800000 = "111111100000000000000000000000";
const sc_lv<32> vivado_activity_thread::ap_const_lv32_0 = "00000000000000000000000000000000";
const sc_lv<4> vivado_activity_thread::ap_const_lv4_0 = "0000";
const sc_lv<1> vivado_activity_thread::ap_const_lv1_0 = "0";
const sc_lv<32> vivado_activity_thread::ap_const_lv32_41200000 = "1000001001000000000000000000000";
const sc_lv<4> vivado_activity_thread::ap_const_lv4_A = "1010";
const sc_lv<4> vivado_activity_thread::ap_const_lv4_1 = "1";
const sc_lv<1> vivado_activity_thread::ap_const_lv1_1 = "1";
const sc_lv<2> vivado_activity_thread::ap_const_lv2_0 = "00";
const sc_lv<2> vivado_activity_thread::ap_const_lv2_1 = "1";
const sc_lv<5> vivado_activity_thread::ap_const_lv5_1 = "1";
const sc_lv<32> vivado_activity_thread::ap_const_lv32_1 = "1";

vivado_activity_thread::vivado_activity_thread(sc_module_name name) : sc_module(name), mVcdFile(0) {
    vivado_activity_thread_faddfsub_32ns_32ns_32_5_full_dsp_U1 = new vivado_activity_thread_faddfsub_32ns_32ns_32_5_full_dsp<1,5,32,32,32>("vivado_activity_thread_faddfsub_32ns_32ns_32_5_full_dsp_U1");
    vivado_activity_thread_faddfsub_32ns_32ns_32_5_full_dsp_U1->clk(ap_clk);
    vivado_activity_thread_faddfsub_32ns_32ns_32_5_full_dsp_U1->reset(ap_rst);
    vivado_activity_thread_faddfsub_32ns_32ns_32_5_full_dsp_U1->din0(grp_fu_182_p0);
    vivado_activity_thread_faddfsub_32ns_32ns_32_5_full_dsp_U1->din1(grp_fu_182_p1);
    vivado_activity_thread_faddfsub_32ns_32ns_32_5_full_dsp_U1->opcode(grp_fu_182_opcode);
    vivado_activity_thread_faddfsub_32ns_32ns_32_5_full_dsp_U1->ce(grp_fu_182_ce);
    vivado_activity_thread_faddfsub_32ns_32ns_32_5_full_dsp_U1->dout(grp_fu_182_p2);
    vivado_activity_thread_fmul_32ns_32ns_32_4_max_dsp_U2 = new vivado_activity_thread_fmul_32ns_32ns_32_4_max_dsp<2,4,32,32,32>("vivado_activity_thread_fmul_32ns_32ns_32_4_max_dsp_U2");
    vivado_activity_thread_fmul_32ns_32ns_32_4_max_dsp_U2->clk(ap_clk);
    vivado_activity_thread_fmul_32ns_32ns_32_4_max_dsp_U2->reset(ap_rst);
    vivado_activity_thread_fmul_32ns_32ns_32_4_max_dsp_U2->din0(grp_fu_187_p0);
    vivado_activity_thread_fmul_32ns_32ns_32_4_max_dsp_U2->din1(grp_fu_187_p1);
    vivado_activity_thread_fmul_32ns_32ns_32_4_max_dsp_U2->ce(grp_fu_187_ce);
    vivado_activity_thread_fmul_32ns_32ns_32_4_max_dsp_U2->dout(grp_fu_187_p2);
    vivado_activity_thread_fdiv_32ns_32ns_32_16_U3 = new vivado_activity_thread_fdiv_32ns_32ns_32_16<3,16,32,32,32>("vivado_activity_thread_fdiv_32ns_32ns_32_16_U3");
    vivado_activity_thread_fdiv_32ns_32ns_32_16_U3->clk(ap_clk);
    vivado_activity_thread_fdiv_32ns_32ns_32_16_U3->reset(ap_rst);
    vivado_activity_thread_fdiv_32ns_32ns_32_16_U3->din0(grp_fu_194_p0);
    vivado_activity_thread_fdiv_32ns_32ns_32_16_U3->din1(grp_fu_194_p1);
    vivado_activity_thread_fdiv_32ns_32ns_32_16_U3->ce(grp_fu_194_ce);
    vivado_activity_thread_fdiv_32ns_32ns_32_16_U3->dout(grp_fu_194_p2);
    vivado_activity_thread_fcmp_32ns_32ns_1_3_U4 = new vivado_activity_thread_fcmp_32ns_32ns_1_3<4,3,32,32,1>("vivado_activity_thread_fcmp_32ns_32ns_1_3_U4");
    vivado_activity_thread_fcmp_32ns_32ns_1_3_U4->clk(ap_clk);
    vivado_activity_thread_fcmp_32ns_32ns_1_3_U4->reset(ap_rst);
    vivado_activity_thread_fcmp_32ns_32ns_1_3_U4->din0(grp_fu_200_p0);
    vivado_activity_thread_fcmp_32ns_32ns_1_3_U4->din1(grp_fu_200_p1);
    vivado_activity_thread_fcmp_32ns_32ns_1_3_U4->ce(grp_fu_200_ce);
    vivado_activity_thread_fcmp_32ns_32ns_1_3_U4->opcode(grp_fu_200_opcode);
    vivado_activity_thread_fcmp_32ns_32ns_1_3_U4->dout(grp_fu_200_p2);
    vivado_activity_thread_fexp_32ns_32ns_32_9_full_dsp_U5 = new vivado_activity_thread_fexp_32ns_32ns_32_9_full_dsp<5,9,32,32,32>("vivado_activity_thread_fexp_32ns_32ns_32_9_full_dsp_U5");
    vivado_activity_thread_fexp_32ns_32ns_32_9_full_dsp_U5->clk(ap_clk);
    vivado_activity_thread_fexp_32ns_32ns_32_9_full_dsp_U5->reset(ap_rst);
    vivado_activity_thread_fexp_32ns_32ns_32_9_full_dsp_U5->din0(grp_fu_205_p0);
    vivado_activity_thread_fexp_32ns_32ns_32_9_full_dsp_U5->din1(grp_fu_205_p1);
    vivado_activity_thread_fexp_32ns_32ns_32_9_full_dsp_U5->ce(grp_fu_205_ce);
    vivado_activity_thread_fexp_32ns_32ns_32_9_full_dsp_U5->dout(grp_fu_205_p2);

    SC_METHOD(thread_ap_clk_no_reset_);
    dont_initialize();
    sensitive << ( ap_clk.pos() );

    SC_METHOD(thread_ap_done);
    sensitive << ( ap_CS_fsm );

    SC_METHOD(thread_ap_idle);
    sensitive << ( ap_start );
    sensitive << ( ap_CS_fsm );

    SC_METHOD(thread_ap_ready);
    sensitive << ( ap_CS_fsm );

    SC_METHOD(thread_exitcond_fu_216_p2);
    sensitive << ( ap_CS_fsm );
    sensitive << ( pp_reg_170 );

    SC_METHOD(thread_grp_fu_182_ce);

    SC_METHOD(thread_grp_fu_182_opcode);
    sensitive << ( ap_CS_fsm );
    sensitive << ( tmp_2_reg_291 );
    sensitive << ( exitcond_fu_216_p2 );

    SC_METHOD(thread_grp_fu_182_p0);
    sensitive << ( ap_CS_fsm );
    sensitive << ( kernel_o_a_0_strike_price );
    sensitive << ( reg_210 );
    sensitive << ( tmp_2_reg_291 );

    SC_METHOD(thread_grp_fu_182_p1);
    sensitive << ( ap_CS_fsm );
    sensitive << ( kernel_o_a_0_strike_price );
    sensitive << ( reg_210 );
    sensitive << ( tmp_2_reg_291 );
    sensitive << ( u_v_gamma_read_assign_reg_158 );

    SC_METHOD(thread_grp_fu_187_ce);

    SC_METHOD(thread_grp_fu_187_p0);
    sensitive << ( ap_CS_fsm );
    sensitive << ( kernel_u_a_0_rfir );
    sensitive << ( kernel_u_a_0_current_price );
    sensitive << ( temp_value_reg_296 );

    SC_METHOD(thread_grp_fu_187_p1);
    sensitive << ( ap_CS_fsm );
    sensitive << ( delta_time_0_reg_246 );
    sensitive << ( temp_value_reg_296 );
    sensitive << ( tmp_pn_reg_146 );

    SC_METHOD(thread_grp_fu_194_ce);

    SC_METHOD(thread_grp_fu_194_p0);
    sensitive << ( ap_CS_fsm );
    sensitive << ( kernel_o_a_0_time_period );

    SC_METHOD(thread_grp_fu_194_p1);
    sensitive << ( ap_CS_fsm );

    SC_METHOD(thread_grp_fu_200_ce);

    SC_METHOD(thread_grp_fu_200_opcode);
    sensitive << ( ap_CS_fsm );
    sensitive << ( exitcond_fu_216_p2 );

    SC_METHOD(thread_grp_fu_200_p0);
    sensitive << ( ap_CS_fsm );
    sensitive << ( kernel_o_a_0_call );

    SC_METHOD(thread_grp_fu_200_p1);
    sensitive << ( ap_CS_fsm );

    SC_METHOD(thread_grp_fu_205_ce);

    SC_METHOD(thread_grp_fu_205_p0);

    SC_METHOD(thread_grp_fu_205_p1);
    sensitive << ( ap_CS_fsm );
    sensitive << ( u_v_0_gamma_reg_280 );

    SC_METHOD(thread_pp_1_fu_222_p2);
    sensitive << ( pp_reg_170 );

    SC_METHOD(thread_temp_value_fu_234_p3);
    sensitive << ( grp_fu_182_p2 );
    sensitive << ( tmp_2_reg_291 );

    SC_METHOD(thread_thread_result_0);
    sensitive << ( ap_CS_fsm );
    sensitive << ( temp_value_reg_296 );

    SC_METHOD(thread_thread_result_0_ap_vld);
    sensitive << ( ap_CS_fsm );

    SC_METHOD(thread_thread_result_sqrd_0);
    sensitive << ( ap_CS_fsm );
    sensitive << ( grp_fu_187_p2 );

    SC_METHOD(thread_thread_result_sqrd_0_ap_vld);
    sensitive << ( ap_CS_fsm );

    SC_METHOD(thread_tmp_2_fu_228_p2);
    sensitive << ( grp_fu_200_p2 );

    SC_METHOD(thread_ap_NS_fsm);
    sensitive << ( ap_start );
    sensitive << ( ap_CS_fsm );
    sensitive << ( exitcond_fu_216_p2 );

    SC_THREAD(thread_hdltv_gen);
    sensitive << ( ap_clk.pos() );

    ap_CS_fsm = "000000";
    static int apTFileNum = 0;
    stringstream apTFilenSS;
    apTFilenSS << "vivado_activity_thread_sc_trace_" << apTFileNum ++;
    string apTFn = apTFilenSS.str();
    mVcdFile = sc_create_vcd_trace_file(apTFn.c_str());
    mVcdFile->set_time_unit(1, SC_PS);
    if (1) {
#ifdef __HLS_TRACE_LEVEL_PORT__
    sc_trace(mVcdFile, ap_clk, "(port)ap_clk");
    sc_trace(mVcdFile, ap_rst, "(port)ap_rst");
    sc_trace(mVcdFile, ap_start, "(port)ap_start");
    sc_trace(mVcdFile, ap_done, "(port)ap_done");
    sc_trace(mVcdFile, ap_idle, "(port)ap_idle");
    sc_trace(mVcdFile, ap_ready, "(port)ap_ready");
    sc_trace(mVcdFile, kernel_u_a_0_rfir, "(port)kernel_u_a_0_rfir");
    sc_trace(mVcdFile, kernel_u_a_0_current_price, "(port)kernel_u_a_0_current_price");
    sc_trace(mVcdFile, kernel_u_a_0_volatility, "(port)kernel_u_a_0_volatility");
    sc_trace(mVcdFile, kernel_u_a_0_initial_volatility, "(port)kernel_u_a_0_initial_volatility");
    sc_trace(mVcdFile, kernel_u_a_0_volatility_volatility, "(port)kernel_u_a_0_volatility_volatility");
    sc_trace(mVcdFile, kernel_u_a_0_rho, "(port)kernel_u_a_0_rho");
    sc_trace(mVcdFile, kernel_u_a_0_kappa, "(port)kernel_u_a_0_kappa");
    sc_trace(mVcdFile, kernel_u_a_0_theta, "(port)kernel_u_a_0_theta");
    sc_trace(mVcdFile, kernel_u_a_0_correlation_matrix_0_0, "(port)kernel_u_a_0_correlation_matrix_0_0");
    sc_trace(mVcdFile, kernel_u_a_0_correlation_matrix_0_1, "(port)kernel_u_a_0_correlation_matrix_0_1");
    sc_trace(mVcdFile, kernel_u_a_0_correlation_matrix_1_0, "(port)kernel_u_a_0_correlation_matrix_1_0");
    sc_trace(mVcdFile, kernel_u_a_0_correlation_matrix_1_1, "(port)kernel_u_a_0_correlation_matrix_1_1");
    sc_trace(mVcdFile, kernel_o_a_0_second_barrier, "(port)kernel_o_a_0_second_barrier");
    sc_trace(mVcdFile, kernel_o_a_0_barrier, "(port)kernel_o_a_0_barrier");
    sc_trace(mVcdFile, kernel_o_a_0_out, "(port)kernel_o_a_0_out");
    sc_trace(mVcdFile, kernel_o_a_0_down, "(port)kernel_o_a_0_down");
    sc_trace(mVcdFile, kernel_o_a_0_strike_price, "(port)kernel_o_a_0_strike_price");
    sc_trace(mVcdFile, kernel_o_a_0_time_period, "(port)kernel_o_a_0_time_period");
    sc_trace(mVcdFile, kernel_o_a_0_call, "(port)kernel_o_a_0_call");
    sc_trace(mVcdFile, kernel_o_a_0_points, "(port)kernel_o_a_0_points");
    sc_trace(mVcdFile, seed_0_s1, "(port)seed_0_s1");
    sc_trace(mVcdFile, seed_0_s2, "(port)seed_0_s2");
    sc_trace(mVcdFile, seed_0_s3, "(port)seed_0_s3");
    sc_trace(mVcdFile, seed_0_offset, "(port)seed_0_offset");
    sc_trace(mVcdFile, thread_result_0, "(port)thread_result_0");
    sc_trace(mVcdFile, thread_result_0_ap_vld, "(port)thread_result_0_ap_vld");
    sc_trace(mVcdFile, thread_result_sqrd_0, "(port)thread_result_sqrd_0");
    sc_trace(mVcdFile, thread_result_sqrd_0_ap_vld, "(port)thread_result_sqrd_0_ap_vld");
#endif
#ifdef __HLS_TRACE_LEVEL_INT__
    sc_trace(mVcdFile, ap_CS_fsm, "ap_CS_fsm");
    sc_trace(mVcdFile, grp_fu_187_p2, "grp_fu_187_p2");
    sc_trace(mVcdFile, reg_210, "reg_210");
    sc_trace(mVcdFile, grp_fu_194_p2, "grp_fu_194_p2");
    sc_trace(mVcdFile, delta_time_0_reg_246, "delta_time_0_reg_246");
    sc_trace(mVcdFile, pp_1_fu_222_p2, "pp_1_fu_222_p2");
    sc_trace(mVcdFile, pp_1_reg_275, "pp_1_reg_275");
    sc_trace(mVcdFile, grp_fu_182_p2, "grp_fu_182_p2");
    sc_trace(mVcdFile, u_v_0_gamma_reg_280, "u_v_0_gamma_reg_280");
    sc_trace(mVcdFile, grp_fu_205_p2, "grp_fu_205_p2");
    sc_trace(mVcdFile, tmp_2_fu_228_p2, "tmp_2_fu_228_p2");
    sc_trace(mVcdFile, tmp_2_reg_291, "tmp_2_reg_291");
    sc_trace(mVcdFile, temp_value_fu_234_p3, "temp_value_fu_234_p3");
    sc_trace(mVcdFile, temp_value_reg_296, "temp_value_reg_296");
    sc_trace(mVcdFile, tmp_pn_reg_146, "tmp_pn_reg_146");
    sc_trace(mVcdFile, u_v_gamma_read_assign_reg_158, "u_v_gamma_read_assign_reg_158");
    sc_trace(mVcdFile, pp_reg_170, "pp_reg_170");
    sc_trace(mVcdFile, grp_fu_182_p0, "grp_fu_182_p0");
    sc_trace(mVcdFile, grp_fu_182_p1, "grp_fu_182_p1");
    sc_trace(mVcdFile, grp_fu_187_p0, "grp_fu_187_p0");
    sc_trace(mVcdFile, grp_fu_187_p1, "grp_fu_187_p1");
    sc_trace(mVcdFile, grp_fu_194_p0, "grp_fu_194_p0");
    sc_trace(mVcdFile, grp_fu_194_p1, "grp_fu_194_p1");
    sc_trace(mVcdFile, grp_fu_200_p0, "grp_fu_200_p0");
    sc_trace(mVcdFile, grp_fu_200_p1, "grp_fu_200_p1");
    sc_trace(mVcdFile, grp_fu_205_p1, "grp_fu_205_p1");
    sc_trace(mVcdFile, grp_fu_200_p2, "grp_fu_200_p2");
    sc_trace(mVcdFile, grp_fu_182_opcode, "grp_fu_182_opcode");
    sc_trace(mVcdFile, exitcond_fu_216_p2, "exitcond_fu_216_p2");
    sc_trace(mVcdFile, grp_fu_182_ce, "grp_fu_182_ce");
    sc_trace(mVcdFile, grp_fu_187_ce, "grp_fu_187_ce");
    sc_trace(mVcdFile, grp_fu_194_ce, "grp_fu_194_ce");
    sc_trace(mVcdFile, grp_fu_200_ce, "grp_fu_200_ce");
    sc_trace(mVcdFile, grp_fu_200_opcode, "grp_fu_200_opcode");
    sc_trace(mVcdFile, grp_fu_205_p0, "grp_fu_205_p0");
    sc_trace(mVcdFile, grp_fu_205_ce, "grp_fu_205_ce");
    sc_trace(mVcdFile, ap_NS_fsm, "ap_NS_fsm");
#endif

    }
    mHdltvinHandle.open("vivado_activity_thread.hdltvin.dat");
    mHdltvoutHandle.open("vivado_activity_thread.hdltvout.dat");
}

vivado_activity_thread::~vivado_activity_thread() {
    if (mVcdFile) 
        sc_close_vcd_trace_file(mVcdFile);

    mHdltvinHandle << "] " << endl;
    mHdltvoutHandle << "] " << endl;
    mHdltvinHandle.close();
    mHdltvoutHandle.close();
    delete vivado_activity_thread_faddfsub_32ns_32ns_32_5_full_dsp_U1;
    delete vivado_activity_thread_fmul_32ns_32ns_32_4_max_dsp_U2;
    delete vivado_activity_thread_fdiv_32ns_32ns_32_16_U3;
    delete vivado_activity_thread_fcmp_32ns_32ns_1_3_U4;
    delete vivado_activity_thread_fexp_32ns_32ns_32_9_full_dsp_U5;
}

void vivado_activity_thread::thread_ap_clk_no_reset_() {
    if ( ap_rst.read() == ap_const_logic_1) {
        ap_CS_fsm = ap_ST_st1_fsm_0;
    } else {
        ap_CS_fsm = ap_NS_fsm.read();
    }
    if (esl_seteq<1,6,6>(ap_ST_st37_fsm_36, ap_CS_fsm.read())) {
        pp_reg_170 = pp_1_reg_275.read();
    } else if (esl_seteq<1,6,6>(ap_ST_st20_fsm_19, ap_CS_fsm.read())) {
        pp_reg_170 = ap_const_lv4_0;
    }
    if (esl_seteq<1,6,6>(ap_ST_st37_fsm_36, ap_CS_fsm.read())) {
        tmp_pn_reg_146 = grp_fu_205_p2.read();
    } else if (esl_seteq<1,6,6>(ap_ST_st20_fsm_19, ap_CS_fsm.read())) {
        tmp_pn_reg_146 = ap_const_lv32_3F800000;
    }
    if (esl_seteq<1,6,6>(ap_ST_st37_fsm_36, ap_CS_fsm.read())) {
        u_v_gamma_read_assign_reg_158 = u_v_0_gamma_reg_280.read();
    } else if (esl_seteq<1,6,6>(ap_ST_st20_fsm_19, ap_CS_fsm.read())) {
        u_v_gamma_read_assign_reg_158 = ap_const_lv32_0;
    }
    if (esl_seteq<1,6,6>(ap_ST_st16_fsm_15, ap_CS_fsm.read())) {
        delta_time_0_reg_246 = grp_fu_194_p2.read();
    }
    if (esl_seteq<1,6,6>(ap_ST_st24_fsm_23, ap_CS_fsm.read())) {
        pp_1_reg_275 = pp_1_fu_222_p2.read();
    }
    if ((esl_seteq<1,6,6>(ap_ST_st20_fsm_19, ap_CS_fsm.read()) || esl_seteq<1,6,6>(ap_ST_st24_fsm_23, ap_CS_fsm.read()))) {
        reg_210 = grp_fu_187_p2.read();
    }
    if (esl_seteq<1,6,6>(ap_ST_st44_fsm_43, ap_CS_fsm.read())) {
        temp_value_reg_296 = temp_value_fu_234_p3.read();
    }
    if (esl_seteq<1,6,6>(ap_ST_st39_fsm_38, ap_CS_fsm.read())) {
        tmp_2_reg_291 = tmp_2_fu_228_p2.read();
    }
    if (esl_seteq<1,6,6>(ap_ST_st28_fsm_27, ap_CS_fsm.read())) {
        u_v_0_gamma_reg_280 = grp_fu_182_p2.read();
    }
}

void vivado_activity_thread::thread_ap_done() {
    if (esl_seteq<1,6,6>(ap_ST_st48_fsm_47, ap_CS_fsm.read())) {
        ap_done = ap_const_logic_1;
    } else {
        ap_done = ap_const_logic_0;
    }
}

void vivado_activity_thread::thread_ap_idle() {
    if ((!esl_seteq<1,1,1>(ap_const_logic_1, ap_start.read()) && 
         esl_seteq<1,6,6>(ap_ST_st1_fsm_0, ap_CS_fsm.read()))) {
        ap_idle = ap_const_logic_1;
    } else {
        ap_idle = ap_const_logic_0;
    }
}

void vivado_activity_thread::thread_ap_ready() {
    if (esl_seteq<1,6,6>(ap_ST_st48_fsm_47, ap_CS_fsm.read())) {
        ap_ready = ap_const_logic_1;
    } else {
        ap_ready = ap_const_logic_0;
    }
}

void vivado_activity_thread::thread_exitcond_fu_216_p2() {
    exitcond_fu_216_p2 = (!pp_reg_170.read().is_01() || !ap_const_lv4_A.is_01())? sc_lv<1>(): sc_lv<1>(pp_reg_170.read() == ap_const_lv4_A);
}

void vivado_activity_thread::thread_grp_fu_182_ce() {
    grp_fu_182_ce = ap_const_logic_1;
}

void vivado_activity_thread::thread_grp_fu_182_opcode() {
    if (((esl_seteq<1,6,6>(ap_ST_st40_fsm_39, ap_CS_fsm.read()) && 
          !esl_seteq<1,1,1>(tmp_2_reg_291.read(), ap_const_lv1_0)) || 
         (esl_seteq<1,6,6>(ap_ST_st40_fsm_39, ap_CS_fsm.read()) && 
          esl_seteq<1,1,1>(tmp_2_reg_291.read(), ap_const_lv1_0)))) {
        grp_fu_182_opcode = ap_const_lv2_1;
    } else if ((esl_seteq<1,6,6>(ap_ST_st24_fsm_23, ap_CS_fsm.read()) && 
                esl_seteq<1,1,1>(ap_const_lv1_0, exitcond_fu_216_p2.read()))) {
        grp_fu_182_opcode = ap_const_lv2_0;
    } else {
        grp_fu_182_opcode =  (sc_lv<2>) ("XX");
    }
}

void vivado_activity_thread::thread_grp_fu_182_p0() {
    if ((esl_seteq<1,6,6>(ap_ST_st40_fsm_39, ap_CS_fsm.read()) && 
         esl_seteq<1,1,1>(tmp_2_reg_291.read(), ap_const_lv1_0))) {
        grp_fu_182_p0 = kernel_o_a_0_strike_price.read();
    } else if ((esl_seteq<1,6,6>(ap_ST_st24_fsm_23, ap_CS_fsm.read()) || 
                (esl_seteq<1,6,6>(ap_ST_st40_fsm_39, ap_CS_fsm.read()) && 
                 !esl_seteq<1,1,1>(tmp_2_reg_291.read(), ap_const_lv1_0)))) {
        grp_fu_182_p0 = reg_210.read();
    } else {
        grp_fu_182_p0 = "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX";
    }
}

void vivado_activity_thread::thread_grp_fu_182_p1() {
    if ((esl_seteq<1,6,6>(ap_ST_st40_fsm_39, ap_CS_fsm.read()) && 
         esl_seteq<1,1,1>(tmp_2_reg_291.read(), ap_const_lv1_0))) {
        grp_fu_182_p1 = reg_210.read();
    } else if ((esl_seteq<1,6,6>(ap_ST_st40_fsm_39, ap_CS_fsm.read()) && 
                !esl_seteq<1,1,1>(tmp_2_reg_291.read(), ap_const_lv1_0))) {
        grp_fu_182_p1 = kernel_o_a_0_strike_price.read();
    } else if (esl_seteq<1,6,6>(ap_ST_st24_fsm_23, ap_CS_fsm.read())) {
        grp_fu_182_p1 = u_v_gamma_read_assign_reg_158.read();
    } else {
        grp_fu_182_p1 = "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX";
    }
}

void vivado_activity_thread::thread_grp_fu_187_ce() {
    grp_fu_187_ce = ap_const_logic_1;
}

void vivado_activity_thread::thread_grp_fu_187_p0() {
    if (esl_seteq<1,6,6>(ap_ST_st45_fsm_44, ap_CS_fsm.read())) {
        grp_fu_187_p0 = temp_value_reg_296.read();
    } else if (esl_seteq<1,6,6>(ap_ST_st21_fsm_20, ap_CS_fsm.read())) {
        grp_fu_187_p0 = kernel_u_a_0_current_price.read();
    } else if (esl_seteq<1,6,6>(ap_ST_st17_fsm_16, ap_CS_fsm.read())) {
        grp_fu_187_p0 = kernel_u_a_0_rfir.read();
    } else {
        grp_fu_187_p0 = "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX";
    }
}

void vivado_activity_thread::thread_grp_fu_187_p1() {
    if (esl_seteq<1,6,6>(ap_ST_st45_fsm_44, ap_CS_fsm.read())) {
        grp_fu_187_p1 = temp_value_reg_296.read();
    } else if (esl_seteq<1,6,6>(ap_ST_st21_fsm_20, ap_CS_fsm.read())) {
        grp_fu_187_p1 = tmp_pn_reg_146.read();
    } else if (esl_seteq<1,6,6>(ap_ST_st17_fsm_16, ap_CS_fsm.read())) {
        grp_fu_187_p1 = delta_time_0_reg_246.read();
    } else {
        grp_fu_187_p1 = "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX";
    }
}

void vivado_activity_thread::thread_grp_fu_194_ce() {
    grp_fu_194_ce = ap_const_logic_1;
}

void vivado_activity_thread::thread_grp_fu_194_p0() {
    grp_fu_194_p0 = kernel_o_a_0_time_period.read();
}

void vivado_activity_thread::thread_grp_fu_194_p1() {
    grp_fu_194_p1 = ap_const_lv32_41200000;
}

void vivado_activity_thread::thread_grp_fu_200_ce() {
    grp_fu_200_ce = ap_const_logic_1;
}

void vivado_activity_thread::thread_grp_fu_200_opcode() {
    grp_fu_200_opcode = ap_const_lv5_1;
}

void vivado_activity_thread::thread_grp_fu_200_p0() {
    grp_fu_200_p0 = kernel_o_a_0_call.read();
}

void vivado_activity_thread::thread_grp_fu_200_p1() {
    grp_fu_200_p1 = ap_const_lv32_0;
}

void vivado_activity_thread::thread_grp_fu_205_ce() {
    grp_fu_205_ce = ap_const_logic_1;
}

void vivado_activity_thread::thread_grp_fu_205_p0() {
    grp_fu_205_p0 = ap_const_lv32_1;
}

void vivado_activity_thread::thread_grp_fu_205_p1() {
    grp_fu_205_p1 = u_v_0_gamma_reg_280.read();
}

void vivado_activity_thread::thread_pp_1_fu_222_p2() {
    pp_1_fu_222_p2 = (!pp_reg_170.read().is_01() || !ap_const_lv4_1.is_01())? sc_lv<4>(): (sc_bigint<4>(pp_reg_170.read()) + sc_biguint<4>(ap_const_lv4_1));
}

void vivado_activity_thread::thread_temp_value_fu_234_p3() {
    temp_value_fu_234_p3 = (!tmp_2_reg_291.read()[0].is_01())? sc_lv<32>(): ((tmp_2_reg_291.read()[0].to_bool())? grp_fu_182_p2.read(): grp_fu_182_p2.read());
}

void vivado_activity_thread::thread_thread_result_0() {
    thread_result_0 = temp_value_reg_296.read();
}

void vivado_activity_thread::thread_thread_result_0_ap_vld() {
    if (esl_seteq<1,6,6>(ap_ST_st45_fsm_44, ap_CS_fsm.read())) {
        thread_result_0_ap_vld = ap_const_logic_1;
    } else {
        thread_result_0_ap_vld = ap_const_logic_0;
    }
}

void vivado_activity_thread::thread_thread_result_sqrd_0() {
    thread_result_sqrd_0 = grp_fu_187_p2.read();
}

void vivado_activity_thread::thread_thread_result_sqrd_0_ap_vld() {
    if (esl_seteq<1,6,6>(ap_ST_st48_fsm_47, ap_CS_fsm.read())) {
        thread_result_sqrd_0_ap_vld = ap_const_logic_1;
    } else {
        thread_result_sqrd_0_ap_vld = ap_const_logic_0;
    }
}

void vivado_activity_thread::thread_tmp_2_fu_228_p2() {
    tmp_2_fu_228_p2 = (grp_fu_200_p2.read() ^ ap_const_lv1_1);
}

void vivado_activity_thread::thread_ap_NS_fsm() {
    switch (ap_CS_fsm.read().to_uint()) {
        case 0 : 
            if (!esl_seteq<1,1,1>(ap_start.read(), ap_const_logic_0)) {
                ap_NS_fsm = ap_ST_st2_fsm_1;
            } else {
                ap_NS_fsm = ap_ST_st1_fsm_0;
            }
            break;
        case 1 : 
            ap_NS_fsm = ap_ST_st3_fsm_2;
            break;
        case 2 : 
            ap_NS_fsm = ap_ST_st4_fsm_3;
            break;
        case 3 : 
            ap_NS_fsm = ap_ST_st5_fsm_4;
            break;
        case 4 : 
            ap_NS_fsm = ap_ST_st6_fsm_5;
            break;
        case 5 : 
            ap_NS_fsm = ap_ST_st7_fsm_6;
            break;
        case 6 : 
            ap_NS_fsm = ap_ST_st8_fsm_7;
            break;
        case 7 : 
            ap_NS_fsm = ap_ST_st9_fsm_8;
            break;
        case 8 : 
            ap_NS_fsm = ap_ST_st10_fsm_9;
            break;
        case 9 : 
            ap_NS_fsm = ap_ST_st11_fsm_10;
            break;
        case 10 : 
            ap_NS_fsm = ap_ST_st12_fsm_11;
            break;
        case 11 : 
            ap_NS_fsm = ap_ST_st13_fsm_12;
            break;
        case 12 : 
            ap_NS_fsm = ap_ST_st14_fsm_13;
            break;
        case 13 : 
            ap_NS_fsm = ap_ST_st15_fsm_14;
            break;
        case 14 : 
            ap_NS_fsm = ap_ST_st16_fsm_15;
            break;
        case 15 : 
            ap_NS_fsm = ap_ST_st17_fsm_16;
            break;
        case 16 : 
            ap_NS_fsm = ap_ST_st18_fsm_17;
            break;
        case 17 : 
            ap_NS_fsm = ap_ST_st19_fsm_18;
            break;
        case 18 : 
            ap_NS_fsm = ap_ST_st20_fsm_19;
            break;
        case 19 : 
            ap_NS_fsm = ap_ST_st21_fsm_20;
            break;
        case 20 : 
            ap_NS_fsm = ap_ST_st22_fsm_21;
            break;
        case 21 : 
            ap_NS_fsm = ap_ST_st23_fsm_22;
            break;
        case 22 : 
            ap_NS_fsm = ap_ST_st24_fsm_23;
            break;
        case 23 : 
            if (!esl_seteq<1,1,1>(ap_const_lv1_0, exitcond_fu_216_p2.read())) {
                ap_NS_fsm = ap_ST_st38_fsm_37;
            } else {
                ap_NS_fsm = ap_ST_st25_fsm_24;
            }
            break;
        case 24 : 
            ap_NS_fsm = ap_ST_st26_fsm_25;
            break;
        case 25 : 
            ap_NS_fsm = ap_ST_st27_fsm_26;
            break;
        case 26 : 
            ap_NS_fsm = ap_ST_st28_fsm_27;
            break;
        case 27 : 
            ap_NS_fsm = ap_ST_st29_fsm_28;
            break;
        case 28 : 
            ap_NS_fsm = ap_ST_st30_fsm_29;
            break;
        case 29 : 
            ap_NS_fsm = ap_ST_st31_fsm_30;
            break;
        case 30 : 
            ap_NS_fsm = ap_ST_st32_fsm_31;
            break;
        case 31 : 
            ap_NS_fsm = ap_ST_st33_fsm_32;
            break;
        case 32 : 
            ap_NS_fsm = ap_ST_st34_fsm_33;
            break;
        case 33 : 
            ap_NS_fsm = ap_ST_st35_fsm_34;
            break;
        case 34 : 
            ap_NS_fsm = ap_ST_st36_fsm_35;
            break;
        case 35 : 
            ap_NS_fsm = ap_ST_st37_fsm_36;
            break;
        case 36 : 
            ap_NS_fsm = ap_ST_st21_fsm_20;
            break;
        case 37 : 
            ap_NS_fsm = ap_ST_st39_fsm_38;
            break;
        case 38 : 
            ap_NS_fsm = ap_ST_st40_fsm_39;
            break;
        case 39 : 
            ap_NS_fsm = ap_ST_st41_fsm_40;
            break;
        case 40 : 
            ap_NS_fsm = ap_ST_st42_fsm_41;
            break;
        case 41 : 
            ap_NS_fsm = ap_ST_st43_fsm_42;
            break;
        case 42 : 
            ap_NS_fsm = ap_ST_st44_fsm_43;
            break;
        case 43 : 
            ap_NS_fsm = ap_ST_st45_fsm_44;
            break;
        case 44 : 
            ap_NS_fsm = ap_ST_st46_fsm_45;
            break;
        case 45 : 
            ap_NS_fsm = ap_ST_st47_fsm_46;
            break;
        case 46 : 
            ap_NS_fsm = ap_ST_st48_fsm_47;
            break;
        case 47 : 
            ap_NS_fsm = ap_ST_st1_fsm_0;
            break;
        default : 
            ap_NS_fsm =  (sc_lv<6>) ("XXXXXX");
            break;
    }
}
void vivado_activity_thread::thread_hdltv_gen() {
    const char* dump_tv = std::getenv("AP_WRITE_TV");
    if (!(dump_tv && string(dump_tv) == "on")) return;

    wait();

    mHdltvinHandle << "[ " << endl;
    mHdltvoutHandle << "[ " << endl;
    int ap_cycleNo = 0;
    while (1) {
        wait();
        const char* mComma = ap_cycleNo == 0 ? " " : ", " ;
        mHdltvinHandle << mComma << "{"  <<  " \"ap_rst\" :  \"" << ap_rst.read() << "\" ";
        mHdltvinHandle << " , " <<  " \"ap_start\" :  \"" << ap_start.read() << "\" ";
        mHdltvoutHandle << mComma << "{"  <<  " \"ap_done\" :  \"" << ap_done.read() << "\" ";
        mHdltvoutHandle << " , " <<  " \"ap_idle\" :  \"" << ap_idle.read() << "\" ";
        mHdltvoutHandle << " , " <<  " \"ap_ready\" :  \"" << ap_ready.read() << "\" ";
        mHdltvinHandle << " , " <<  " \"kernel_u_a_0_rfir\" :  \"" << kernel_u_a_0_rfir.read() << "\" ";
        mHdltvinHandle << " , " <<  " \"kernel_u_a_0_current_price\" :  \"" << kernel_u_a_0_current_price.read() << "\" ";
        mHdltvinHandle << " , " <<  " \"kernel_u_a_0_volatility\" :  \"" << kernel_u_a_0_volatility.read() << "\" ";
        mHdltvinHandle << " , " <<  " \"kernel_u_a_0_initial_volatility\" :  \"" << kernel_u_a_0_initial_volatility.read() << "\" ";
        mHdltvinHandle << " , " <<  " \"kernel_u_a_0_volatility_volatility\" :  \"" << kernel_u_a_0_volatility_volatility.read() << "\" ";
        mHdltvinHandle << " , " <<  " \"kernel_u_a_0_rho\" :  \"" << kernel_u_a_0_rho.read() << "\" ";
        mHdltvinHandle << " , " <<  " \"kernel_u_a_0_kappa\" :  \"" << kernel_u_a_0_kappa.read() << "\" ";
        mHdltvinHandle << " , " <<  " \"kernel_u_a_0_theta\" :  \"" << kernel_u_a_0_theta.read() << "\" ";
        mHdltvinHandle << " , " <<  " \"kernel_u_a_0_correlation_matrix_0_0\" :  \"" << kernel_u_a_0_correlation_matrix_0_0.read() << "\" ";
        mHdltvinHandle << " , " <<  " \"kernel_u_a_0_correlation_matrix_0_1\" :  \"" << kernel_u_a_0_correlation_matrix_0_1.read() << "\" ";
        mHdltvinHandle << " , " <<  " \"kernel_u_a_0_correlation_matrix_1_0\" :  \"" << kernel_u_a_0_correlation_matrix_1_0.read() << "\" ";
        mHdltvinHandle << " , " <<  " \"kernel_u_a_0_correlation_matrix_1_1\" :  \"" << kernel_u_a_0_correlation_matrix_1_1.read() << "\" ";
        mHdltvinHandle << " , " <<  " \"kernel_o_a_0_second_barrier\" :  \"" << kernel_o_a_0_second_barrier.read() << "\" ";
        mHdltvinHandle << " , " <<  " \"kernel_o_a_0_barrier\" :  \"" << kernel_o_a_0_barrier.read() << "\" ";
        mHdltvinHandle << " , " <<  " \"kernel_o_a_0_out\" :  \"" << kernel_o_a_0_out.read() << "\" ";
        mHdltvinHandle << " , " <<  " \"kernel_o_a_0_down\" :  \"" << kernel_o_a_0_down.read() << "\" ";
        mHdltvinHandle << " , " <<  " \"kernel_o_a_0_strike_price\" :  \"" << kernel_o_a_0_strike_price.read() << "\" ";
        mHdltvinHandle << " , " <<  " \"kernel_o_a_0_time_period\" :  \"" << kernel_o_a_0_time_period.read() << "\" ";
        mHdltvinHandle << " , " <<  " \"kernel_o_a_0_call\" :  \"" << kernel_o_a_0_call.read() << "\" ";
        mHdltvinHandle << " , " <<  " \"kernel_o_a_0_points\" :  \"" << kernel_o_a_0_points.read() << "\" ";
        mHdltvinHandle << " , " <<  " \"seed_0_s1\" :  \"" << seed_0_s1.read() << "\" ";
        mHdltvinHandle << " , " <<  " \"seed_0_s2\" :  \"" << seed_0_s2.read() << "\" ";
        mHdltvinHandle << " , " <<  " \"seed_0_s3\" :  \"" << seed_0_s3.read() << "\" ";
        mHdltvinHandle << " , " <<  " \"seed_0_offset\" :  \"" << seed_0_offset.read() << "\" ";
        mHdltvoutHandle << " , " <<  " \"thread_result_0\" :  \"" << thread_result_0.read() << "\" ";
        mHdltvoutHandle << " , " <<  " \"thread_result_0_ap_vld\" :  \"" << thread_result_0_ap_vld.read() << "\" ";
        mHdltvoutHandle << " , " <<  " \"thread_result_sqrd_0\" :  \"" << thread_result_sqrd_0.read() << "\" ";
        mHdltvoutHandle << " , " <<  " \"thread_result_sqrd_0_ap_vld\" :  \"" << thread_result_sqrd_0_ap_vld.read() << "\" ";
        mHdltvinHandle << "}" << std::endl;
        mHdltvoutHandle << "}" << std::endl;
        ap_cycleNo++;
    }
}

}

