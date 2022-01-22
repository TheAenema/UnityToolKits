#include <Windows.h>

// D3D11 Typedefs
typedef HRESULT(*D3D11CreateDeviceFunc)(uintptr_t pAdapter, int DriverType, HMODULE Software,
	UINT Flags, uintptr_t pFeatureLevels, UINT FeatureLevels, UINT SDKVersion,
	void** ppDevice, uintptr_t pFeatureLevel, void** ppImmediateContext);

typedef enum D3D11_CREATE_DEVICE_FLAG 
{
	D3D11_CREATE_DEVICE_SINGLETHREADED,
	D3D11_CREATE_DEVICE_DEBUG,
	D3D11_CREATE_DEVICE_SWITCH_TO_REF,
	D3D11_CREATE_DEVICE_PREVENT_INTERNAL_THREADING_OPTIMIZATIONS,
	D3D11_CREATE_DEVICE_BGRA_SUPPORT,
	D3D11_CREATE_DEVICE_DEBUGGABLE,
	D3D11_CREATE_DEVICE_PREVENT_ALTERING_LAYER_SETTINGS_FROM_REGISTRY,
	D3D11_CREATE_DEVICE_DISABLE_GPU_TIMEOUT,
	D3D11_CREATE_DEVICE_VIDEO_SUPPORT
};

#pragma region Proxy
struct d3d11_dll {
	HMODULE dll;
	FARPROC oCreateDirect3D11DeviceFromDXGIDevice;
	FARPROC oCreateDirect3D11SurfaceFromDXGISurface;
	FARPROC oD3D11CoreCreateDevice;
	FARPROC oD3D11CoreCreateLayeredDevice;
	FARPROC oD3D11CoreGetLayeredDeviceSize;
	FARPROC oD3D11CoreRegisterLayers;
	FARPROC oD3D11CreateDevice;
	FARPROC oD3D11CreateDeviceAndSwapChain;
	FARPROC oD3D11CreateDeviceForD3D12;
	FARPROC oD3D11On12CreateDevice;
	FARPROC oD3DKMTCloseAdapter;
	FARPROC oD3DKMTCreateAllocation;
	FARPROC oD3DKMTCreateContext;
	FARPROC oD3DKMTCreateDevice;
	FARPROC oD3DKMTCreateSynchronizationObject;
	FARPROC oD3DKMTDestroyAllocation;
	FARPROC oD3DKMTDestroyContext;
	FARPROC oD3DKMTDestroyDevice;
	FARPROC oD3DKMTDestroySynchronizationObject;
	FARPROC oD3DKMTEscape;
	FARPROC oD3DKMTGetContextSchedulingPriority;
	FARPROC oD3DKMTGetDeviceState;
	FARPROC oD3DKMTGetDisplayModeList;
	FARPROC oD3DKMTGetMultisampleMethodList;
	FARPROC oD3DKMTGetRuntimeData;
	FARPROC oD3DKMTGetSharedPrimaryHandle;
	FARPROC oD3DKMTLock;
	FARPROC oD3DKMTOpenAdapterFromHdc;
	FARPROC oD3DKMTOpenResource;
	FARPROC oD3DKMTPresent;
	FARPROC oD3DKMTQueryAdapterInfo;
	FARPROC oD3DKMTQueryAllocationResidency;
	FARPROC oD3DKMTQueryResourceInfo;
	FARPROC oD3DKMTRender;
	FARPROC oD3DKMTSetAllocationPriority;
	FARPROC oD3DKMTSetContextSchedulingPriority;
	FARPROC oD3DKMTSetDisplayMode;
	FARPROC oD3DKMTSetDisplayPrivateDriverFormat;
	FARPROC oD3DKMTSetGammaRamp;
	FARPROC oD3DKMTSetVidPnSourceOwner;
	FARPROC oD3DKMTSignalSynchronizationObject;
	FARPROC oD3DKMTUnlock;
	FARPROC oD3DKMTWaitForSynchronizationObject;
	FARPROC oD3DKMTWaitForVerticalBlankEvent;
	FARPROC oD3DPerformance_BeginEvent;
	FARPROC oD3DPerformance_EndEvent;
	FARPROC oD3DPerformance_GetStatus;
	FARPROC oD3DPerformance_SetMarker;
	FARPROC oEnableFeatureLevelUpgrade;
	FARPROC oOpenAdapter10;
	FARPROC oOpenAdapter10_2;
} d3d11;

// API Table
extern "C" {
	FARPROC PA = 0;
	int runASM();

	// Hooked Functions
	HRESULT fD3D11CreateDevice(uintptr_t pAdapter, int DriverType, HMODULE Software,
		UINT Flags, uintptr_t pFeatureLevels, UINT FeatureLevels, UINT SDKVersion,
		void** ppDevice, uintptr_t pFeatureLevel, void** ppImmediateContext)
	{ 
		D3D11CreateDeviceFunc funOriginal = (D3D11CreateDeviceFunc)d3d11.oD3D11CreateDevice;

		// Add Debug Flag
		UINT altredFlags = Flags;
		altredFlags |= D3D11_CREATE_DEVICE_DEBUG;
		altredFlags |= D3D11_CREATE_DEVICE_DEBUGGABLE;
		return funOriginal(pAdapter, DriverType, Software, altredFlags, pFeatureLevels, FeatureLevels, SDKVersion, ppDevice, pFeatureLevel, ppImmediateContext);
	}

	// Original Functions
	void fCreateDirect3D11DeviceFromDXGIDevice() { PA = d3d11.oCreateDirect3D11DeviceFromDXGIDevice; runASM(); }
	void fCreateDirect3D11SurfaceFromDXGISurface() { PA = d3d11.oCreateDirect3D11SurfaceFromDXGISurface; runASM(); }
	void fD3D11CoreCreateDevice() { PA = d3d11.oD3D11CoreCreateDevice; runASM(); }
	void fD3D11CoreCreateLayeredDevice() { PA = d3d11.oD3D11CoreCreateLayeredDevice; runASM(); }
	void fD3D11CoreGetLayeredDeviceSize() { PA = d3d11.oD3D11CoreGetLayeredDeviceSize; runASM(); }
	void fD3D11CoreRegisterLayers() { PA = d3d11.oD3D11CoreRegisterLayers; runASM(); }
	void fD3D11CreateDeviceAndSwapChain() { PA = d3d11.oD3D11CreateDeviceAndSwapChain; runASM(); }
	void fD3D11CreateDeviceForD3D12() { PA = d3d11.oD3D11CreateDeviceForD3D12; runASM(); }
	void fD3D11On12CreateDevice() { PA = d3d11.oD3D11On12CreateDevice; runASM(); }
	void fD3DKMTCloseAdapter() { PA = d3d11.oD3DKMTCloseAdapter; runASM(); }
	void fD3DKMTCreateAllocation() { PA = d3d11.oD3DKMTCreateAllocation; runASM(); }
	void fD3DKMTCreateContext() { PA = d3d11.oD3DKMTCreateContext; runASM(); }
	void fD3DKMTCreateDevice() { PA = d3d11.oD3DKMTCreateDevice; runASM(); }
	void fD3DKMTCreateSynchronizationObject() { PA = d3d11.oD3DKMTCreateSynchronizationObject; runASM(); }
	void fD3DKMTDestroyAllocation() { PA = d3d11.oD3DKMTDestroyAllocation; runASM(); }
	void fD3DKMTDestroyContext() { PA = d3d11.oD3DKMTDestroyContext; runASM(); }
	void fD3DKMTDestroyDevice() { PA = d3d11.oD3DKMTDestroyDevice; runASM(); }
	void fD3DKMTDestroySynchronizationObject() { PA = d3d11.oD3DKMTDestroySynchronizationObject; runASM(); }
	void fD3DKMTEscape() { PA = d3d11.oD3DKMTEscape; runASM(); }
	void fD3DKMTGetContextSchedulingPriority() { PA = d3d11.oD3DKMTGetContextSchedulingPriority; runASM(); }
	void fD3DKMTGetDeviceState() { PA = d3d11.oD3DKMTGetDeviceState; runASM(); }
	void fD3DKMTGetDisplayModeList() { PA = d3d11.oD3DKMTGetDisplayModeList; runASM(); }
	void fD3DKMTGetMultisampleMethodList() { PA = d3d11.oD3DKMTGetMultisampleMethodList; runASM(); }
	void fD3DKMTGetRuntimeData() { PA = d3d11.oD3DKMTGetRuntimeData; runASM(); }
	void fD3DKMTGetSharedPrimaryHandle() { PA = d3d11.oD3DKMTGetSharedPrimaryHandle; runASM(); }
	void fD3DKMTLock() { PA = d3d11.oD3DKMTLock; runASM(); }
	void fD3DKMTOpenAdapterFromHdc() { PA = d3d11.oD3DKMTOpenAdapterFromHdc; runASM(); }
	void fD3DKMTOpenResource() { PA = d3d11.oD3DKMTOpenResource; runASM(); }
	void fD3DKMTPresent() { PA = d3d11.oD3DKMTPresent; runASM(); }
	void fD3DKMTQueryAdapterInfo() { PA = d3d11.oD3DKMTQueryAdapterInfo; runASM(); }
	void fD3DKMTQueryAllocationResidency() { PA = d3d11.oD3DKMTQueryAllocationResidency; runASM(); }
	void fD3DKMTQueryResourceInfo() { PA = d3d11.oD3DKMTQueryResourceInfo; runASM(); }
	void fD3DKMTRender() { PA = d3d11.oD3DKMTRender; runASM(); }
	void fD3DKMTSetAllocationPriority() { PA = d3d11.oD3DKMTSetAllocationPriority; runASM(); }
	void fD3DKMTSetContextSchedulingPriority() { PA = d3d11.oD3DKMTSetContextSchedulingPriority; runASM(); }
	void fD3DKMTSetDisplayMode() { PA = d3d11.oD3DKMTSetDisplayMode; runASM(); }
	void fD3DKMTSetDisplayPrivateDriverFormat() { PA = d3d11.oD3DKMTSetDisplayPrivateDriverFormat; runASM(); }
	void fD3DKMTSetGammaRamp() { PA = d3d11.oD3DKMTSetGammaRamp; runASM(); }
	void fD3DKMTSetVidPnSourceOwner() { PA = d3d11.oD3DKMTSetVidPnSourceOwner; runASM(); }
	void fD3DKMTSignalSynchronizationObject() { PA = d3d11.oD3DKMTSignalSynchronizationObject; runASM(); }
	void fD3DKMTUnlock() { PA = d3d11.oD3DKMTUnlock; runASM(); }
	void fD3DKMTWaitForSynchronizationObject() { PA = d3d11.oD3DKMTWaitForSynchronizationObject; runASM(); }
	void fD3DKMTWaitForVerticalBlankEvent() { PA = d3d11.oD3DKMTWaitForVerticalBlankEvent; runASM(); }
	void fD3DPerformance_BeginEvent() { PA = d3d11.oD3DPerformance_BeginEvent; runASM(); }
	void fD3DPerformance_EndEvent() { PA = d3d11.oD3DPerformance_EndEvent; runASM(); }
	void fD3DPerformance_GetStatus() { PA = d3d11.oD3DPerformance_GetStatus; runASM(); }
	void fD3DPerformance_SetMarker() { PA = d3d11.oD3DPerformance_SetMarker; runASM(); }
	void fEnableFeatureLevelUpgrade() { PA = d3d11.oEnableFeatureLevelUpgrade; runASM(); }
	void fOpenAdapter10() { PA = d3d11.oOpenAdapter10; runASM(); }
	void fOpenAdapter10_2() { PA = d3d11.oOpenAdapter10_2; runASM(); }
}

void setupFunctions() {
	d3d11.oCreateDirect3D11DeviceFromDXGIDevice = GetProcAddress(d3d11.dll, "CreateDirect3D11DeviceFromDXGIDevice");
	d3d11.oCreateDirect3D11SurfaceFromDXGISurface = GetProcAddress(d3d11.dll, "CreateDirect3D11SurfaceFromDXGISurface");
	d3d11.oD3D11CoreCreateDevice = GetProcAddress(d3d11.dll, "D3D11CoreCreateDevice");
	d3d11.oD3D11CoreCreateLayeredDevice = GetProcAddress(d3d11.dll, "D3D11CoreCreateLayeredDevice");
	d3d11.oD3D11CoreGetLayeredDeviceSize = GetProcAddress(d3d11.dll, "D3D11CoreGetLayeredDeviceSize");
	d3d11.oD3D11CoreRegisterLayers = GetProcAddress(d3d11.dll, "D3D11CoreRegisterLayers");
	d3d11.oD3D11CreateDevice = GetProcAddress(d3d11.dll, "D3D11CreateDevice");
	d3d11.oD3D11CreateDeviceAndSwapChain = GetProcAddress(d3d11.dll, "D3D11CreateDeviceAndSwapChain");
	d3d11.oD3D11CreateDeviceForD3D12 = GetProcAddress(d3d11.dll, "D3D11CreateDeviceForD3D12");
	d3d11.oD3D11On12CreateDevice = GetProcAddress(d3d11.dll, "D3D11On12CreateDevice");
	d3d11.oD3DKMTCloseAdapter = GetProcAddress(d3d11.dll, "D3DKMTCloseAdapter");
	d3d11.oD3DKMTCreateAllocation = GetProcAddress(d3d11.dll, "D3DKMTCreateAllocation");
	d3d11.oD3DKMTCreateContext = GetProcAddress(d3d11.dll, "D3DKMTCreateContext");
	d3d11.oD3DKMTCreateDevice = GetProcAddress(d3d11.dll, "D3DKMTCreateDevice");
	d3d11.oD3DKMTCreateSynchronizationObject = GetProcAddress(d3d11.dll, "D3DKMTCreateSynchronizationObject");
	d3d11.oD3DKMTDestroyAllocation = GetProcAddress(d3d11.dll, "D3DKMTDestroyAllocation");
	d3d11.oD3DKMTDestroyContext = GetProcAddress(d3d11.dll, "D3DKMTDestroyContext");
	d3d11.oD3DKMTDestroyDevice = GetProcAddress(d3d11.dll, "D3DKMTDestroyDevice");
	d3d11.oD3DKMTDestroySynchronizationObject = GetProcAddress(d3d11.dll, "D3DKMTDestroySynchronizationObject");
	d3d11.oD3DKMTEscape = GetProcAddress(d3d11.dll, "D3DKMTEscape");
	d3d11.oD3DKMTGetContextSchedulingPriority = GetProcAddress(d3d11.dll, "D3DKMTGetContextSchedulingPriority");
	d3d11.oD3DKMTGetDeviceState = GetProcAddress(d3d11.dll, "D3DKMTGetDeviceState");
	d3d11.oD3DKMTGetDisplayModeList = GetProcAddress(d3d11.dll, "D3DKMTGetDisplayModeList");
	d3d11.oD3DKMTGetMultisampleMethodList = GetProcAddress(d3d11.dll, "D3DKMTGetMultisampleMethodList");
	d3d11.oD3DKMTGetRuntimeData = GetProcAddress(d3d11.dll, "D3DKMTGetRuntimeData");
	d3d11.oD3DKMTGetSharedPrimaryHandle = GetProcAddress(d3d11.dll, "D3DKMTGetSharedPrimaryHandle");
	d3d11.oD3DKMTLock = GetProcAddress(d3d11.dll, "D3DKMTLock");
	d3d11.oD3DKMTOpenAdapterFromHdc = GetProcAddress(d3d11.dll, "D3DKMTOpenAdapterFromHdc");
	d3d11.oD3DKMTOpenResource = GetProcAddress(d3d11.dll, "D3DKMTOpenResource");
	d3d11.oD3DKMTPresent = GetProcAddress(d3d11.dll, "D3DKMTPresent");
	d3d11.oD3DKMTQueryAdapterInfo = GetProcAddress(d3d11.dll, "D3DKMTQueryAdapterInfo");
	d3d11.oD3DKMTQueryAllocationResidency = GetProcAddress(d3d11.dll, "D3DKMTQueryAllocationResidency");
	d3d11.oD3DKMTQueryResourceInfo = GetProcAddress(d3d11.dll, "D3DKMTQueryResourceInfo");
	d3d11.oD3DKMTRender = GetProcAddress(d3d11.dll, "D3DKMTRender");
	d3d11.oD3DKMTSetAllocationPriority = GetProcAddress(d3d11.dll, "D3DKMTSetAllocationPriority");
	d3d11.oD3DKMTSetContextSchedulingPriority = GetProcAddress(d3d11.dll, "D3DKMTSetContextSchedulingPriority");
	d3d11.oD3DKMTSetDisplayMode = GetProcAddress(d3d11.dll, "D3DKMTSetDisplayMode");
	d3d11.oD3DKMTSetDisplayPrivateDriverFormat = GetProcAddress(d3d11.dll, "D3DKMTSetDisplayPrivateDriverFormat");
	d3d11.oD3DKMTSetGammaRamp = GetProcAddress(d3d11.dll, "D3DKMTSetGammaRamp");
	d3d11.oD3DKMTSetVidPnSourceOwner = GetProcAddress(d3d11.dll, "D3DKMTSetVidPnSourceOwner");
	d3d11.oD3DKMTSignalSynchronizationObject = GetProcAddress(d3d11.dll, "D3DKMTSignalSynchronizationObject");
	d3d11.oD3DKMTUnlock = GetProcAddress(d3d11.dll, "D3DKMTUnlock");
	d3d11.oD3DKMTWaitForSynchronizationObject = GetProcAddress(d3d11.dll, "D3DKMTWaitForSynchronizationObject");
	d3d11.oD3DKMTWaitForVerticalBlankEvent = GetProcAddress(d3d11.dll, "D3DKMTWaitForVerticalBlankEvent");
	d3d11.oD3DPerformance_BeginEvent = GetProcAddress(d3d11.dll, "D3DPerformance_BeginEvent");
	d3d11.oD3DPerformance_EndEvent = GetProcAddress(d3d11.dll, "D3DPerformance_EndEvent");
	d3d11.oD3DPerformance_GetStatus = GetProcAddress(d3d11.dll, "D3DPerformance_GetStatus");
	d3d11.oD3DPerformance_SetMarker = GetProcAddress(d3d11.dll, "D3DPerformance_SetMarker");
	d3d11.oEnableFeatureLevelUpgrade = GetProcAddress(d3d11.dll, "EnableFeatureLevelUpgrade");
	d3d11.oOpenAdapter10 = GetProcAddress(d3d11.dll, "OpenAdapter10");
	d3d11.oOpenAdapter10_2 = GetProcAddress(d3d11.dll, "OpenAdapter10_2");
}
#pragma endregion

BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved) {
	switch (ul_reason_for_call) {
	case DLL_PROCESS_ATTACH:
		d3d11.dll = LoadLibrary(L"C:\\Windows\\System32\\d3d11.dll");
		setupFunctions();
		break;
	case DLL_PROCESS_DETACH:
		FreeLibrary(d3d11.dll);
		break;
	}
	return 1;
}
