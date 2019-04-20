//
// Created by semen on 19.04.19.
//

#include <iostream>
#include <thread>

long nfib(long n) {
    std::cout << std::this_thread::get_id() << std::endl;

    long i, j;
    if (n < 2) return 1;
    else {
#pragma    omp    task    shared(i)        if    (n>33)
        i = nfib(n - 1);
        j = nfib(n - 2);
#pragma    omp taskwait
        return i + j + 1;
    }
}

//int main(int argc, char **argv) {
//    long n = 45;
//    long v = 0;
//#pragma    omp    parallel    shared(n, v)
//    {
//#pragma    omp    single
//        v = nfib(n);
//    }
//}



//int main() {
//#pragma omp parallel
//    {
//#pragma omp single
//        {
//#pragma omp task
//            {
//                printf("hello world\n");
//                std::cout << std::this_thread::get_id() << std::endl;
//
//            };
//#pragma omp task
//            {
//                printf("hello again!\n");
//                std::cout << std::this_thread::get_id() << std::endl;
//            };
//        }
//    }
//    return 0;
//}