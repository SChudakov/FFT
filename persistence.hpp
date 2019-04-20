//
// Created by semen on 19.04.19.
//

#ifndef PARALLEL_PERSISTENCE_H
#define PARALLEL_PERSISTENCE_H

#include <vector>
#include <string>
#include <fstream>
#include <random>

namespace persistence {
    std::vector<int> read_vector(const std::string &path);

    void generate(const std::string &path, long size);
}

#endif //PARALLEL_PERSISTENCE_H
