// Prime-Generator - main.cpp
// Copyright (c) 2025 epsill0n epsill0n
// Non-commercial use only. Redistribution or modification prohibited without permission.
// See LICENSE.txt for full terms.

#include <iostream>
#define FAST_IO

#include "PG.hpp"
#include <chrono>
#include <iomanip>

__attribute__((constructor)) void init() {
#ifdef FAST_IO
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
#endif
}

int main (int argc, char** argv) {
    if (argc != 3) {
        std::cout << "Usage: " << argv[0] << " [n] [1/0 if to print first n, else only the n-th]\n" << std::flush;
        return -1;
    }

    ull n = std::atoi(argv[1]);
    bool until_n = bool(std::atoi(argv[2]));

    ull* primes;

    std::chrono::system_clock::time_point begin, end;
    std::chrono::duration<double, std::milli> elapsed;

    begin = std::chrono::high_resolution_clock::now();
    PG::get_primes(n, primes, until_n);
    end = std::chrono::high_resolution_clock::now();

    ull range = ((until_n) ? (n) : (1));
    // std::cout << "range = " << range << std::endl;
    
    for (ull i = 0; i < range; ++i) {
        // std::cout << "i = " << i << std::endl;
        std::cout << primes[i] << " ";
    } std::cout << "\n";

    delete[] primes;

    elapsed = end - begin;
    std::cout << "Time: " << std::fixed << std::setprecision(10) <<  (elapsed.count()) << "ms\n";

    std::cout << std::flush;
    return 0;
}