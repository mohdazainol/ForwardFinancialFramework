// ==============================================================
// File generated by Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC
// Version: 2013.3
// Copyright (C) 2013 Xilinx Inc. All rights reserved.
// 
// ==============================================================

#ifndef __linux__

#include "xstatus.h"
#include "xparameters.h"
#include "xvivado_activity_thread.h"

extern XVivado_activity_thread_Config XVivado_activity_thread_ConfigTable[];

XVivado_activity_thread_Config *XVivado_activity_thread_LookupConfig(u16 DeviceId) {
	XVivado_activity_thread_Config *ConfigPtr = NULL;

	int Index;

	for (Index = 0; Index < XPAR_XVIVADO_ACTIVITY_THREAD_NUM_INSTANCES; Index++) {
		if (XVivado_activity_thread_ConfigTable[Index].DeviceId == DeviceId) {
			ConfigPtr = &XVivado_activity_thread_ConfigTable[Index];
			break;
		}
	}

	return ConfigPtr;
}

int XVivado_activity_thread_Initialize(XVivado_activity_thread *InstancePtr, u16 DeviceId) {
	XVivado_activity_thread_Config *ConfigPtr;

	Xil_AssertNonvoid(InstancePtr != NULL);

	ConfigPtr = XVivado_activity_thread_LookupConfig(DeviceId);
	if (ConfigPtr == NULL) {
		InstancePtr->IsReady = 0;
		return (XST_DEVICE_NOT_FOUND);
	}

	return XVivado_activity_thread_CfgInitialize(InstancePtr, ConfigPtr);
}

#endif

