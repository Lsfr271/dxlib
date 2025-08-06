cmake_minimum_required(VERSION 3.22)

project(dxlib LANGUAGES C CXX)

option(ENABLE_EXAMPLE "enable example for dxlib" ON)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)
set(CMAKE_CXX_EXTENSIONS OFF)

add_library(dxlib INTERFACE)
add_library(dxlib::dxlib ALIAS dxlib) 
target_include_directories(dxlib INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/include)

if (WIN32 AND ${CMAKE_CXX_COMPILER_ID} STREQUAL "MSVC")
    target_compile_definitions(dxlib PUBLIC INTERFACE   
       WIN32_LEAN_AND_MEAN  
       NOMINMAX 
    )   
endif() 

message("${CMAKE_CXX_COMPILER_ID}")

if(ENABLE_EXAMPLE)
    add_subdirectory(examples)
endif()
