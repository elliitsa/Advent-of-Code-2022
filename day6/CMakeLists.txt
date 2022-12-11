cmake_minimum_required(VERSION 3.22)
project(day6)

set(CMAKE_CXX_STANDARD 23)

set(target day6)

add_executable(day6 main.cpp)

target_sources(${target}
        PRIVATE
        main.cpp)

target_compile_features(${target} PRIVATE cxx_std_20)

target_compile_options(${target} PRIVATE
        # set warnings for all build types
        $<$<CXX_COMPILER_ID:GNU,Clang,AppleClang>:-Wall -Wextra -Wpedantic -Wshadow -Wnon-virtual-dtor >
        # debug optimisation in Debug
        $<$<AND:$<CXX_COMPILER_ID:GNU,Clang,AppleClang>,$<CONFIG:Release>>:-O3>
        # O3 optimisation Release
        $<$<AND:$<CXX_COMPILER_ID:GNU,Clang,AppleClang>,$<CONFIG:Debug>>:-Og -g -fno-omit-frame-pointer>
        )
