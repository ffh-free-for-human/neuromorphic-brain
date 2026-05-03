cmake_minimum_required(VERSION 3.10)

# project name
project(neuromorphic-brain)

# C++ standard
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


# main file
add_executable(neuromorphic-brain src/main.cpp "src/brains/Brains.h" "src/brains/Brains.cpp"  "src/params.h" "src/brains/NeuronCloud/NeuronCloud.h" "src/brains/NeuronCloud/NeuronCloud.cpp" "src/brains/NeuronCloud/NeuronCloudConst.h")

if(USE_DEBUG_FEATURES)
    # add macro for C++ code
    target_compile_definitions(neuromorphic-brain PRIVATE DEBUG)
    
    # can add additional files for debug
    # target_sources(neuromorphic-brain PRIVATE src/debug_tools.cpp)
    
    message(STATUS "--- Debug build ON ---")
endif()
