; ModuleID = '/home/ee/s/sf306/ForwardFinancialFramework/Platforms/VivadoFPGA/vivadohls_code/hls_prj/F3_VivadoHLS_core/.autopilot/db/a.o.2.bc'
target datalayout = "e-p:64:64:64-i1:8:8-i8:8:8-i16:16:16-i32:32:32-i64:64:64-f32:32:32-f64:64:64-v64:64:64-v128:128:128-a0:0:64-s0:64:64-f80:128:128-n8:16:32:64-S128"
target triple = "x86_64-unknown-linux-gnu"

@end_tv_sec = common global i64 0
@end_tv_nsec = common global i64 0
@setup_end_tv_sec = common global i64 0
@setup_end_tv_nsec = common global i64 0
@start_tv_sec = common global i64 0
@start_tv_nsec = common global i64 0
@p_str124 = private unnamed_addr constant [1 x i8] zeroinitializer, align 1
@p_str125 = private unnamed_addr constant [10 x i8] c"AXI_SLAVE\00", align 1
@p_str126 = private unnamed_addr constant [20 x i8] c"-bus_bundle CORE_IO\00", align 1
@p_str127 = private unnamed_addr constant [13 x i8] c"PATHSET_LOOP\00", align 1
@p_str128 = private unnamed_addr constant [10 x i8] c"PATH_LOOP\00", align 1
@i = common global i32 0, align 4
@j = common global i32 0, align 4
@discount_0_0 = common global float 0.000000e+00, align 4
@thread_paths = common global i32 0, align 4
@option_price_0 = common global float 0.000000e+00, align 4
@option_price_0_confidence_interval = common global float 0.000000e+00, align 4
@setup_time = common global float 0.000000e+00, align 4
@activity_time = common global float 0.000000e+00, align 4
@ret = common global i32 0, align 4
@ret_2 = common global i32 0, align 4
@llvm_global_ctors_0 = appending global [2 x i32] [i32 65535, i32 65535]
@llvm_global_ctors_1 = appending global [2 x void ()*] [void ()* @_GLOBAL__I_a, void ()* @_GLOBAL__I_a2027]
@str = internal constant [23 x i8] c"vivado_activity_thread\00"

define void @vivado_activity_thread(float* %kernel_u_a_0_rfir, float* %kernel_u_a_0_current_price, float* %kernel_u_a_0_volatility, float* %kernel_u_a_0_initial_volatility, float* %kernel_u_a_0_volatility_volatility, float* %kernel_u_a_0_rho, float* %kernel_u_a_0_kappa, float* %kernel_u_a_0_theta, float* %kernel_u_a_0_correlation_matrix_0_0, float* %kernel_u_a_0_correlation_matrix_0_1, float* %kernel_u_a_0_correlation_matrix_1_0, float* %kernel_u_a_0_correlation_matrix_1_1, float* %kernel_o_a_0_second_barrier, float* %kernel_o_a_0_barrier, float* %kernel_o_a_0_out, float* %kernel_o_a_0_down, float* %kernel_o_a_0_strike_price, float* %kernel_o_a_0_time_period, float* %kernel_o_a_0_call, float* %kernel_o_a_0_points, i32* %seed_0_s1, i32* %seed_0_s2, i32* %seed_0_s3, i32* %seed_0_offset, float* %thread_result_0, float* %thread_result_sqrd_0) {
.critedge:
  call void (...)* @_ssdm_op_SpecBitsMap(float* %kernel_u_a_0_rfir), !map !94
  call void (...)* @_ssdm_op_SpecBitsMap(float* %kernel_u_a_0_current_price), !map !98
  call void (...)* @_ssdm_op_SpecBitsMap(float* %kernel_u_a_0_volatility), !map !102
  call void (...)* @_ssdm_op_SpecBitsMap(float* %kernel_u_a_0_initial_volatility), !map !106
  call void (...)* @_ssdm_op_SpecBitsMap(float* %kernel_u_a_0_volatility_volatility), !map !110
  call void (...)* @_ssdm_op_SpecBitsMap(float* %kernel_u_a_0_rho), !map !114
  call void (...)* @_ssdm_op_SpecBitsMap(float* %kernel_u_a_0_kappa), !map !118
  call void (...)* @_ssdm_op_SpecBitsMap(float* %kernel_u_a_0_theta), !map !122
  call void (...)* @_ssdm_op_SpecBitsMap(float* %kernel_u_a_0_correlation_matrix_0_0), !map !126
  call void (...)* @_ssdm_op_SpecBitsMap(float* %kernel_u_a_0_correlation_matrix_0_1), !map !130
  call void (...)* @_ssdm_op_SpecBitsMap(float* %kernel_u_a_0_correlation_matrix_1_0), !map !134
  call void (...)* @_ssdm_op_SpecBitsMap(float* %kernel_u_a_0_correlation_matrix_1_1), !map !138
  call void (...)* @_ssdm_op_SpecBitsMap(float* %kernel_o_a_0_second_barrier), !map !142
  call void (...)* @_ssdm_op_SpecBitsMap(float* %kernel_o_a_0_barrier), !map !146
  call void (...)* @_ssdm_op_SpecBitsMap(float* %kernel_o_a_0_out), !map !150
  call void (...)* @_ssdm_op_SpecBitsMap(float* %kernel_o_a_0_down), !map !154
  call void (...)* @_ssdm_op_SpecBitsMap(float* %kernel_o_a_0_strike_price), !map !158
  call void (...)* @_ssdm_op_SpecBitsMap(float* %kernel_o_a_0_time_period), !map !162
  call void (...)* @_ssdm_op_SpecBitsMap(float* %kernel_o_a_0_call), !map !166
  call void (...)* @_ssdm_op_SpecBitsMap(float* %kernel_o_a_0_points), !map !170
  call void (...)* @_ssdm_op_SpecBitsMap(i32* %seed_0_s1), !map !174
  call void (...)* @_ssdm_op_SpecBitsMap(i32* %seed_0_s2), !map !178
  call void (...)* @_ssdm_op_SpecBitsMap(i32* %seed_0_s3), !map !182
  call void (...)* @_ssdm_op_SpecBitsMap(i32* %seed_0_offset), !map !186
  call void (...)* @_ssdm_op_SpecBitsMap(float* %thread_result_0), !map !190
  call void (...)* @_ssdm_op_SpecBitsMap(float* %thread_result_sqrd_0), !map !194
  call void (...)* @_ssdm_op_SpecTopModule([23 x i8]* @str) nounwind
  call void (...)* @_ssdm_op_SpecIFCore(float* %kernel_u_a_0_rfir, float* %kernel_u_a_0_current_price, float* %kernel_u_a_0_volatility, float* %kernel_u_a_0_initial_volatility, float* %kernel_u_a_0_volatility_volatility, float* %kernel_u_a_0_rho, float* %kernel_u_a_0_kappa, float* %kernel_u_a_0_theta, float* %kernel_u_a_0_correlation_matrix_0_0, float* %kernel_u_a_0_correlation_matrix_0_1, float* %kernel_u_a_0_correlation_matrix_1_0, float* %kernel_u_a_0_correlation_matrix_1_1, [1 x i8]* @p_str124, [10 x i8]* @p_str125, [1 x i8]* @p_str124, [1 x i8]* @p_str124, [1 x i8]* @p_str124, [20 x i8]* @p_str126)
  call void (...)* @_ssdm_op_SpecIFCore(float* %kernel_o_a_0_second_barrier, float* %kernel_o_a_0_barrier, float* %kernel_o_a_0_out, float* %kernel_o_a_0_down, float* %kernel_o_a_0_strike_price, float* %kernel_o_a_0_time_period, float* %kernel_o_a_0_call, float* %kernel_o_a_0_points, [1 x i8]* @p_str124, [10 x i8]* @p_str125, [1 x i8]* @p_str124, [1 x i8]* @p_str124, [1 x i8]* @p_str124, [20 x i8]* @p_str126)
  call void (...)* @_ssdm_op_SpecIFCore(i32* %seed_0_s1, i32* %seed_0_s2, i32* %seed_0_s3, i32* %seed_0_offset, [1 x i8]* @p_str124, [10 x i8]* @p_str125, [1 x i8]* @p_str124, [1 x i8]* @p_str124, [1 x i8]* @p_str124, [20 x i8]* @p_str126)
  call void (...)* @_ssdm_op_SpecIFCore(float* %thread_result_0, [1 x i8]* @p_str124, [10 x i8]* @p_str125, [1 x i8]* @p_str124, [1 x i8]* @p_str124, [1 x i8]* @p_str124, [20 x i8]* @p_str126)
  call void (...)* @_ssdm_op_SpecIFCore(float* %thread_result_sqrd_0, [1 x i8]* @p_str124, [10 x i8]* @p_str125, [1 x i8]* @p_str124, [1 x i8]* @p_str124, [1 x i8]* @p_str124, [20 x i8]* @p_str126)
  call void (...)* @_ssdm_op_SpecIFCore(i32 0, [1 x i8]* @p_str124, [10 x i8]* @p_str125, [1 x i8]* @p_str124, [1 x i8]* @p_str124, [1 x i8]* @p_str124, [20 x i8]* @p_str126)
  %o_a_0_strike_price = call float @_ssdm_op_Read.ap_auto.floatP(float* %kernel_o_a_0_strike_price)
  %o_a_0_time_period = call float @_ssdm_op_Read.ap_auto.floatP(float* %kernel_o_a_0_time_period)
  %o_a_0_call = call float @_ssdm_op_Read.ap_auto.floatP(float* %kernel_o_a_0_call)
  %u_a_0_rfir = call float @_ssdm_op_Read.ap_auto.floatP(float* %kernel_u_a_0_rfir)
  %u_a_0_current_price = call float @_ssdm_op_Read.ap_auto.floatP(float* %kernel_u_a_0_current_price)
  call void (...)* @_ssdm_op_SpecLoopName([13 x i8]* @p_str127) nounwind
  %tmp = call i32 (...)* @_ssdm_op_SpecRegionBegin([13 x i8]* @p_str127)
  %delta_time_0 = fdiv float %o_a_0_time_period, 1.000000e+01
  %tmp_i = fmul float %u_a_0_rfir, %delta_time_0
  br label %0

; <label>:0                                       ; preds = %1, %.critedge
  %u_v_gamma_read_assign = phi float [ 0.000000e+00, %.critedge ], [ %u_v_0_gamma, %1 ]
  %pp = phi i4 [ 0, %.critedge ], [ %pp_1, %1 ]
  %tmp_pn = phi float [ 1.000000e+00, %.critedge ], [ %tmp_7, %1 ]
  %spot_price_0 = fmul float %u_a_0_current_price, %tmp_pn
  %exitcond = icmp eq i4 %pp, -6
  %empty = call i32 (...)* @_ssdm_op_SpecLoopTripCount(i64 10, i64 10, i64 10)
  %pp_1 = add i4 %pp, 1
  br i1 %exitcond, label %_ifconv, label %1

; <label>:1                                       ; preds = %0
  call void (...)* @_ssdm_op_SpecLoopName([10 x i8]* @p_str128) nounwind
  %u_v_0_gamma = fadd float %tmp_i, %u_v_gamma_read_assign
  %tmp_7 = call float @llvm.exp.f32(float %u_v_0_gamma)
  br label %0

_ifconv:                                          ; preds = %0
  %tmp_1 = fcmp oeq float %o_a_0_call, 0.000000e+00
  %tmp_2 = xor i1 %tmp_1, true
  %tmp_1_i = fsub float %spot_price_0, %o_a_0_strike_price
  %tmp_2_i = fsub float %o_a_0_strike_price, %spot_price_0
  %temp_value = select i1 %tmp_2, float %tmp_1_i, float %tmp_2_i
  call void @_ssdm_op_Write.ap_auto.floatP(float* %thread_result_0, float %temp_value)
  %tmp_6 = fmul float %temp_value, %temp_value
  call void @_ssdm_op_Write.ap_auto.floatP(float* %thread_result_sqrd_0, float %tmp_6)
  %empty_2 = call i32 (...)* @_ssdm_op_SpecRegionEnd([13 x i8]* @p_str127, i32 %tmp)
  ret void
}

define weak void @_ssdm_op_SpecLoopName(...) nounwind {
entry:
  ret void
}

declare void @llvm.dbg.value(metadata, i64, metadata) nounwind readnone

define weak void @_ssdm_op_SpecTopModule(...) {
entry:
  ret void
}

declare void @_GLOBAL__I_a() nounwind section ".text.startup"

declare void @_GLOBAL__I_a2027() nounwind section ".text.startup"

declare float @llvm.exp.f32(float) nounwind readonly

define weak i32 @_ssdm_op_SpecRegionBegin(...) {
entry:
  ret i32 0
}

define weak i32 @_ssdm_op_SpecRegionEnd(...) {
entry:
  ret i32 0
}

define weak void @_ssdm_op_SpecIFCore(...) {
entry:
  ret void
}

define weak void @_ssdm_op_SpecBitsMap(...) {
entry:
  ret void
}

define weak i32 @_ssdm_op_SpecLoopTripCount(...) {
entry:
  ret i32 0
}

define weak float @_ssdm_op_Read.ap_auto.floatP(float*) {
entry:
  %empty = load float* %0
  ret float %empty
}

define weak void @_ssdm_op_Write.ap_auto.floatP(float*, float) {
entry:
  store float %1, float* %0
  ret void
}

!llvm.map.gv = !{!0, !7, !12, !17, !22, !27, !32, !37, !42, !47, !52, !57, !62, !67, !72, !77, !82, !87}

!0 = metadata !{metadata !1, i64* @end_tv_sec}
!1 = metadata !{metadata !2}
!2 = metadata !{i32 0, i32 63, metadata !3}
!3 = metadata !{metadata !4}
!4 = metadata !{metadata !"end.tv_sec", metadata !5, metadata !"long int"}
!5 = metadata !{metadata !6}
!6 = metadata !{i32 0, i32 0, i32 1}
!7 = metadata !{metadata !8, i64* @end_tv_nsec}
!8 = metadata !{metadata !9}
!9 = metadata !{i32 0, i32 63, metadata !10}
!10 = metadata !{metadata !11}
!11 = metadata !{metadata !"end.tv_nsec", metadata !5, metadata !"long int"}
!12 = metadata !{metadata !13, i64* @setup_end_tv_sec}
!13 = metadata !{metadata !14}
!14 = metadata !{i32 0, i32 63, metadata !15}
!15 = metadata !{metadata !16}
!16 = metadata !{metadata !"setup_end.tv_sec", metadata !5, metadata !"long int"}
!17 = metadata !{metadata !18, i64* @setup_end_tv_nsec}
!18 = metadata !{metadata !19}
!19 = metadata !{i32 0, i32 63, metadata !20}
!20 = metadata !{metadata !21}
!21 = metadata !{metadata !"setup_end.tv_nsec", metadata !5, metadata !"long int"}
!22 = metadata !{metadata !23, i64* @start_tv_sec}
!23 = metadata !{metadata !24}
!24 = metadata !{i32 0, i32 63, metadata !25}
!25 = metadata !{metadata !26}
!26 = metadata !{metadata !"start.tv_sec", metadata !5, metadata !"long int"}
!27 = metadata !{metadata !28, i64* @start_tv_nsec}
!28 = metadata !{metadata !29}
!29 = metadata !{i32 0, i32 63, metadata !30}
!30 = metadata !{metadata !31}
!31 = metadata !{metadata !"start.tv_nsec", metadata !5, metadata !"long int"}
!32 = metadata !{metadata !33, i32* @i}
!33 = metadata !{metadata !34}
!34 = metadata !{i32 0, i32 31, metadata !35}
!35 = metadata !{metadata !36}
!36 = metadata !{metadata !"i", metadata !5, metadata !"int"}
!37 = metadata !{metadata !38, i32* @j}
!38 = metadata !{metadata !39}
!39 = metadata !{i32 0, i32 31, metadata !40}
!40 = metadata !{metadata !41}
!41 = metadata !{metadata !"j", metadata !5, metadata !"int"}
!42 = metadata !{metadata !43, float* @discount_0_0}
!43 = metadata !{metadata !44}
!44 = metadata !{i32 0, i32 31, metadata !45}
!45 = metadata !{metadata !46}
!46 = metadata !{metadata !"discount_0_0", metadata !5, metadata !"float"}
!47 = metadata !{metadata !48, i32* @thread_paths}
!48 = metadata !{metadata !49}
!49 = metadata !{i32 0, i32 31, metadata !50}
!50 = metadata !{metadata !51}
!51 = metadata !{metadata !"thread_paths", metadata !5, metadata !"int"}
!52 = metadata !{metadata !53, float* @option_price_0}
!53 = metadata !{metadata !54}
!54 = metadata !{i32 0, i32 31, metadata !55}
!55 = metadata !{metadata !56}
!56 = metadata !{metadata !"option_price_0", metadata !5, metadata !"float"}
!57 = metadata !{metadata !58, float* @option_price_0_confidence_interval}
!58 = metadata !{metadata !59}
!59 = metadata !{i32 0, i32 31, metadata !60}
!60 = metadata !{metadata !61}
!61 = metadata !{metadata !"option_price_0_confidence_interval", metadata !5, metadata !"float"}
!62 = metadata !{metadata !63, float* @setup_time}
!63 = metadata !{metadata !64}
!64 = metadata !{i32 0, i32 31, metadata !65}
!65 = metadata !{metadata !66}
!66 = metadata !{metadata !"setup_time", metadata !5, metadata !"float"}
!67 = metadata !{metadata !68, float* @activity_time}
!68 = metadata !{metadata !69}
!69 = metadata !{i32 0, i32 31, metadata !70}
!70 = metadata !{metadata !71}
!71 = metadata !{metadata !"activity_time", metadata !5, metadata !"float"}
!72 = metadata !{metadata !73, i32* @ret}
!73 = metadata !{metadata !74}
!74 = metadata !{i32 0, i32 31, metadata !75}
!75 = metadata !{metadata !76}
!76 = metadata !{metadata !"ret", metadata !5, metadata !"int"}
!77 = metadata !{metadata !78, i32* @ret_2}
!78 = metadata !{metadata !79}
!79 = metadata !{i32 0, i32 31, metadata !80}
!80 = metadata !{metadata !81}
!81 = metadata !{metadata !"ret_2", metadata !5, metadata !"int"}
!82 = metadata !{metadata !83, null}
!83 = metadata !{metadata !84}
!84 = metadata !{i32 0, i32 7, metadata !85}
!85 = metadata !{metadata !86}
!86 = metadata !{metadata !"__dso_handle", metadata !5, metadata !""}
!87 = metadata !{metadata !88, [2 x i32]* @llvm_global_ctors_0}
!88 = metadata !{metadata !89}
!89 = metadata !{i32 0, i32 31, metadata !90}
!90 = metadata !{metadata !91}
!91 = metadata !{metadata !"llvm.global_ctors.0", metadata !92, metadata !""}
!92 = metadata !{metadata !93}
!93 = metadata !{i32 0, i32 1, i32 1}
!94 = metadata !{metadata !95}
!95 = metadata !{i32 0, i32 31, metadata !96}
!96 = metadata !{metadata !97}
!97 = metadata !{metadata !"kernel_u_a_0.rfir", metadata !5, metadata !"float"}
!98 = metadata !{metadata !99}
!99 = metadata !{i32 0, i32 31, metadata !100}
!100 = metadata !{metadata !101}
!101 = metadata !{metadata !"kernel_u_a_0.current_price", metadata !5, metadata !"float"}
!102 = metadata !{metadata !103}
!103 = metadata !{i32 0, i32 31, metadata !104}
!104 = metadata !{metadata !105}
!105 = metadata !{metadata !"kernel_u_a_0.volatility", metadata !5, metadata !"float"}
!106 = metadata !{metadata !107}
!107 = metadata !{i32 0, i32 31, metadata !108}
!108 = metadata !{metadata !109}
!109 = metadata !{metadata !"kernel_u_a_0.initial_volatility", metadata !5, metadata !"float"}
!110 = metadata !{metadata !111}
!111 = metadata !{i32 0, i32 31, metadata !112}
!112 = metadata !{metadata !113}
!113 = metadata !{metadata !"kernel_u_a_0.volatility_volatility", metadata !5, metadata !"float"}
!114 = metadata !{metadata !115}
!115 = metadata !{i32 0, i32 31, metadata !116}
!116 = metadata !{metadata !117}
!117 = metadata !{metadata !"kernel_u_a_0.rho", metadata !5, metadata !"float"}
!118 = metadata !{metadata !119}
!119 = metadata !{i32 0, i32 31, metadata !120}
!120 = metadata !{metadata !121}
!121 = metadata !{metadata !"kernel_u_a_0.kappa", metadata !5, metadata !"float"}
!122 = metadata !{metadata !123}
!123 = metadata !{i32 0, i32 31, metadata !124}
!124 = metadata !{metadata !125}
!125 = metadata !{metadata !"kernel_u_a_0.theta", metadata !5, metadata !"float"}
!126 = metadata !{metadata !127}
!127 = metadata !{i32 0, i32 31, metadata !128}
!128 = metadata !{metadata !129}
!129 = metadata !{metadata !"kernel_u_a_0.correlation_matrix_0_0", metadata !5, metadata !"float"}
!130 = metadata !{metadata !131}
!131 = metadata !{i32 0, i32 31, metadata !132}
!132 = metadata !{metadata !133}
!133 = metadata !{metadata !"kernel_u_a_0.correlation_matrix_0_1", metadata !5, metadata !"float"}
!134 = metadata !{metadata !135}
!135 = metadata !{i32 0, i32 31, metadata !136}
!136 = metadata !{metadata !137}
!137 = metadata !{metadata !"kernel_u_a_0.correlation_matrix_1_0", metadata !5, metadata !"float"}
!138 = metadata !{metadata !139}
!139 = metadata !{i32 0, i32 31, metadata !140}
!140 = metadata !{metadata !141}
!141 = metadata !{metadata !"kernel_u_a_0.correlation_matrix_1_1", metadata !5, metadata !"float"}
!142 = metadata !{metadata !143}
!143 = metadata !{i32 0, i32 31, metadata !144}
!144 = metadata !{metadata !145}
!145 = metadata !{metadata !"kernel_o_a_0.second_barrier", metadata !5, metadata !"float"}
!146 = metadata !{metadata !147}
!147 = metadata !{i32 0, i32 31, metadata !148}
!148 = metadata !{metadata !149}
!149 = metadata !{metadata !"kernel_o_a_0.barrier", metadata !5, metadata !"float"}
!150 = metadata !{metadata !151}
!151 = metadata !{i32 0, i32 31, metadata !152}
!152 = metadata !{metadata !153}
!153 = metadata !{metadata !"kernel_o_a_0.out", metadata !5, metadata !"float"}
!154 = metadata !{metadata !155}
!155 = metadata !{i32 0, i32 31, metadata !156}
!156 = metadata !{metadata !157}
!157 = metadata !{metadata !"kernel_o_a_0.down", metadata !5, metadata !"float"}
!158 = metadata !{metadata !159}
!159 = metadata !{i32 0, i32 31, metadata !160}
!160 = metadata !{metadata !161}
!161 = metadata !{metadata !"kernel_o_a_0.strike_price", metadata !5, metadata !"float"}
!162 = metadata !{metadata !163}
!163 = metadata !{i32 0, i32 31, metadata !164}
!164 = metadata !{metadata !165}
!165 = metadata !{metadata !"kernel_o_a_0.time_period", metadata !5, metadata !"float"}
!166 = metadata !{metadata !167}
!167 = metadata !{i32 0, i32 31, metadata !168}
!168 = metadata !{metadata !169}
!169 = metadata !{metadata !"kernel_o_a_0.call", metadata !5, metadata !"float"}
!170 = metadata !{metadata !171}
!171 = metadata !{i32 0, i32 31, metadata !172}
!172 = metadata !{metadata !173}
!173 = metadata !{metadata !"kernel_o_a_0.points", metadata !5, metadata !"float"}
!174 = metadata !{metadata !175}
!175 = metadata !{i32 0, i32 31, metadata !176}
!176 = metadata !{metadata !177}
!177 = metadata !{metadata !"seed_0.s1", metadata !5, metadata !"uint32"}
!178 = metadata !{metadata !179}
!179 = metadata !{i32 0, i32 31, metadata !180}
!180 = metadata !{metadata !181}
!181 = metadata !{metadata !"seed_0.s2", metadata !5, metadata !"uint32"}
!182 = metadata !{metadata !183}
!183 = metadata !{i32 0, i32 31, metadata !184}
!184 = metadata !{metadata !185}
!185 = metadata !{metadata !"seed_0.s3", metadata !5, metadata !"uint32"}
!186 = metadata !{metadata !187}
!187 = metadata !{i32 0, i32 31, metadata !188}
!188 = metadata !{metadata !189}
!189 = metadata !{metadata !"seed_0.offset", metadata !5, metadata !"uint32"}
!190 = metadata !{metadata !191}
!191 = metadata !{i32 0, i32 31, metadata !192}
!192 = metadata !{metadata !193}
!193 = metadata !{metadata !"thread_result_0", metadata !5, metadata !"float"}
!194 = metadata !{metadata !195}
!195 = metadata !{i32 0, i32 31, metadata !196}
!196 = metadata !{metadata !197}
!197 = metadata !{metadata !"thread_result_sqrd_0", metadata !5, metadata !"float"}
