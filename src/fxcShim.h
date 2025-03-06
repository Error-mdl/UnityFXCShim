#pragma once

//#include <windows.h>
#include "guiddef.h"
#include "minwindef.h"
//typedef const void* LPCVOID;
//typedef void* LPVOID;
//typedef const char* LPCSTR;
//typedef const wchar_t* LPCWSTR;
//typedef long HRESULT;
//typedef unsigned long SIZE_T;
//typedef unsigned long DWORD, * PDWORD, * LPDWORD;


#include <stdint.h>

#ifndef DBG_PRINT
#define DBG_PRINT
#endif
#define DLL_EXPORT __declspec(dllexport)
#define API_CALL __stdcall
#define W_CDECL
//#ifndef HRESULT
//#define HRESULT long
//#endif

typedef void* ID3DBlob;
typedef void* ID3DInclude;
typedef int D3D_BLOB_PART;
struct ID3D11Linker;
struct ID3D11Module;
struct ID3D11FunctionLinkingGraph;
struct D3D_SHADER_DATA;
struct ID3D11ShaderTrace;
struct ID3D10Blob;
struct ID3D10Effect;

typedef struct _D3D_SHADER_MACRO
{
    LPCSTR Name;
    LPCSTR Definition;
} 	D3D_SHADER_MACRO;

typedef struct _D3D_SHADER_MACRO* LPD3D_SHADER_MACRO;

// D3DReadFileToBlob -----------------------------------------------------------

typedef HRESULT (API_CALL *PFN_D3DReadFileToBlob)(LPCWSTR pFileName, ID3DBlob** ppContents);

PFN_D3DReadFileToBlob p_D3DReadFileToBlob;

HRESULT API_CALL W_CDECL
__attribute__((noinline))
D3DReadFileToBlob_jmp(LPCWSTR pFileName,
    ID3DBlob** ppContents)
{
    return p_D3DReadFileToBlob(pFileName, ppContents);
}

DLL_EXPORT HRESULT API_CALL W_CDECL
__attribute__((section(".D3DReadFileToBlob")))
D3DReadFileToBlob(LPCWSTR pFileName,
    ID3DBlob** ppContents)
{
    return D3DReadFileToBlob_jmp(pFileName, ppContents);
} 

// D3DWriteBlobToFile ----------------------------------------------------------

typedef HRESULT (API_CALL *PFN_D3DWriteBlobToFile)
   (ID3DBlob* pBlob,
    LPCWSTR pFileName,
    BOOL bOverwrite);

PFN_D3DWriteBlobToFile p_D3DWriteBlobToFile;

DLL_EXPORT HRESULT API_CALL W_CDECL
__attribute__((section(".D3DWriteBlobToFile")))
D3DWriteBlobToFile(ID3DBlob* pBlob,
    LPCWSTR pFileName,
    BOOL bOverwrite)
{
    DBG_PRINT(p_D3DWriteBlobToFile);
    return p_D3DWriteBlobToFile(pBlob, pFileName, bOverwrite);
}

// D3DCompile ----------------------------------------------------------------

typedef HRESULT (API_CALL *PFN_D3DCompile)
   (LPCVOID pSrcData,
    SIZE_T SrcDataSize,
    LPCSTR pSourceName,
    CONST D3D_SHADER_MACRO* pDefines,
    ID3DInclude* pInclude,
    LPCSTR pEntrypoint,
    LPCSTR pTarget,
    uint32_t Flags1,
    uint32_t Flags2,
    ID3DBlob** ppCode,
    ID3DBlob** ppErrorMsgs);

PFN_D3DCompile p_D3DCompile;

DLL_EXPORT HRESULT API_CALL W_CDECL
__attribute__((section(".D3DCompile")))
D3DCompile(LPCVOID pSrcData,
    SIZE_T SrcDataSize,
    LPCSTR pSourceName,
    CONST D3D_SHADER_MACRO* pDefines,
    ID3DInclude* pInclude,
    LPCSTR pEntrypoint,
    LPCSTR pTarget,
    uint32_t Flags1,
    uint32_t Flags2,
    ID3DBlob** ppCode,
    ID3DBlob** ppErrorMsgs)
{
    DBG_PRINT(p_D3DCompile);
    return p_D3DCompile(pSrcData, SrcDataSize, pSourceName, pDefines, pInclude, pEntrypoint, pTarget, Flags1, Flags2, ppCode, ppErrorMsgs);
}

// D3DCompile2 ---------------------------------------------------------------

typedef HRESULT (API_CALL *PFN_D3DCompile2)
   (LPCVOID pSrcData,
    SIZE_T SrcDataSize,
    LPCSTR pSourceName,
    CONST D3D_SHADER_MACRO* pDefines,
    ID3DInclude* pInclude,
    LPCSTR pEntrypoint,
    LPCSTR pTarget,
    uint32_t Flags1,
    uint32_t Flags2,
    uint32_t SecondaryDataFlags,
    LPCVOID pSecondaryData,
    SIZE_T SecondaryDataSize,
    ID3DBlob** ppCode,
    ID3DBlob** ppErrorMsgs);

PFN_D3DCompile2 p_D3DCompile2;

DLL_EXPORT HRESULT API_CALL W_CDECL
__attribute__((section(".D3DCompile2")))
D3DCompile2(LPCVOID pSrcData,
    SIZE_T SrcDataSize,
    LPCSTR pSourceName,
    CONST D3D_SHADER_MACRO* pDefines,
    ID3DInclude* pInclude,
    LPCSTR pEntrypoint,
    LPCSTR pTarget,
    uint32_t Flags1,
    uint32_t Flags2,
    uint32_t SecondaryDataFlags,
    LPCVOID pSecondaryData,
    SIZE_T SecondaryDataSize,
    ID3DBlob** ppCode,
    ID3DBlob** ppErrorMsgs)
{
    DBG_PRINT(p_D3DCompile2);
    return p_D3DCompile2(
        pSrcData, 
        SrcDataSize, 
        pSourceName, 
        pDefines, 
        pInclude, 
        pEntrypoint, 
        pTarget, 
        Flags1, 
        Flags2, 
        SecondaryDataFlags, 
        pSecondaryData, 
        SecondaryDataSize, 
        ppCode, 
        ppErrorMsgs);
}

// D3DCompileFromFile --------------------------------------------------------

typedef HRESULT (API_CALL *PFN_D3DCompileFromFile)
   (LPCWSTR pFileName,
    CONST D3D_SHADER_MACRO* pDefines,
    ID3DInclude* pInclude,
    LPCSTR pEntrypoint,
    LPCSTR pTarget,
    uint32_t Flags1,
    uint32_t Flags2,
    ID3DBlob** ppCode,
    ID3DBlob** ppErrorMsgs);

PFN_D3DCompileFromFile p_D3DCompileFromFile;

DLL_EXPORT HRESULT API_CALL W_CDECL
__attribute__((section(".D3DCompileFromFile")))
D3DCompileFromFile(LPCWSTR pFileName,
    CONST D3D_SHADER_MACRO* pDefines,
    ID3DInclude* pInclude,
    LPCSTR pEntrypoint,
    LPCSTR pTarget,
    uint32_t Flags1,
    uint32_t Flags2,
    ID3DBlob** ppCode,
    ID3DBlob** ppErrorMsgs)
{
    DBG_PRINT(p_D3DCompileFromFile);
    return p_D3DCompileFromFile(
        pFileName,
        pDefines,
        pInclude,
        pEntrypoint,
        pTarget,
        Flags1,
        Flags2,
        ppCode,
        ppErrorMsgs);
}

// D3DPreprocess -------------------------------------------------------------

typedef HRESULT (API_CALL *PFN_D3DPreprocess)
   (LPCVOID pSrcData,
    SIZE_T SrcDataSize,
    LPCSTR pSourceName,
    CONST D3D_SHADER_MACRO* pDefines,
    ID3DInclude* pInclude,
    ID3DBlob** ppCodeText,
    ID3DBlob** ppErrorMsgs);

PFN_D3DPreprocess p_D3DPreprocess;

DLL_EXPORT HRESULT API_CALL W_CDECL
__attribute__((section(".D3DPreprocess")))
D3DPreprocess(LPCVOID pSrcData,
    SIZE_T SrcDataSize,
    LPCSTR pSourceName,
    CONST D3D_SHADER_MACRO* pDefines,
    ID3DInclude* pInclude,
    ID3DBlob** ppCodeText,
    ID3DBlob** ppErrorMsgs)
{
    DBG_PRINT(p_D3DPreprocess);
    return p_D3DPreprocess(
        pSrcData,
        SrcDataSize,
        pSourceName,
        pDefines,
        pInclude,
        ppCodeText,
        ppErrorMsgs);
}

// D3DGetDebugInfo -----------------------------------------------------------

typedef HRESULT (API_CALL *PFN_D3DGetDebugInfo)
   (LPCVOID pSrcData,
    SIZE_T SrcDataSize,
    ID3DBlob** ppDebugInfo);

PFN_D3DGetDebugInfo p_D3DGetDebugInfo;

DLL_EXPORT HRESULT API_CALL W_CDECL
__attribute__((section(".D3DGetDebugInfo")))
D3DGetDebugInfo(LPCVOID pSrcData,
    SIZE_T SrcDataSize,
    ID3DBlob** ppDebugInfo)
{
    DBG_PRINT(p_D3DGetDebugInfo);
    return p_D3DGetDebugInfo(
        pSrcData,
        SrcDataSize,
        ppDebugInfo
    );
}

// D3DReflect ----------------------------------------------------------------

typedef HRESULT (API_CALL *PFN_D3DReflect)
   (LPCVOID pSrcData,
    SIZE_T SrcDataSize,
    REFIID pInterface,
    void** ppReflector);

PFN_D3DReflect p_D3DReflect;

DLL_EXPORT HRESULT API_CALL W_CDECL
__attribute__((section(".D3DReflect")))
D3DReflect(LPCVOID pSrcData,
    SIZE_T SrcDataSize,
    REFIID pInterface,
    void** ppReflector)
{
    DBG_PRINT(p_D3DReflect);
    return p_D3DReflect(
        pSrcData,
        SrcDataSize,
        pInterface,
        ppReflector
    );
}

// D3DReflectLibrary ---------------------------------------------------------

typedef HRESULT (API_CALL *PFN_D3DReflectLibrary)
   (LPCVOID pSrcData,
    SIZE_T SrcDataSize,
    REFIID riid,
    LPVOID* ppReflector);

PFN_D3DReflectLibrary p_D3DReflectLibrary;

DLL_EXPORT HRESULT API_CALL W_CDECL
__attribute__((section(".D3DReflectLibrary")))
D3DReflectLibrary(LPCVOID pSrcData,
    SIZE_T SrcDataSize,
    REFIID riid,
    LPVOID* ppReflector)
{
    DBG_PRINT(p_D3DReflectLibrary);
    return p_D3DReflectLibrary(
        pSrcData,
        SrcDataSize,
        riid,
        ppReflector
    );
}

// D3DDisassemble ------------------------------------------------------------

typedef HRESULT (API_CALL *PFN_D3DDisassemble)
   (LPCVOID pSrcData,
    SIZE_T SrcDataSize,
    uint32_t Flags,
    LPCSTR szComments,
    ID3DBlob** ppDisassembly);

PFN_D3DDisassemble p_D3DDisassemble;

HRESULT API_CALL W_CDECL
__attribute__((noinline))
D3DDisassemble_jmp(LPCVOID pSrcData,
    SIZE_T SrcDataSize,
    uint32_t Flags,
    LPCSTR szComments,
    ID3DBlob** ppDisassembly)
{
    return p_D3DDisassemble(
        pSrcData,
        SrcDataSize,
        Flags,
        szComments,
        ppDisassembly
    );
}

DLL_EXPORT HRESULT API_CALL W_CDECL
__attribute__((section(".D3DDisassemble")))
D3DDisassemble(LPCVOID pSrcData,
    SIZE_T SrcDataSize,
    uint32_t Flags,
    LPCSTR szComments,
    ID3DBlob** ppDisassembly)
{
    return D3DDisassemble_jmp(
        pSrcData,
        SrcDataSize,
        Flags,
        szComments,
        ppDisassembly
    );
}

// D3DDisassembleRegion ------------------------------------------------------

typedef HRESULT (API_CALL *PFN_D3DDisassembleRegion)
   (LPCVOID pSrcData,
    SIZE_T SrcDataSize,
    uint32_t Flags,
    LPCSTR szComments,
    SIZE_T StartByteOffset,
    SIZE_T NumInsts,
    SIZE_T* pFinishByteOffset,
    ID3DBlob** ppDisassembly);

PFN_D3DDisassembleRegion p_D3DDisassembleRegion;

HRESULT API_CALL W_CDECL
__attribute__((noinline))
D3DDisassembleRegion_jmp(
    LPCVOID pSrcData,
    SIZE_T SrcDataSize,
    uint32_t Flags,
    LPCSTR szComments,
    SIZE_T StartByteOffset,
    SIZE_T NumInsts,
    SIZE_T* pFinishByteOffset,
    ID3DBlob** ppDisassembly)
{
    return p_D3DDisassembleRegion(
        pSrcData,
        SrcDataSize,
        Flags,
        szComments,
        StartByteOffset,
        NumInsts,
        pFinishByteOffset,
        ppDisassembly
    );
}

DLL_EXPORT HRESULT API_CALL W_CDECL
__attribute__((section(".D3DDisassembleRegion")))
D3DDisassembleRegion(
    LPCVOID pSrcData,
    SIZE_T SrcDataSize,
    uint32_t Flags,
    LPCSTR szComments,
    SIZE_T StartByteOffset,
    SIZE_T NumInsts,
    SIZE_T* pFinishByteOffset,
    ID3DBlob** ppDisassembly)
{
    return D3DDisassembleRegion_jmp(
        pSrcData,
        SrcDataSize,
        Flags,
        szComments,
        StartByteOffset,
        NumInsts,
        pFinishByteOffset,
        ppDisassembly
    );
}

// D3DCreateLinker -----------------------------------------------------------

typedef HRESULT (API_CALL *PFN_D3DCreateLinker)(struct ID3D11Linker** ppLinker);

PFN_D3DCreateLinker p_D3DCreateLinker;

DLL_EXPORT HRESULT API_CALL W_CDECL
__attribute__((section(".D3DCreateLinker")))
D3DCreateLinker(struct ID3D11Linker** ppLinker)
{
    DBG_PRINT(p_D3DCreateLinker);
    return p_D3DCreateLinker(ppLinker);
}

// D3DLoadModule --------------------------------------------------------------

typedef HRESULT (API_CALL *PFN_D3DLoadModule)
   (LPCVOID pSrcData,
    SIZE_T cbSrcDataSize,
    struct ID3D11Module** ppModule);

PFN_D3DLoadModule p_D3DLoadModule;

DLL_EXPORT HRESULT API_CALL W_CDECL
__attribute__((section(".D3DLoadModule")))
D3DLoadModule(LPCVOID pSrcData,
    SIZE_T cbSrcDataSize,
    struct ID3D11Module** ppModule)
{
    DBG_PRINT(p_D3DLoadModule);
    return p_D3DLoadModule(pSrcData, cbSrcDataSize, ppModule);
}

// D3DCreateFunctionLinkingGraph ---------------------------------------------

typedef HRESULT (API_CALL *PFN_D3DCreateFunctionLinkingGraph)
   (uint32_t uFlags,
    struct ID3D11FunctionLinkingGraph** ppFunctionLinkingGraph);

PFN_D3DCreateFunctionLinkingGraph p_D3DCreateFunctionLinkingGraph;

DLL_EXPORT HRESULT API_CALL W_CDECL
__attribute__((section(".D3DCreateFunctionLinkingGraph")))
D3DCreateFunctionLinkingGraph(uint32_t uFlags,
    struct ID3D11FunctionLinkingGraph** ppFunctionLinkingGraph)
{
    DBG_PRINT(p_D3DCreateFunctionLinkingGraph);
    return p_D3DCreateFunctionLinkingGraph(uFlags, ppFunctionLinkingGraph);
}

// D3DGetTraceInstructionOffsets -----------------------------------------------

typedef HRESULT (API_CALL *PFN_D3DGetTraceInstructionOffsets)
   (LPCVOID pSrcData,
    SIZE_T SrcDataSize,
    uint32_t Flags,
    SIZE_T StartInstIndex,
    SIZE_T NumInsts,
    SIZE_T* pOffsets,
    SIZE_T* pTotalInsts);

PFN_D3DGetTraceInstructionOffsets p_D3DGetTraceInstructionOffsets;

DLL_EXPORT HRESULT API_CALL W_CDECL
__attribute__((section(".D3DGetTraceInstructionOffsets")))
D3DGetTraceInstructionOffsets(
    LPCVOID pSrcData,
    SIZE_T SrcDataSize,
    uint32_t Flags,
    SIZE_T StartInstIndex,
    SIZE_T NumInsts,
    SIZE_T* pOffsets,
    SIZE_T* pTotalInsts)
{
    DBG_PRINT(p_D3DGetTraceInstructionOffsets);
    return p_D3DGetTraceInstructionOffsets(
        pSrcData,
        SrcDataSize,
        Flags,
        StartInstIndex,
        NumInsts,
        pOffsets,
        pTotalInsts
    );
}

// D3DGetInputSignatureBlob --------------------------------------------------

typedef HRESULT (API_CALL *PFN_D3DGetInputSignatureBlob)(
    LPCVOID pSrcData,
    SIZE_T SrcDataSize,
    ID3DBlob** ppSignatureBlob);

PFN_D3DGetInputSignatureBlob p_D3DGetInputSignatureBlob;

DLL_EXPORT HRESULT API_CALL W_CDECL
__attribute__((section(".D3DGetInputSignatureBlob")))
D3DGetInputSignatureBlob(
    LPCVOID pSrcData,
    SIZE_T SrcDataSize,
    ID3DBlob** ppSignatureBlob)
{
    DBG_PRINT(p_D3DGetInputSignatureBlob);
    return p_D3DGetInputSignatureBlob(
        pSrcData,
        SrcDataSize,
        ppSignatureBlob
    );
}

// D3DGetOutputSignatureBlob --------------------------------------------------

typedef HRESULT(API_CALL* PFN_D3DGetOutputSignatureBlob)(
    LPCVOID pSrcData,
    SIZE_T SrcDataSize,
    ID3DBlob** ppSignatureBlob);

PFN_D3DGetOutputSignatureBlob p_D3DGetOutputSignatureBlob;

DLL_EXPORT HRESULT API_CALL W_CDECL
__attribute__((section(".D3DGetOutputSignatureBlob")))
D3DGetOutputSignatureBlob(
    LPCVOID pSrcData,
    SIZE_T SrcDataSize,
    ID3DBlob** ppSignatureBlob)
{
    DBG_PRINT(p_D3DGetOutputSignatureBlob);
    return p_D3DGetOutputSignatureBlob(
        pSrcData,
        SrcDataSize,
        ppSignatureBlob
    );
}

// D3DGetInputAndOutputSignatureBlob -------------------------------------------

typedef HRESULT (API_CALL *PFN_D3DGetInputAndOutputSignatureBlob)(
    LPCVOID pSrcData,
    SIZE_T SrcDataSize,
    ID3DBlob** ppSignatureBlob);

PFN_D3DGetInputAndOutputSignatureBlob p_D3DGetInputAndOutputSignatureBlob;

DLL_EXPORT HRESULT API_CALL W_CDECL
__attribute__((section(".D3DGetInputAndOutputSignatureBlob")))
D3DGetInputAndOutputSignatureBlob(
    LPCVOID pSrcData,
    SIZE_T SrcDataSize,
    ID3DBlob** ppSignatureBlob)
{
    DBG_PRINT(p_D3DGetInputAndOutputSignatureBlob);
    return p_D3DGetInputAndOutputSignatureBlob(
        pSrcData,
        SrcDataSize,
        ppSignatureBlob
    );
}

// D3DStripShader -------------------------------------------------------------

typedef HRESULT (API_CALL *PFN_D3DStripShader)(
    LPCVOID pShaderBytecode,
    SIZE_T BytecodeLength,
    uint32_t uStripFlags,
    ID3DBlob** ppStrippedBlob);

PFN_D3DStripShader p_D3DStripShader;

DLL_EXPORT HRESULT API_CALL W_CDECL 
__attribute__((section(".D3DStripShader")))
D3DStripShader(
    LPCVOID pShaderBytecode,
    SIZE_T BytecodeLength,
    uint32_t uStripFlags,
    ID3DBlob** ppStrippedBlob)
{
    DBG_PRINT(p_D3DStripShader);
    return p_D3DStripShader(
        pShaderBytecode,
        BytecodeLength,
        uStripFlags,
        ppStrippedBlob
    );
}

// D3DGetBlobPart ------------------------------------------------------------

typedef HRESULT (API_CALL *PFN_D3DGetBlobPart)(
    LPCVOID pSrcData,
    SIZE_T SrcDataSize,
    int32_t Part,
    uint32_t Flags,
    ID3DBlob** ppPart);

PFN_D3DGetBlobPart p_D3DGetBlobPart;

DLL_EXPORT HRESULT API_CALL W_CDECL 
__attribute__((section(".D3DGetBlobPart")))
D3DGetBlobPart(
    LPCVOID pSrcData,
    SIZE_T SrcDataSize,
    D3D_BLOB_PART Part,
    uint32_t Flags,
    ID3DBlob** ppPart)
{
    DBG_PRINT(p_D3DGetBlobPart);
    return p_D3DGetBlobPart(
        pSrcData,
        SrcDataSize,
        Part,
        Flags,
        ppPart
    );
}

// D3DSetBlobPart -------------------------------------------------------------

typedef HRESULT (API_CALL *PFN_D3DSetBlobPart)(
    LPCVOID pSrcData,
    SIZE_T SrcDataSize,
    D3D_BLOB_PART Part,
    uint32_t Flags,
    LPCVOID pPart,
    SIZE_T PartSize,
    ID3DBlob** ppNewShader);

PFN_D3DSetBlobPart p_D3DSetBlobPart;

DLL_EXPORT HRESULT API_CALL 
__attribute__((section(".D3DSetBlobPart")))
D3DSetBlobPart(
    LPCVOID pSrcData,
    SIZE_T SrcDataSize,
    D3D_BLOB_PART Part,
    uint32_t Flags,
    LPCVOID pPart,
    SIZE_T PartSize,
    ID3DBlob** ppNewShader)
{
    DBG_PRINT(p_D3DSetBlobPart);
    return p_D3DSetBlobPart(
        pSrcData,
        SrcDataSize,
        Part,
        Flags,
        pPart,
        PartSize,
        ppNewShader
    );
}

// D3DCreateBlob --------------------------------------------------------------

typedef HRESULT (API_CALL *PFN_D3DCreateBlob)(
    SIZE_T Size,
    ID3DBlob** ppBlob);

PFN_D3DCreateBlob p_D3DCreateBlob;

DLL_EXPORT HRESULT API_CALL W_CDECL 
__attribute__((section(".D3DCreateBlob")))
D3DCreateBlob(SIZE_T Size, ID3DBlob** ppBlob)
{
    DBG_PRINT(p_D3DCreateBlob);
    return p_D3DCreateBlob(Size, ppBlob);
}

// D3DCompressShaders ---------------------------------------------------------

typedef HRESULT (API_CALL *PFN_D3DCompressShaders)(
    uint32_t uNumShaders,
    struct D3D_SHADER_DATA* pShaderData,
    uint32_t uFlags,
    ID3DBlob** ppCompressedData);

PFN_D3DCompressShaders p_D3DCompressShaders;

DLL_EXPORT HRESULT API_CALL W_CDECL
__attribute__((section(".D3DCompressShaders")))
D3DCompressShaders(
    uint32_t uNumShaders,
    struct D3D_SHADER_DATA* pShaderData,
    uint32_t uFlags,
    ID3DBlob** ppCompressedData)
{
    DBG_PRINT(p_D3DCompressShaders);
    return p_D3DCompressShaders(
        uNumShaders,
        pShaderData,
        uFlags,
        ppCompressedData
    );
}

// D3DDecompressShaders -------------------------------------------------------

typedef HRESULT (API_CALL *PFN_D3DDecompressShaders)(
    LPCVOID pSrcData,
    SIZE_T SrcDataSize,
    uint32_t uNumShaders,
    uint32_t uStartIndex,
    uint32_t* pIndices,
    uint32_t uFlags,
    ID3DBlob** ppShaders,
    uint32_t* pTotalShaders);

PFN_D3DDecompressShaders p_D3DDecompressShaders;

DLL_EXPORT HRESULT API_CALL 
__attribute__((section(".D3DDecompressShaders")))
D3DDecompressShaders(
    LPCVOID pSrcData,
    SIZE_T SrcDataSize,
    uint32_t uNumShaders,
    uint32_t uStartIndex,
    uint32_t* pIndices,
    uint32_t uFlags,
    ID3DBlob** ppShaders,
    uint32_t* pTotalShaders)
{
    DBG_PRINT(p_D3DDecompressShaders);
    return p_D3DDecompressShaders(
        pSrcData,
        SrcDataSize,
        uNumShaders,
        uStartIndex,
        pIndices,
        uFlags,
        ppShaders,
        pTotalShaders
    );
}

// D3DDisassemble10Effect -----------------------------------------------------

typedef HRESULT (API_CALL *PFN_D3DDisassemble10Effect)(
    struct ID3D10Effect* pEffect,
    uint32_t Flags,
    ID3DBlob** ppDisassembly);

PFN_D3DDisassemble10Effect p_D3DDisassemble10Effect;

DLL_EXPORT HRESULT API_CALL W_CDECL 
__attribute__((section(".D3DDisassemble10Effect")))
D3DDisassemble10Effect(
    struct ID3D10Effect* pEffect,
    uint32_t Flags,
    ID3DBlob** ppDisassembly)
{
    DBG_PRINT(p_D3DDisassemble10Effect);
    return p_D3DDisassemble10Effect(
        pEffect,
        Flags,
        ppDisassembly
    );
}

// D3DDisassemble11Trace ------------------------------------------------------

typedef HRESULT (API_CALL *PFN_D3DDisassemble11Trace)(
    LPCVOID           pSrcData,
    SIZE_T            SrcDataSize,
    struct ID3D11ShaderTrace* pTrace,
    uint32_t          StartStep,
    uint32_t          NumSteps,
    uint32_t          Flags,
    struct ID3D10Blob** ppDisassembly
);

PFN_D3DDisassemble11Trace p_D3DDisassemble11Trace;

DLL_EXPORT HRESULT API_CALL W_CDECL 
__attribute__((section(".D3DDisassemble11Trace")))
D3DDisassemble11Trace(
    LPCVOID           pSrcData,
    SIZE_T            SrcDataSize,
    struct ID3D11ShaderTrace* pTrace,
    uint32_t          StartStep,
    uint32_t          NumSteps,
    uint32_t          Flags,
    struct ID3D10Blob** ppDisassembly
)
{
    DBG_PRINT(p_D3DDisassemble11Trace);
    return p_D3DDisassemble11Trace(
        pSrcData,
        SrcDataSize,
        pTrace,
        StartStep,
        NumSteps,
        Flags,
        ppDisassembly
    );
}

typedef HRESULT (API_CALL *PFN_D3DAssemble)(
    const char* data,
    uint32_t data_len,
    void* unknown,
    void* defines,
    void* include,
    DWORD flags,
    void** shader,
    void** error_messages);

PFN_D3DAssemble p_D3DAssemble;

DLL_EXPORT HRESULT API_CALL W_CDECL
__attribute__((section(".D3DAssemble")))
D3DAssemble(
    const char* data,
    uint32_t    data_len,
    void*       unknown,
    void*       defines,
    void*       include,
    DWORD       flags,
    void**      shader,
    void**      error_messages)
{
    return p_D3DAssemble(
        data,
        data_len,
        unknown,
        defines,
        include,
        flags,
        shader,
        error_messages
    );
}
