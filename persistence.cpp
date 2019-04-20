//
// Created by semen on 12.04.19.
//
#include "persistence.hpp"

#include <iostream>

namespace persistence {
    std::vector<int> read_vector(const std::string &path) {
        std::vector<int> result;
        std::ifstream read_stream(path);

        int i;
        while (read_stream >> i) {
            result.push_back(i);
//            std::cout << i << std::endl;
        }
        return result;
    }

    void generate(const std::string &path, long size) {
        std::ofstream write_stream(path);

        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(0);

        for (int i = 0; i < size; ++i) {
            write_stream << dis(gen) << ' ';
        }
    }
}

