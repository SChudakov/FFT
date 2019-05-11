cmake_minimum_required(VERSION 3.13)
project(parallel CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3 -fopenmp -march=native")

set(CMAKE_CXX_COMPILE_FLAGS ${CMAKE_CXX_COMPILE_FLAGS} ${MPI_COMPILE_FLAGS})
set(CMAKE_CXX_LINK_FLAGS ${CMAKE_CXX_LINK_FLAGS} ${MPI_LINK_FLAGS})

SET(CMAKE_C_COMPILER mpicc)
SET(CMAKE_CXX_COMPILER mpic++)

find_package(MPI REQUIRED)
find_package(Boost 1.65.1 COMPONENTS system filesystem mpi serialization REQUIRED)

add_executable(parallel
#        main.cpp
#        benchmark.hpp
#        benchmark.cpp
#        generate.cpp
        sequential.hpp
        sequential.cpp
        parallel.hpp
        parallel.cpp
        distributed.cpp
        persistence.hpp
        persistence.cpp
        Timer.hpp
        Timer.cpp
        )

message(${Boost_LIBRARIES})

include_directories(${Boost_INCLUDE_DIRS})

target_link_libraries(parallel ${Boost_LIBRARIES})