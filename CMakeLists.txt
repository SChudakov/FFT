cmake_minimum_required(VERSION 3.13)
project(parallel)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fopenmp")

add_executable(parallel main.cpp sequential.cpp parallel.cpp distributed.cpp benchmark.cpp)