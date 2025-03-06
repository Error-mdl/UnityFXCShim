#include <stdio.h>
#include "Windows.h"

#include "fxcFuncs.inl"

#define D3DCOMPILER_DLL_A "libD3DCompiler_47.dll"

int main() 
{
    HMODULE libD3dCompiler47 = LoadLibraryA(D3DCOMPILER_DLL_A);
    if (libD3dCompiler47)
    {
        printf("FXC Shim Test: Loading FXC functions from " D3DCOMPILER_DLL_A);

#define LOAD_FXC_FUNC(fn) FARPROC p_##fn = GetProcAddress(libD3dCompiler47, #fn); if (p_##fn == NULL) { printf("Failed to load " #fn); }
        DO_FOR_ALL_FXC(LOAD_FXC_FUNC);
    }
    else
    {
        printf("FXC Shim Test: Could not load " D3DCOMPILER_DLL_A "!");
    }
    FreeLibrary(libD3dCompiler47);
    return 0;
}