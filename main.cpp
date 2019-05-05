#include <iostream>
#include <vector>
#include <functional>
#include <omp.h>

#include "persistence.hpp"
#include "benchmark.hpp"
#include "sequential.hpp"
#include "parallel.hpp"
#include "distributed.hpp"

void measure_time(std::function<std::vector<int>(std::vector<int>, std::vector<int>)> f,
                  std::vector<int> &a, std::vector<int> &b, const std::string &descriptor) {
    long start = benchmark::current_time();
    f(a, b);
    long end = benchmark::current_time();
    std::cout << descriptor << " execution time: " << (end - start) << std::endl;
}

int main() {
    omp_set_num_threads(8);

    long size = 10000000;
    std::string a_file = "/home/semen/drive/workspace.cpp/parallel/data/a.txt";
    std::string b_file = "/home/semen/drive/workspace.cpp/parallel/data/b.txt";

    std::string sequential_desc = "sequential";
    std::string parallel_desc = "parallel";
    std::string distributed_desc = "distributed";

    persistence::generate(a_file, size);
//    std::cout << "a generated" << std::endl;
    std::vector<int> a = persistence::read_vector(a_file);
//    std::cout << "a read" << std::endl;


    persistence::generate(b_file, size);
//    std::cout << "b generated" << std::endl;
    std::vector<int> b = persistence::read_vector(b_file);
//    std::cout << "b read" << std::endl;

    auto sequential = [](std::vector<int> a, std::vector<int> b) { return sequential::multiply(a, b); };
    auto parallel = [](std::vector<int> a, std::vector<int> b) { return parallel::multiply(a, b); };
    auto distributed = [](std::vector<int> a, std::vector<int> b) { return distributed::multiply(a, b); };

//    measure_time(sequential, a, b, sequential_desc);
    measure_time(parallel, a, b, parallel_desc);
//    measure_time(distributed, a, b, distributed_desc);

    return 0;
}