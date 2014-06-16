// ==============================================================
// File generated by Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC
// Version: 2013.4
// Copyright (C) 2013 Xilinx Inc. All rights reserved.
// 
// ==============================================================

/***************************** Include Files *********************************/
#include "xvivado_activity_thread.h"

#define RESERVED_MEM_START_ADDRESS 0x38400000
#define RESERVED_MEM_MAP_SIZE 4096UL
#define RESERVED_MEM_MAP_MASK (RESERVED_MEM_MAP_SIZE - 1)

#define MAP_SIZE 4096UL
#define MAP_MASK (MAP_SIZE - 1)
#define VIVADO_ACTIVITY_THREAD_ADDRESS 0x43C00000 

/************************** Function Implementation *************************/
#ifndef __linux__
int XVivado_activity_thread_CfgInitialize(XVivado_activity_thread *InstancePtr, XVivado_activity_thread_Config *ConfigPtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(ConfigPtr != NULL);

    InstancePtr->Core_io_BaseAddress = ConfigPtr->Core_io_BaseAddress;
    InstancePtr->IsReady = XIL_COMPONENT_IS_READY;

    return XST_SUCCESS;
}
#endif

void * setup_reserved_mem() //returns a pointer in userspace to the device
{
    void *mapped_base_reserved_mem;
    int memfd_reserved_mem;
    void *mapped_dev_base;
    off_t dev_base = RESERVED_MEM_START_ADDRESS;

    memfd_reserved_mem = open("/dev/mem", O_RDWR | O_SYNC); //to open this the program needs to be run as root
        if (memfd_reserved_mem == -1) {
        printf("Can't open /dev/mem.\n");
        exit(0);
    }
    //printf("/dev/mem opened.\n"); 

    // Map one page of memory into user space such that the device is in that page, but it may not
    // be at the start of the page.

    mapped_base_reserved_mem = mmap(0, RESERVED_MEM_MAP_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, memfd_reserved_mem, dev_base & ~RESERVED_MEM_MAP_MASK);
        if (mapped_base_reserved_mem == (void *) -1) {
        printf("Can't map the memory to user space.\n");
        exit(0);
    }
     //printf("Memory mapped at address %p.\n", mapped_base_reserved_mem); 

    // get the address of the device in user space which will be an offset from the base 
    // that was mapped as memory is mapped at the start of a page 
    close(memfd_reserved_mem);
    mapped_dev_base = mapped_base_reserved_mem + (dev_base & RESERVED_MEM_MAP_MASK);
    return mapped_dev_base;
}


XVivado_activity_thread setup_XVivado_activity_thread(void)
{
    void *mapped_base_activity_thread;
    int memfd_activity_thread;

    void *mapped_dev_base;
    off_t dev_base = VIVADO_ACTIVITY_THREAD_ADDRESS;

    memfd_activity_thread = open("/dev/mem", O_RDWR | O_SYNC); //to open this the program needs to be run as root
        if (memfd_activity_thread == -1) {
        printf("Can't open /dev/mem.\n");
        exit(0);
    }

    // Map one page of memory into user space such that the device is in that page, but it may not
    // be at the start of the page.

    mapped_base_activity_thread = mmap(0, MAP_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, memfd_activity_thread, dev_base & ~MAP_MASK);
        if (mapped_base_activity_thread == (void *) -1) {
        printf("Can't map the memory to user space.\n");
        exit(0);
    }

    // get the address of the device in user space which will be an offset from the base 
    // that was mapped as memory is mapped at the start of a page 

    mapped_dev_base = mapped_base_activity_thread + (dev_base & MAP_MASK);
    XVivado_activity_thread device;
    close(memfd_activity_thread);
    device.Core_io_BaseAddress = mapped_dev_base;
    device.IsReady = XIL_COMPONENT_IS_READY;

    return device;
}

void vivado_activity_thread_hw(standard_underlying_attributes *kernel_u_a_0,standard_derivative_attributes *kernel_o_a_0,rng_state_t *seed_0,unsigned int thread_result_addr,XVivado_activity_thread *device_info)
{
        //volatile unsigned long * vivado_core_vbase = vivado_core_userspace();
        //XVivado_activity_thread  device_info;
//device_info = setup_XVivado_activity_thread();       

    	//------------------------------------AXI Master Setup------------------------------------------
        //printf("Writing to AXI master config registers.\n");
    	XVivado_activity_thread_SetThread_result_0(device_info, thread_result_addr); //Okay the base address is now set for the thread result into the AXI master
    	//printf("Thread Result Addr = 0x%X\n", XVivado_activity_thread_GetThread_result_0(&device_info));

    	//printf("\n\n");
        //------------------------------------INPUT SECTION---------------------------------------------
        //PASSING kernel_u_a_0 to the device
        XVivado_activity_thread_SetKernel_u_a_0_rfir(device_info, *(int*)&kernel_u_a_0->rfir);
        //printf("rfir: %f\n", kernel_u_a_0->rfir);
        XVivado_activity_thread_SetKernel_u_a_0_current_price(device_info, *(int*)&kernel_u_a_0->current_price);
        //printf("current_price: %f\n", kernel_u_a_0->current_price);
        XVivado_activity_thread_SetKernel_u_a_0_volatility(device_info, *(int*)&kernel_u_a_0->volatility);
        //printf("volatility: %f\n", kernel_u_a_0->volatility);
        XVivado_activity_thread_SetKernel_u_a_0_initial_volatility(device_info, *(int*)&kernel_u_a_0->initial_volatility);
        //printf("initial_volatility: %f\n", kernel_u_a_0->initial_volatility);
        XVivado_activity_thread_SetKernel_u_a_0_volatility_volatility(device_info, *(int*)&kernel_u_a_0->volatility_volatility);
        //printf("volatility_volatility: %f\n", kernel_u_a_0->volatility_volatility);
        XVivado_activity_thread_SetKernel_u_a_0_rho(device_info, *(int*)&kernel_u_a_0->rho);
        //printf("rho: %f\n", kernel_u_a_0->rho);
        XVivado_activity_thread_SetKernel_u_a_0_kappa(device_info, *(int*)&kernel_u_a_0->kappa);
        //printf("kappa: %f\n", kernel_u_a_0->kappa);
        XVivado_activity_thread_SetKernel_u_a_0_theta(device_info, *(int*)&kernel_u_a_0->theta);
        //printf("theta: %f\n", kernel_u_a_0->theta);
        XVivado_activity_thread_SetKernel_u_a_0_correlation_matrix_0_0(device_info, *(int*)&kernel_u_a_0->correlation_matrix_0_0);
        //printf("correlation_matrix_0_0: %f\n", kernel_u_a_0->correlation_matrix_0_0);
        XVivado_activity_thread_SetKernel_u_a_0_correlation_matrix_0_1(device_info, *(int*)&kernel_u_a_0->correlation_matrix_0_1);
        //printf("correlation_matrix_0_1: %f\n", kernel_u_a_0->correlation_matrix_0_1);
        XVivado_activity_thread_SetKernel_u_a_0_correlation_matrix_1_0(device_info, *(int*)&kernel_u_a_0->correlation_matrix_1_0);
        //printf("correlation_matrix_1_0: %f\n", kernel_u_a_0->correlation_matrix_1_0);
        XVivado_activity_thread_SetKernel_u_a_0_correlation_matrix_1_1(device_info, *(int*)&kernel_u_a_0->correlation_matrix_1_1);
        //printf("correlation_matrix_1_1: %f\n", kernel_u_a_0->correlation_matrix_1_1);

        //printf("\n\n");
        //PASSING kernel_o_a_0 to the device
        XVivado_activity_thread_SetKernel_o_a_0_second_barrier(device_info, *(int*)&kernel_o_a_0->second_barrier);
        //printf("second_barrier: %f\n", kernel_o_a_0->second_barrier);
        XVivado_activity_thread_SetKernel_o_a_0_barrier(device_info, *(int*)&kernel_o_a_0->barrier);
        //printf("barrier: %f\n", kernel_o_a_0->barrier);
        XVivado_activity_thread_SetKernel_o_a_0_out(device_info, *(int*)&kernel_o_a_0->out);
        //printf("out: %f\n", kernel_o_a_0->out);
        XVivado_activity_thread_SetKernel_o_a_0_down(device_info, *(int*)&kernel_o_a_0->down);
        //printf("down: %f\n", kernel_o_a_0->down);
        XVivado_activity_thread_SetKernel_o_a_0_strike_price(device_info, *(int*)&kernel_o_a_0->strike_price);
        //printf("strike_price: %f\n", kernel_o_a_0->strike_price);
        XVivado_activity_thread_SetKernel_o_a_0_time_period(device_info, *(int*)&kernel_o_a_0->time_period);
        //printf("time_period: %f\n", kernel_o_a_0->time_period);
        XVivado_activity_thread_SetKernel_o_a_0_call(device_info, *(int*)&kernel_o_a_0->call);
        //printf("call: %f\n", kernel_o_a_0->call);
        XVivado_activity_thread_SetKernel_o_a_0_points(device_info, *(int*)&kernel_o_a_0->points);
        //printf("points: %f\n", kernel_o_a_0->points);

        //printf("\n\n");
        //PASSING seed_0 to the device
        XVivado_activity_thread_SetSeed_0_s1(device_info, *(int*)&seed_0->s1);
        //printf("s1: %d\n", seed_0->s1);
        XVivado_activity_thread_SetSeed_0_s2(device_info, *(int*)&seed_0->s2);
        //printf("s2: %d\n", seed_0->s2);
        XVivado_activity_thread_SetSeed_0_s3(device_info, *(int*)&seed_0->s3);
        //printf("s3: %d\n", seed_0->s3);
        XVivado_activity_thread_SetSeed_0_offset(device_info, *(int*)&seed_0->offset);
        //printf("offset: %d\n", seed_0->offset);

        //printf("\n\n");
        XVivado_activity_thread_Start(device_info); //Kick the device into starting
        //usleep(2000);
        //while(XVivado_activity_thread_IsDone(&device_info) != 1) { } //Waiting for the operation to complete

        //u32 temp_thread_result_0 = XVivado_activity_thread_GetThread_result_0(&device_info);
        //u32 temp_thread_result_sqrd_0 = XVivado_activity_thread_GetThread_result_sqrd_0(&device_info);

        //Converting the results to float and outputting
        //*thread_result_0 = *(float*)&temp_thread_result_0;
        //*thread_result_sqrd_0 = *(float*)&temp_thread_result_sqrd_0;
}

void xVivado_activity_thread_Wait(XVivado_activity_thread *device_info){
	while(XVivado_activity_thread_IsDone(device_info) != 1) { }
}



void XVivado_activity_thread_Start(XVivado_activity_thread *InstancePtr) {
    u32 Data;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XVivado_activity_thread_ReadReg(InstancePtr->Core_io_BaseAddress, XVIVADO_ACTIVITY_THREAD_CORE_IO_ADDR_AP_CTRL) & 0x80;
    XVivado_activity_thread_WriteReg(InstancePtr->Core_io_BaseAddress, XVIVADO_ACTIVITY_THREAD_CORE_IO_ADDR_AP_CTRL, Data | 0x01);
}

u32 XVivado_activity_thread_IsDone(XVivado_activity_thread *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XVivado_activity_thread_ReadReg(InstancePtr->Core_io_BaseAddress, XVIVADO_ACTIVITY_THREAD_CORE_IO_ADDR_AP_CTRL);
    return (Data >> 1) & 0x1;
}

u32 XVivado_activity_thread_IsIdle(XVivado_activity_thread *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XVivado_activity_thread_ReadReg(InstancePtr->Core_io_BaseAddress, XVIVADO_ACTIVITY_THREAD_CORE_IO_ADDR_AP_CTRL);
    return (Data >> 2) & 0x1;
}

u32 XVivado_activity_thread_IsReady(XVivado_activity_thread *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XVivado_activity_thread_ReadReg(InstancePtr->Core_io_BaseAddress, XVIVADO_ACTIVITY_THREAD_CORE_IO_ADDR_AP_CTRL);
    // check ap_start to see if the pcore is ready for next input
    return !(Data & 0x1);
}

void XVivado_activity_thread_EnableAutoRestart(XVivado_activity_thread *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XVivado_activity_thread_WriteReg(InstancePtr->Core_io_BaseAddress, XVIVADO_ACTIVITY_THREAD_CORE_IO_ADDR_AP_CTRL, 0x80);
}

void XVivado_activity_thread_DisableAutoRestart(XVivado_activity_thread *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XVivado_activity_thread_WriteReg(InstancePtr->Core_io_BaseAddress, XVIVADO_ACTIVITY_THREAD_CORE_IO_ADDR_AP_CTRL, 0);
}

void XVivado_activity_thread_SetKernel_u_a_0_rfir(XVivado_activity_thread *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XVivado_activity_thread_WriteReg(InstancePtr->Core_io_BaseAddress, XVIVADO_ACTIVITY_THREAD_CORE_IO_ADDR_KERNEL_U_A_0_RFIR_DATA, Data);
}

u32 XVivado_activity_thread_GetKernel_u_a_0_rfir(XVivado_activity_thread *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XVivado_activity_thread_ReadReg(InstancePtr->Core_io_BaseAddress, XVIVADO_ACTIVITY_THREAD_CORE_IO_ADDR_KERNEL_U_A_0_RFIR_DATA);
    return Data;
}

void XVivado_activity_thread_SetKernel_u_a_0_current_price(XVivado_activity_thread *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XVivado_activity_thread_WriteReg(InstancePtr->Core_io_BaseAddress, XVIVADO_ACTIVITY_THREAD_CORE_IO_ADDR_KERNEL_U_A_0_CURRENT_PRICE_DATA, Data);
}

u32 XVivado_activity_thread_GetKernel_u_a_0_current_price(XVivado_activity_thread *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XVivado_activity_thread_ReadReg(InstancePtr->Core_io_BaseAddress, XVIVADO_ACTIVITY_THREAD_CORE_IO_ADDR_KERNEL_U_A_0_CURRENT_PRICE_DATA);
    return Data;
}

void XVivado_activity_thread_SetKernel_u_a_0_volatility(XVivado_activity_thread *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XVivado_activity_thread_WriteReg(InstancePtr->Core_io_BaseAddress, XVIVADO_ACTIVITY_THREAD_CORE_IO_ADDR_KERNEL_U_A_0_VOLATILITY_DATA, Data);
}

u32 XVivado_activity_thread_GetKernel_u_a_0_volatility(XVivado_activity_thread *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XVivado_activity_thread_ReadReg(InstancePtr->Core_io_BaseAddress, XVIVADO_ACTIVITY_THREAD_CORE_IO_ADDR_KERNEL_U_A_0_VOLATILITY_DATA);
    return Data;
}

void XVivado_activity_thread_SetKernel_u_a_0_initial_volatility(XVivado_activity_thread *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XVivado_activity_thread_WriteReg(InstancePtr->Core_io_BaseAddress, XVIVADO_ACTIVITY_THREAD_CORE_IO_ADDR_KERNEL_U_A_0_INITIAL_VOLATILITY_DATA, Data);
}

u32 XVivado_activity_thread_GetKernel_u_a_0_initial_volatility(XVivado_activity_thread *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XVivado_activity_thread_ReadReg(InstancePtr->Core_io_BaseAddress, XVIVADO_ACTIVITY_THREAD_CORE_IO_ADDR_KERNEL_U_A_0_INITIAL_VOLATILITY_DATA);
    return Data;
}

void XVivado_activity_thread_SetKernel_u_a_0_volatility_volatility(XVivado_activity_thread *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XVivado_activity_thread_WriteReg(InstancePtr->Core_io_BaseAddress, XVIVADO_ACTIVITY_THREAD_CORE_IO_ADDR_KERNEL_U_A_0_VOLATILITY_VOLATILITY_DATA, Data);
}

u32 XVivado_activity_thread_GetKernel_u_a_0_volatility_volatility(XVivado_activity_thread *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XVivado_activity_thread_ReadReg(InstancePtr->Core_io_BaseAddress, XVIVADO_ACTIVITY_THREAD_CORE_IO_ADDR_KERNEL_U_A_0_VOLATILITY_VOLATILITY_DATA);
    return Data;
}

void XVivado_activity_thread_SetKernel_u_a_0_rho(XVivado_activity_thread *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XVivado_activity_thread_WriteReg(InstancePtr->Core_io_BaseAddress, XVIVADO_ACTIVITY_THREAD_CORE_IO_ADDR_KERNEL_U_A_0_RHO_DATA, Data);
}

u32 XVivado_activity_thread_GetKernel_u_a_0_rho(XVivado_activity_thread *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XVivado_activity_thread_ReadReg(InstancePtr->Core_io_BaseAddress, XVIVADO_ACTIVITY_THREAD_CORE_IO_ADDR_KERNEL_U_A_0_RHO_DATA);
    return Data;
}

void XVivado_activity_thread_SetKernel_u_a_0_kappa(XVivado_activity_thread *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XVivado_activity_thread_WriteReg(InstancePtr->Core_io_BaseAddress, XVIVADO_ACTIVITY_THREAD_CORE_IO_ADDR_KERNEL_U_A_0_KAPPA_DATA, Data);
}

u32 XVivado_activity_thread_GetKernel_u_a_0_kappa(XVivado_activity_thread *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XVivado_activity_thread_ReadReg(InstancePtr->Core_io_BaseAddress, XVIVADO_ACTIVITY_THREAD_CORE_IO_ADDR_KERNEL_U_A_0_KAPPA_DATA);
    return Data;
}

void XVivado_activity_thread_SetKernel_u_a_0_theta(XVivado_activity_thread *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XVivado_activity_thread_WriteReg(InstancePtr->Core_io_BaseAddress, XVIVADO_ACTIVITY_THREAD_CORE_IO_ADDR_KERNEL_U_A_0_THETA_DATA, Data);
}

u32 XVivado_activity_thread_GetKernel_u_a_0_theta(XVivado_activity_thread *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XVivado_activity_thread_ReadReg(InstancePtr->Core_io_BaseAddress, XVIVADO_ACTIVITY_THREAD_CORE_IO_ADDR_KERNEL_U_A_0_THETA_DATA);
    return Data;
}

void XVivado_activity_thread_SetKernel_u_a_0_correlation_matrix_0_0(XVivado_activity_thread *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XVivado_activity_thread_WriteReg(InstancePtr->Core_io_BaseAddress, XVIVADO_ACTIVITY_THREAD_CORE_IO_ADDR_KERNEL_U_A_0_CORRELATION_MATRIX_0_0_DATA, Data);
}

u32 XVivado_activity_thread_GetKernel_u_a_0_correlation_matrix_0_0(XVivado_activity_thread *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XVivado_activity_thread_ReadReg(InstancePtr->Core_io_BaseAddress, XVIVADO_ACTIVITY_THREAD_CORE_IO_ADDR_KERNEL_U_A_0_CORRELATION_MATRIX_0_0_DATA);
    return Data;
}

void XVivado_activity_thread_SetKernel_u_a_0_correlation_matrix_0_1(XVivado_activity_thread *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XVivado_activity_thread_WriteReg(InstancePtr->Core_io_BaseAddress, XVIVADO_ACTIVITY_THREAD_CORE_IO_ADDR_KERNEL_U_A_0_CORRELATION_MATRIX_0_1_DATA, Data);
}

u32 XVivado_activity_thread_GetKernel_u_a_0_correlation_matrix_0_1(XVivado_activity_thread *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XVivado_activity_thread_ReadReg(InstancePtr->Core_io_BaseAddress, XVIVADO_ACTIVITY_THREAD_CORE_IO_ADDR_KERNEL_U_A_0_CORRELATION_MATRIX_0_1_DATA);
    return Data;
}

void XVivado_activity_thread_SetKernel_u_a_0_correlation_matrix_1_0(XVivado_activity_thread *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XVivado_activity_thread_WriteReg(InstancePtr->Core_io_BaseAddress, XVIVADO_ACTIVITY_THREAD_CORE_IO_ADDR_KERNEL_U_A_0_CORRELATION_MATRIX_1_0_DATA, Data);
}

u32 XVivado_activity_thread_GetKernel_u_a_0_correlation_matrix_1_0(XVivado_activity_thread *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XVivado_activity_thread_ReadReg(InstancePtr->Core_io_BaseAddress, XVIVADO_ACTIVITY_THREAD_CORE_IO_ADDR_KERNEL_U_A_0_CORRELATION_MATRIX_1_0_DATA);
    return Data;
}

void XVivado_activity_thread_SetKernel_u_a_0_correlation_matrix_1_1(XVivado_activity_thread *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XVivado_activity_thread_WriteReg(InstancePtr->Core_io_BaseAddress, XVIVADO_ACTIVITY_THREAD_CORE_IO_ADDR_KERNEL_U_A_0_CORRELATION_MATRIX_1_1_DATA, Data);
}

u32 XVivado_activity_thread_GetKernel_u_a_0_correlation_matrix_1_1(XVivado_activity_thread *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XVivado_activity_thread_ReadReg(InstancePtr->Core_io_BaseAddress, XVIVADO_ACTIVITY_THREAD_CORE_IO_ADDR_KERNEL_U_A_0_CORRELATION_MATRIX_1_1_DATA);
    return Data;
}

void XVivado_activity_thread_SetKernel_o_a_0_second_barrier(XVivado_activity_thread *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XVivado_activity_thread_WriteReg(InstancePtr->Core_io_BaseAddress, XVIVADO_ACTIVITY_THREAD_CORE_IO_ADDR_KERNEL_O_A_0_SECOND_BARRIER_DATA, Data);
}

u32 XVivado_activity_thread_GetKernel_o_a_0_second_barrier(XVivado_activity_thread *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XVivado_activity_thread_ReadReg(InstancePtr->Core_io_BaseAddress, XVIVADO_ACTIVITY_THREAD_CORE_IO_ADDR_KERNEL_O_A_0_SECOND_BARRIER_DATA);
    return Data;
}

void XVivado_activity_thread_SetKernel_o_a_0_barrier(XVivado_activity_thread *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XVivado_activity_thread_WriteReg(InstancePtr->Core_io_BaseAddress, XVIVADO_ACTIVITY_THREAD_CORE_IO_ADDR_KERNEL_O_A_0_BARRIER_DATA, Data);
}

u32 XVivado_activity_thread_GetKernel_o_a_0_barrier(XVivado_activity_thread *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XVivado_activity_thread_ReadReg(InstancePtr->Core_io_BaseAddress, XVIVADO_ACTIVITY_THREAD_CORE_IO_ADDR_KERNEL_O_A_0_BARRIER_DATA);
    return Data;
}

void XVivado_activity_thread_SetKernel_o_a_0_out(XVivado_activity_thread *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XVivado_activity_thread_WriteReg(InstancePtr->Core_io_BaseAddress, XVIVADO_ACTIVITY_THREAD_CORE_IO_ADDR_KERNEL_O_A_0_OUT_DATA, Data);
}

u32 XVivado_activity_thread_GetKernel_o_a_0_out(XVivado_activity_thread *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XVivado_activity_thread_ReadReg(InstancePtr->Core_io_BaseAddress, XVIVADO_ACTIVITY_THREAD_CORE_IO_ADDR_KERNEL_O_A_0_OUT_DATA);
    return Data;
}

void XVivado_activity_thread_SetKernel_o_a_0_down(XVivado_activity_thread *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XVivado_activity_thread_WriteReg(InstancePtr->Core_io_BaseAddress, XVIVADO_ACTIVITY_THREAD_CORE_IO_ADDR_KERNEL_O_A_0_DOWN_DATA, Data);
}

u32 XVivado_activity_thread_GetKernel_o_a_0_down(XVivado_activity_thread *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XVivado_activity_thread_ReadReg(InstancePtr->Core_io_BaseAddress, XVIVADO_ACTIVITY_THREAD_CORE_IO_ADDR_KERNEL_O_A_0_DOWN_DATA);
    return Data;
}

void XVivado_activity_thread_SetKernel_o_a_0_strike_price(XVivado_activity_thread *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XVivado_activity_thread_WriteReg(InstancePtr->Core_io_BaseAddress, XVIVADO_ACTIVITY_THREAD_CORE_IO_ADDR_KERNEL_O_A_0_STRIKE_PRICE_DATA, Data);
}

u32 XVivado_activity_thread_GetKernel_o_a_0_strike_price(XVivado_activity_thread *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XVivado_activity_thread_ReadReg(InstancePtr->Core_io_BaseAddress, XVIVADO_ACTIVITY_THREAD_CORE_IO_ADDR_KERNEL_O_A_0_STRIKE_PRICE_DATA);
    return Data;
}

void XVivado_activity_thread_SetKernel_o_a_0_time_period(XVivado_activity_thread *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XVivado_activity_thread_WriteReg(InstancePtr->Core_io_BaseAddress, XVIVADO_ACTIVITY_THREAD_CORE_IO_ADDR_KERNEL_O_A_0_TIME_PERIOD_DATA, Data);
}

u32 XVivado_activity_thread_GetKernel_o_a_0_time_period(XVivado_activity_thread *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XVivado_activity_thread_ReadReg(InstancePtr->Core_io_BaseAddress, XVIVADO_ACTIVITY_THREAD_CORE_IO_ADDR_KERNEL_O_A_0_TIME_PERIOD_DATA);
    return Data;
}

void XVivado_activity_thread_SetKernel_o_a_0_call(XVivado_activity_thread *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XVivado_activity_thread_WriteReg(InstancePtr->Core_io_BaseAddress, XVIVADO_ACTIVITY_THREAD_CORE_IO_ADDR_KERNEL_O_A_0_CALL_DATA, Data);
}

u32 XVivado_activity_thread_GetKernel_o_a_0_call(XVivado_activity_thread *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XVivado_activity_thread_ReadReg(InstancePtr->Core_io_BaseAddress, XVIVADO_ACTIVITY_THREAD_CORE_IO_ADDR_KERNEL_O_A_0_CALL_DATA);
    return Data;
}

void XVivado_activity_thread_SetKernel_o_a_0_points(XVivado_activity_thread *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XVivado_activity_thread_WriteReg(InstancePtr->Core_io_BaseAddress, XVIVADO_ACTIVITY_THREAD_CORE_IO_ADDR_KERNEL_O_A_0_POINTS_DATA, Data);
}

u32 XVivado_activity_thread_GetKernel_o_a_0_points(XVivado_activity_thread *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XVivado_activity_thread_ReadReg(InstancePtr->Core_io_BaseAddress, XVIVADO_ACTIVITY_THREAD_CORE_IO_ADDR_KERNEL_O_A_0_POINTS_DATA);
    return Data;
}

void XVivado_activity_thread_SetSeed_0_s1(XVivado_activity_thread *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XVivado_activity_thread_WriteReg(InstancePtr->Core_io_BaseAddress, XVIVADO_ACTIVITY_THREAD_CORE_IO_ADDR_SEED_0_S1_DATA, Data);
}

u32 XVivado_activity_thread_GetSeed_0_s1(XVivado_activity_thread *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XVivado_activity_thread_ReadReg(InstancePtr->Core_io_BaseAddress, XVIVADO_ACTIVITY_THREAD_CORE_IO_ADDR_SEED_0_S1_DATA);
    return Data;
}

void XVivado_activity_thread_SetSeed_0_s2(XVivado_activity_thread *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XVivado_activity_thread_WriteReg(InstancePtr->Core_io_BaseAddress, XVIVADO_ACTIVITY_THREAD_CORE_IO_ADDR_SEED_0_S2_DATA, Data);
}

u32 XVivado_activity_thread_GetSeed_0_s2(XVivado_activity_thread *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XVivado_activity_thread_ReadReg(InstancePtr->Core_io_BaseAddress, XVIVADO_ACTIVITY_THREAD_CORE_IO_ADDR_SEED_0_S2_DATA);
    return Data;
}

void XVivado_activity_thread_SetSeed_0_s3(XVivado_activity_thread *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XVivado_activity_thread_WriteReg(InstancePtr->Core_io_BaseAddress, XVIVADO_ACTIVITY_THREAD_CORE_IO_ADDR_SEED_0_S3_DATA, Data);
}

u32 XVivado_activity_thread_GetSeed_0_s3(XVivado_activity_thread *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XVivado_activity_thread_ReadReg(InstancePtr->Core_io_BaseAddress, XVIVADO_ACTIVITY_THREAD_CORE_IO_ADDR_SEED_0_S3_DATA);
    return Data;
}

void XVivado_activity_thread_SetSeed_0_offset(XVivado_activity_thread *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XVivado_activity_thread_WriteReg(InstancePtr->Core_io_BaseAddress, XVIVADO_ACTIVITY_THREAD_CORE_IO_ADDR_SEED_0_OFFSET_DATA, Data);
}

u32 XVivado_activity_thread_GetSeed_0_offset(XVivado_activity_thread *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XVivado_activity_thread_ReadReg(InstancePtr->Core_io_BaseAddress, XVIVADO_ACTIVITY_THREAD_CORE_IO_ADDR_SEED_0_OFFSET_DATA);
    return Data;
}

void XVivado_activity_thread_SetThread_result_0(XVivado_activity_thread *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XVivado_activity_thread_WriteReg(InstancePtr->Core_io_BaseAddress, XVIVADO_ACTIVITY_THREAD_CORE_IO_ADDR_THREAD_RESULT_0_DATA, Data);
}

u32 XVivado_activity_thread_GetThread_result_0(XVivado_activity_thread *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XVivado_activity_thread_ReadReg(InstancePtr->Core_io_BaseAddress, XVIVADO_ACTIVITY_THREAD_CORE_IO_ADDR_THREAD_RESULT_0_DATA);
    return Data;
}

void XVivado_activity_thread_InterruptGlobalEnable(XVivado_activity_thread *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XVivado_activity_thread_WriteReg(InstancePtr->Core_io_BaseAddress, XVIVADO_ACTIVITY_THREAD_CORE_IO_ADDR_GIE, 1);
}

void XVivado_activity_thread_InterruptGlobalDisable(XVivado_activity_thread *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XVivado_activity_thread_WriteReg(InstancePtr->Core_io_BaseAddress, XVIVADO_ACTIVITY_THREAD_CORE_IO_ADDR_GIE, 0);
}

void XVivado_activity_thread_InterruptEnable(XVivado_activity_thread *InstancePtr, u32 Mask) {
    u32 Register;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Register =  XVivado_activity_thread_ReadReg(InstancePtr->Core_io_BaseAddress, XVIVADO_ACTIVITY_THREAD_CORE_IO_ADDR_IER);
    XVivado_activity_thread_WriteReg(InstancePtr->Core_io_BaseAddress, XVIVADO_ACTIVITY_THREAD_CORE_IO_ADDR_IER, Register | Mask);
}

void XVivado_activity_thread_InterruptDisable(XVivado_activity_thread *InstancePtr, u32 Mask) {
    u32 Register;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Register =  XVivado_activity_thread_ReadReg(InstancePtr->Core_io_BaseAddress, XVIVADO_ACTIVITY_THREAD_CORE_IO_ADDR_IER);
    XVivado_activity_thread_WriteReg(InstancePtr->Core_io_BaseAddress, XVIVADO_ACTIVITY_THREAD_CORE_IO_ADDR_IER, Register & (~Mask));
}

void XVivado_activity_thread_InterruptClear(XVivado_activity_thread *InstancePtr, u32 Mask) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XVivado_activity_thread_WriteReg(InstancePtr->Core_io_BaseAddress, XVIVADO_ACTIVITY_THREAD_CORE_IO_ADDR_ISR, Mask);
}

u32 XVivado_activity_thread_InterruptGetEnabled(XVivado_activity_thread *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XVivado_activity_thread_ReadReg(InstancePtr->Core_io_BaseAddress, XVIVADO_ACTIVITY_THREAD_CORE_IO_ADDR_IER);
}

u32 XVivado_activity_thread_InterruptGetStatus(XVivado_activity_thread *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XVivado_activity_thread_ReadReg(InstancePtr->Core_io_BaseAddress, XVIVADO_ACTIVITY_THREAD_CORE_IO_ADDR_ISR);
}
