// ==============================================================
// Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2024.1 (64-bit)
// Tool Version Limit: 2024.05
// Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
// Copyright 2022-2024 Advanced Micro Devices, Inc. All Rights Reserved.
// 
// ==============================================================
#ifndef __linux__

#include "xstatus.h"
#ifdef SDT
#include "xparameters.h"
#endif
#include "xvadd.h"

extern XVadd_Config XVadd_ConfigTable[];

#ifdef SDT
XVadd_Config *XVadd_LookupConfig(UINTPTR BaseAddress) {
	XVadd_Config *ConfigPtr = NULL;

	int Index;

	for (Index = (u32)0x0; XVadd_ConfigTable[Index].Name != NULL; Index++) {
		if (!BaseAddress || XVadd_ConfigTable[Index].Control_BaseAddress == BaseAddress) {
			ConfigPtr = &XVadd_ConfigTable[Index];
			break;
		}
	}

	return ConfigPtr;
}

int XVadd_Initialize(XVadd *InstancePtr, UINTPTR BaseAddress) {
	XVadd_Config *ConfigPtr;

	Xil_AssertNonvoid(InstancePtr != NULL);

	ConfigPtr = XVadd_LookupConfig(BaseAddress);
	if (ConfigPtr == NULL) {
		InstancePtr->IsReady = 0;
		return (XST_DEVICE_NOT_FOUND);
	}

	return XVadd_CfgInitialize(InstancePtr, ConfigPtr);
}
#else
XVadd_Config *XVadd_LookupConfig(u16 DeviceId) {
	XVadd_Config *ConfigPtr = NULL;

	int Index;

	for (Index = 0; Index < XPAR_XVADD_NUM_INSTANCES; Index++) {
		if (XVadd_ConfigTable[Index].DeviceId == DeviceId) {
			ConfigPtr = &XVadd_ConfigTable[Index];
			break;
		}
	}

	return ConfigPtr;
}

int XVadd_Initialize(XVadd *InstancePtr, u16 DeviceId) {
	XVadd_Config *ConfigPtr;

	Xil_AssertNonvoid(InstancePtr != NULL);

	ConfigPtr = XVadd_LookupConfig(DeviceId);
	if (ConfigPtr == NULL) {
		InstancePtr->IsReady = 0;
		return (XST_DEVICE_NOT_FOUND);
	}

	return XVadd_CfgInitialize(InstancePtr, ConfigPtr);
}
#endif

#endif

