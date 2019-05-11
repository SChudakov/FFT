//
// Created by semen on 10.05.19.
//
#include <iostream>
#include <boost/filesystem.hpp>
#include "persistence.hpp"

int main() {
    int processor_count = 24;
    int vectors_length = 1000000;
    std::string base_prefix = "/home/semen/drive/workspace.cpp/parallel/data/tasks/";

    for (int i = 0; i < processor_count; i++) {
        std::cout << "generating " << i << std::endl;
        std::string directory_path = base_prefix + std::to_string(i) + "/";
        if (!boost::filesystem::exists(directory_path)) {
            boost::filesystem::create_directories(directory_path);
        }
        std::string a_file_path = directory_path + "/a.txt";
        std::string b_file_path = directory_path + "/b.txt";

        persistence::generate(a_file_path, vectors_length);
        persistence::generate(b_file_path, vectors_length);
    }

    return 0;
}