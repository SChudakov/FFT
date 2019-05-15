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
        }
        return result;
    }

    void generate(const std::string &path, long size) {
        std::vector<int> vector;

        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis;

        for (int i = 0; i < size; ++i) {
            vector.push_back(dis(gen));
        }
        write_vector(path, vector);
    }

    void write_vector(const std::string &path, const std::vector<int> &vector) {
        std::ofstream write_stream(path);
        for (int el : vector) {
            write_stream << el << ' ';
        }
        write_stream.close();
    }
}

