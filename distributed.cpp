//
// Created by semen on 12.04.19.
//
#include <boost/mpi.hpp>
#include <boost/filesystem.hpp>

#include "sequential.hpp"
#include "persistence.hpp"
#include "Timer.hpp"

namespace {
    long number_of_subdirectories(const std::string &directory_path) {
        boost::filesystem::directory_iterator begin(directory_path);
        boost::filesystem::directory_iterator end;
        return std::count_if(
                begin,
                end,
                [](const boost::filesystem::directory_entry &d) {
                    return is_directory(d.path());
                }
        );
    }
}


int main(int argc, char **argv) {
    boost::mpi::environment environment(argc, argv);
    boost::mpi::communicator world;

    std::string base_prefix = "/home/semen/drive/workspace.cpp/parallel/data/tasks/";

    int rank = world.rank();
    int world_size = world.size();
    long number_of_tasks = number_of_subdirectories(base_prefix);

    if (rank == 0) {
        std::cout << "world size: " << world_size << std::endl;
        std::cout << "number of tasks: " << number_of_tasks << std::endl;
    }

    Timer timer;

    if (rank == 0) {
        timer.start();
    }

    for (int task = rank; task < number_of_tasks; task += world_size) {
        std::cout << "process " << rank << " task " << task << std::endl;

        std::string a_path = base_prefix + std::to_string(task) + "/a.txt";
        std::string b_path = base_prefix + std::to_string(task) + "/b.txt";
        std::string result_path = base_prefix + std::to_string(task) + "/result.txt";

        std::vector a = persistence::read_vector(a_path);
        std::vector b = persistence::read_vector(b_path);

        std::vector<int> result = sequential::multiply(a, b);
        persistence::write_vector(result_path, result);
    }

    world.barrier();
    if (rank == 0) {
        timer.stop();
        std::cout << "execution time: " << timer.get_duration().count() << std::endl;
    }
    return 0;
}
