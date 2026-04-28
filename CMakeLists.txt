cmake_minimum_required(VERSION 3.10)

# project name
project(neuromorphic-brain)

# C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


# main file
add_executable(neuromorphic-brain src/main.cpp "src/brain/Brains.h" "src/brain/Brains.cpp" "src/brain/IBrain.h" "src/params.h")

if(USE_DEBUG_FEATURES)
    # add macro for C++ code
    target_compile_definitions(neuromorphic-brain PRIVATE DEBUG)
    
    # can add additional files for debug
    # target_sources(neuromorphic-brain PRIVATE src/debug_tools.cpp)
    
    message(STATUS "--- Debug build ON ---")
endif()

# compiled program install
install(TARGETS neuromorphic-brain DESTINATION bin)
