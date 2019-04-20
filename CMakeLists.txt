cmake_minimum_required(VERSION 3.13)
project(parallel CXX)

set(CMAKE_CXX_STANDARD 14)

#message("${CMAKE_CXX_FLAGS}")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3 -fopenmp -march=native")


add_executable(parallel
        main.cpp
        sequential.cpp
        parallel.cpp
        distributed.cpp
        benchmark.cpp
        persistence.cpp
        sequential.hpp
        parallel.hpp
        distributed.hpp
        benchmark.hpp
        persistence.hpp
        tmp.cpp)

target_link_libraries(parallel pthread)