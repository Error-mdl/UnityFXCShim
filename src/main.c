// dllmain.cpp : Defines the entry point for the DLL application.

//#include "libloaderapi.h"

//#include "debugapi.h"

//#define DBG_PRINT(fnct) OutputDebugStringA("FXC Shim: Called " #fnct)
#include "fxcShim.h"
//#include "d3dcompiler.h"
/*
#define D3DCOMPILER_OLD_DLL_W "D3DCompiler_47_old.dll"

HMODULE libD3dCompiler47;

#include "fxcFuncs.inl"

void AttachOriginalFXC()
{
    libD3dCompiler47 = LoadLibraryA(D3DCOMPILER_OLD_DLL_W);
    if (libD3dCompiler47)
    {
        //OutputDebugStringA("FXC Shim: Loading FXC functions from " D3DCOMPILER_OLD_DLL_W);

#define LOAD_FXC_FUNC(fn) p_##fn = (PFN_##fn) GetProcAddress(libD3dCompiler47, #fn); if (p_##fn == NULL) { OutputDebugStringA("Failed to load " #fn); }
        DO_FOR_ALL_FXC(LOAD_FXC_FUNC);
    }
    else
    {
        //OutputDebugStringA("FXC Shim: Could not load " D3DCOMPILER_OLD_DLL_W "!");
    }
}

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        AttachOriginalFXC();

    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        if (libD3dCompiler47)
        {
            FreeLibrary(libD3dCompiler47);
        }
        break;
    }
    return TRUE;
}

*/
