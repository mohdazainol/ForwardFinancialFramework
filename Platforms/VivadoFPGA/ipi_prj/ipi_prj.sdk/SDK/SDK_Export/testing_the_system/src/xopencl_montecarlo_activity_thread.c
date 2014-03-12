// ==============================================================
// File generated by Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC
// Version: 2013.3
// Copyright (C) 2013 Xilinx Inc. All rights reserved.
// 
// ==============================================================

/***************************** Include Files *********************************/
#include "xopencl_montecarlo_activity_thread.h"

/************************** Function Implementation *************************/
#ifndef __linux__
int XOpencl_montecarlo_activity_thread_CfgInitialize(XOpencl_montecarlo_activity_thread *InstancePtr, XOpencl_montecarlo_activity_thread_Config *ConfigPtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(ConfigPtr != NULL);

    InstancePtr->Core_io_BaseAddress = ConfigPtr->Core_io_BaseAddress;
    InstancePtr->IsReady = XIL_COMPONENT_IS_READY;

    return XST_SUCCESS;
}
#endif

void XOpencl_montecarlo_activity_thread_Start(XOpencl_montecarlo_activity_thread *InstancePtr) {
    u32 Data;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XOpencl_montecarlo_activity_thread_ReadReg(InstancePtr->Core_io_BaseAddress, XOPENCL_MONTECARLO_ACTIVITY_THREAD_CORE_IO_ADDR_AP_CTRL) & 0x80;
    XOpencl_montecarlo_activity_thread_WriteReg(InstancePtr->Core_io_BaseAddress, XOPENCL_MONTECARLO_ACTIVITY_THREAD_CORE_IO_ADDR_AP_CTRL, Data | 0x01);
}

u32 XOpencl_montecarlo_activity_thread_IsDone(XOpencl_montecarlo_activity_thread *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XOpencl_montecarlo_activity_thread_ReadReg(InstancePtr->Core_io_BaseAddress, XOPENCL_MONTECARLO_ACTIVITY_THREAD_CORE_IO_ADDR_AP_CTRL);
    return (Data >> 1) & 0x1;
}

u32 XOpencl_montecarlo_activity_thread_IsIdle(XOpencl_montecarlo_activity_thread *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XOpencl_montecarlo_activity_thread_ReadReg(InstancePtr->Core_io_BaseAddress, XOPENCL_MONTECARLO_ACTIVITY_THREAD_CORE_IO_ADDR_AP_CTRL);
    return (Data >> 2) & 0x1;
}

u32 XOpencl_montecarlo_activity_thread_IsReady(XOpencl_montecarlo_activity_thread *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XOpencl_montecarlo_activity_thread_ReadReg(InstancePtr->Core_io_BaseAddress, XOPENCL_MONTECARLO_ACTIVITY_THREAD_CORE_IO_ADDR_AP_CTRL);
    // check ap_start to see if the pcore is ready for next input
    return !(Data & 0x1);
}

void XOpencl_montecarlo_activity_thread_EnableAutoRestart(XOpencl_montecarlo_activity_thread *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XOpencl_montecarlo_activity_thread_WriteReg(InstancePtr->Core_io_BaseAddress, XOPENCL_MONTECARLO_ACTIVITY_THREAD_CORE_IO_ADDR_AP_CTRL, 0x80);
}

void XOpencl_montecarlo_activity_thread_DisableAutoRestart(XOpencl_montecarlo_activity_thread *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XOpencl_montecarlo_activity_thread_WriteReg(InstancePtr->Core_io_BaseAddress, XOPENCL_MONTECARLO_ACTIVITY_THREAD_CORE_IO_ADDR_AP_CTRL, 0);
}

void XOpencl_montecarlo_activity_thread_SetThread_arg_thread_paths(XOpencl_montecarlo_activity_thread *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XOpencl_montecarlo_activity_thread_WriteReg(InstancePtr->Core_io_BaseAddress, XOPENCL_MONTECARLO_ACTIVITY_THREAD_CORE_IO_ADDR_THREAD_ARG_THREAD_PATHS_DATA, Data);
}

u32 XOpencl_montecarlo_activity_thread_GetThread_arg_thread_paths(XOpencl_montecarlo_activity_thread *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XOpencl_montecarlo_activity_thread_ReadReg(InstancePtr->Core_io_BaseAddress, XOPENCL_MONTECARLO_ACTIVITY_THREAD_CORE_IO_ADDR_THREAD_ARG_THREAD_PATHS_DATA);
    return Data;
}

void XOpencl_montecarlo_activity_thread_SetThread_arg_path_points(XOpencl_montecarlo_activity_thread *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XOpencl_montecarlo_activity_thread_WriteReg(InstancePtr->Core_io_BaseAddress, XOPENCL_MONTECARLO_ACTIVITY_THREAD_CORE_IO_ADDR_THREAD_ARG_PATH_POINTS_DATA, Data);
}

u32 XOpencl_montecarlo_activity_thread_GetThread_arg_path_points(XOpencl_montecarlo_activity_thread *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XOpencl_montecarlo_activity_thread_ReadReg(InstancePtr->Core_io_BaseAddress, XOPENCL_MONTECARLO_ACTIVITY_THREAD_CORE_IO_ADDR_THREAD_ARG_PATH_POINTS_DATA);
    return Data;
}

u32 XOpencl_montecarlo_activity_thread_GetThread_arg_thread_result(XOpencl_montecarlo_activity_thread *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XOpencl_montecarlo_activity_thread_ReadReg(InstancePtr->Core_io_BaseAddress, XOPENCL_MONTECARLO_ACTIVITY_THREAD_CORE_IO_ADDR_THREAD_ARG_THREAD_RESULT_DATA);
    return Data;
}

u32 XOpencl_montecarlo_activity_thread_GetThread_arg_thread_resultVld(XOpencl_montecarlo_activity_thread *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XOpencl_montecarlo_activity_thread_ReadReg(InstancePtr->Core_io_BaseAddress, XOPENCL_MONTECARLO_ACTIVITY_THREAD_CORE_IO_ADDR_THREAD_ARG_THREAD_RESULT_CTRL);
    return Data & 0x1;
}

u32 XOpencl_montecarlo_activity_thread_GetThread_arg_thread_result_sqrd(XOpencl_montecarlo_activity_thread *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XOpencl_montecarlo_activity_thread_ReadReg(InstancePtr->Core_io_BaseAddress, XOPENCL_MONTECARLO_ACTIVITY_THREAD_CORE_IO_ADDR_THREAD_ARG_THREAD_RESULT_SQRD_DATA);
    return Data;
}

u32 XOpencl_montecarlo_activity_thread_GetThread_arg_thread_result_sqrdVld(XOpencl_montecarlo_activity_thread *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XOpencl_montecarlo_activity_thread_ReadReg(InstancePtr->Core_io_BaseAddress, XOPENCL_MONTECARLO_ACTIVITY_THREAD_CORE_IO_ADDR_THREAD_ARG_THREAD_RESULT_SQRD_CTRL);
    return Data & 0x1;
}

void XOpencl_montecarlo_activity_thread_SetThread_arg_u_a_0_rfir(XOpencl_montecarlo_activity_thread *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XOpencl_montecarlo_activity_thread_WriteReg(InstancePtr->Core_io_BaseAddress, XOPENCL_MONTECARLO_ACTIVITY_THREAD_CORE_IO_ADDR_THREAD_ARG_U_A_0_RFIR_DATA, Data);
}

u32 XOpencl_montecarlo_activity_thread_GetThread_arg_u_a_0_rfir(XOpencl_montecarlo_activity_thread *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XOpencl_montecarlo_activity_thread_ReadReg(InstancePtr->Core_io_BaseAddress, XOPENCL_MONTECARLO_ACTIVITY_THREAD_CORE_IO_ADDR_THREAD_ARG_U_A_0_RFIR_DATA);
    return Data;
}

void XOpencl_montecarlo_activity_thread_SetThread_arg_u_a_0_current_price(XOpencl_montecarlo_activity_thread *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XOpencl_montecarlo_activity_thread_WriteReg(InstancePtr->Core_io_BaseAddress, XOPENCL_MONTECARLO_ACTIVITY_THREAD_CORE_IO_ADDR_THREAD_ARG_U_A_0_CURRENT_PRICE_DATA, Data);
}

u32 XOpencl_montecarlo_activity_thread_GetThread_arg_u_a_0_current_price(XOpencl_montecarlo_activity_thread *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XOpencl_montecarlo_activity_thread_ReadReg(InstancePtr->Core_io_BaseAddress, XOPENCL_MONTECARLO_ACTIVITY_THREAD_CORE_IO_ADDR_THREAD_ARG_U_A_0_CURRENT_PRICE_DATA);
    return Data;
}

void XOpencl_montecarlo_activity_thread_SetThread_arg_o_a_0_strike_price(XOpencl_montecarlo_activity_thread *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XOpencl_montecarlo_activity_thread_WriteReg(InstancePtr->Core_io_BaseAddress, XOPENCL_MONTECARLO_ACTIVITY_THREAD_CORE_IO_ADDR_THREAD_ARG_O_A_0_STRIKE_PRICE_DATA, Data);
}

u32 XOpencl_montecarlo_activity_thread_GetThread_arg_o_a_0_strike_price(XOpencl_montecarlo_activity_thread *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XOpencl_montecarlo_activity_thread_ReadReg(InstancePtr->Core_io_BaseAddress, XOPENCL_MONTECARLO_ACTIVITY_THREAD_CORE_IO_ADDR_THREAD_ARG_O_A_0_STRIKE_PRICE_DATA);
    return Data;
}

void XOpencl_montecarlo_activity_thread_SetThread_arg_o_a_0_time_period(XOpencl_montecarlo_activity_thread *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XOpencl_montecarlo_activity_thread_WriteReg(InstancePtr->Core_io_BaseAddress, XOPENCL_MONTECARLO_ACTIVITY_THREAD_CORE_IO_ADDR_THREAD_ARG_O_A_0_TIME_PERIOD_DATA, Data);
}

u32 XOpencl_montecarlo_activity_thread_GetThread_arg_o_a_0_time_period(XOpencl_montecarlo_activity_thread *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XOpencl_montecarlo_activity_thread_ReadReg(InstancePtr->Core_io_BaseAddress, XOPENCL_MONTECARLO_ACTIVITY_THREAD_CORE_IO_ADDR_THREAD_ARG_O_A_0_TIME_PERIOD_DATA);
    return Data;
}

void XOpencl_montecarlo_activity_thread_SetThread_arg_o_a_0_call(XOpencl_montecarlo_activity_thread *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XOpencl_montecarlo_activity_thread_WriteReg(InstancePtr->Core_io_BaseAddress, XOPENCL_MONTECARLO_ACTIVITY_THREAD_CORE_IO_ADDR_THREAD_ARG_O_A_0_CALL_DATA, Data);
}

u32 XOpencl_montecarlo_activity_thread_GetThread_arg_o_a_0_call(XOpencl_montecarlo_activity_thread *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XOpencl_montecarlo_activity_thread_ReadReg(InstancePtr->Core_io_BaseAddress, XOPENCL_MONTECARLO_ACTIVITY_THREAD_CORE_IO_ADDR_THREAD_ARG_O_A_0_CALL_DATA);
    return Data;
}

void XOpencl_montecarlo_activity_thread_InterruptGlobalEnable(XOpencl_montecarlo_activity_thread *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XOpencl_montecarlo_activity_thread_WriteReg(InstancePtr->Core_io_BaseAddress, XOPENCL_MONTECARLO_ACTIVITY_THREAD_CORE_IO_ADDR_GIE, 1);
}

void XOpencl_montecarlo_activity_thread_InterruptGlobalDisable(XOpencl_montecarlo_activity_thread *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XOpencl_montecarlo_activity_thread_WriteReg(InstancePtr->Core_io_BaseAddress, XOPENCL_MONTECARLO_ACTIVITY_THREAD_CORE_IO_ADDR_GIE, 0);
}

void XOpencl_montecarlo_activity_thread_InterruptEnable(XOpencl_montecarlo_activity_thread *InstancePtr, u32 Mask) {
    u32 Register;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Register =  XOpencl_montecarlo_activity_thread_ReadReg(InstancePtr->Core_io_BaseAddress, XOPENCL_MONTECARLO_ACTIVITY_THREAD_CORE_IO_ADDR_IER);
    XOpencl_montecarlo_activity_thread_WriteReg(InstancePtr->Core_io_BaseAddress, XOPENCL_MONTECARLO_ACTIVITY_THREAD_CORE_IO_ADDR_IER, Register | Mask);
}

void XOpencl_montecarlo_activity_thread_InterruptDisable(XOpencl_montecarlo_activity_thread *InstancePtr, u32 Mask) {
    u32 Register;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Register =  XOpencl_montecarlo_activity_thread_ReadReg(InstancePtr->Core_io_BaseAddress, XOPENCL_MONTECARLO_ACTIVITY_THREAD_CORE_IO_ADDR_IER);
    XOpencl_montecarlo_activity_thread_WriteReg(InstancePtr->Core_io_BaseAddress, XOPENCL_MONTECARLO_ACTIVITY_THREAD_CORE_IO_ADDR_IER, Register & (~Mask));
}

void XOpencl_montecarlo_activity_thread_InterruptClear(XOpencl_montecarlo_activity_thread *InstancePtr, u32 Mask) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XOpencl_montecarlo_activity_thread_WriteReg(InstancePtr->Core_io_BaseAddress, XOPENCL_MONTECARLO_ACTIVITY_THREAD_CORE_IO_ADDR_ISR, Mask);
}

u32 XOpencl_montecarlo_activity_thread_InterruptGetEnabled(XOpencl_montecarlo_activity_thread *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XOpencl_montecarlo_activity_thread_ReadReg(InstancePtr->Core_io_BaseAddress, XOPENCL_MONTECARLO_ACTIVITY_THREAD_CORE_IO_ADDR_IER);
}

u32 XOpencl_montecarlo_activity_thread_InterruptGetStatus(XOpencl_montecarlo_activity_thread *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XOpencl_montecarlo_activity_thread_ReadReg(InstancePtr->Core_io_BaseAddress, XOPENCL_MONTECARLO_ACTIVITY_THREAD_CORE_IO_ADDR_ISR);
}

