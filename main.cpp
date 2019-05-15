#include <iostream>
#include <vector>
#include <functional>
#include <omp.h>

#include "persistence.hpp"
#include "Timer.hpp"
#include "sequential.hpp"
#include "parallel.hpp"

void measure_time(std::function<std::vector<int>(std::vector<int>, std::vector<int>)> f,
                  std::vector<int> &a, std::vector<int> &b, const std::string &descriptor) {
    Timer timer;
    timer.start();
    f(a, b);
    timer.stop();
    std::cout << descriptor << " execution time: " << timer.get_duration().count() << std::endl;
}

int main() {
    omp_set_num_threads(12);

    long size = 10000000;
    std::string a_file = "/home/semen/drive/workspace.cpp/parallel/data/a.txt";
    std::string b_file = "/home/semen/drive/workspace.cpp/parallel/data/b.txt";

    std::string sequential_desc = "sequential";
    std::string parallel_desc = "parallel";
    std::string distributed_desc = "distributed";

    persistence::generate(a_file, size);
    std::vector<int> a = persistence::read_vector(a_file);


    persistence::generate(b_file, size);
    std::vector<int> b = persistence::read_vector(b_file);

    auto sequential = [](std::vector<int> a, std::vector<int> b) { return sequential::multiply(a, b); };
    auto parallel = [](std::vector<int> a, std::vector<int> b) { return parallel::multiply(a, b); };

//    measure_time(sequential, a, b, sequential_desc);
    measure_time(parallel, a, b, parallel_desc);

    return 0;
}