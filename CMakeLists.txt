cmake_minimum_required(VERSION 3.20)

set(PROJECT_NAME UnityFXCShim)

project(${PROJECT_NAME} VERSION 0.0
    DESCRIPTION "Shared Library to stand between Unity and D3DCompiler_47.dll to allow modifying the arguments passed to the compiler"
    LANGUAGES C
	)
	
set(CMAKE_C_STANDARD 17)

add_library(D3DCompiler_47 SHARED src/main.c src/fxcShim.h)
target_include_directories(D3DCompiler_47 PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/src")
target_compile_options(D3DCompiler_47 PRIVATE "-mcmodel=small" "-O2")
target_link_options(D3DCompiler_47 PRIVATE "SHELL:-T${CMAKE_CURRENT_SOURCE_DIR}/src/link.ld")
#target_link_options(D3DCompiler_47 PRIVATE "SHELL:-Wl,--verbose")
#target_link_options(D3DCompiler_47 PRIVATE "SHELL:-Wl,-Map=${CMAKE_CURRENT_SOURCE_DIR}/src/map.map" "-Wl,--no-gc-sections")

add_executable(test src/test.c)
target_include_directories(test PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/src")