// Prime-Generator - PG.hpp
// Copyright (c) 2025 epsill0n epsill0n
// Non-commercial use only. Redistribution or modification prohibited without permission.
// See LICENSE.txt for full terms.

#pragma once

namespace PG {
    inline void get_primes(int n, int*& primes, bool until_n = false) {
        int size = (until_n)*(n) + (!until_n)*(1);

        primes = new int[size];
        int* __primes = ((until_n) ? nullptr : (new int[n]));
        int* __primes_arr = ((until_n) ? primes : __primes);

        int c_id = 1, c_num = 3;
        __primes_arr[0]=2;
        bool isPrime;
        for (; c_id <= n; c_num+=2) {
            isPrime = true;
            for (int p_iter = 0; __primes_arr[p_iter] * __primes_arr[p_iter] <= c_num; ++p_iter) {
                isPrime = isPrime && (c_num % __primes_arr[p_iter]);
                if (!isPrime) break;
            }

            if (isPrime) __primes_arr[c_id++] = c_num;
        }

        if (!until_n) {
            primes[0] = __primes_arr[n-1];
            delete[] __primes;
        }
    }
}