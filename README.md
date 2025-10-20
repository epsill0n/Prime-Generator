# Implementation of an algorithm for generating prime numbers

> This repository implements an algorithm for generating prime numbers.
> It uses a bottom-up dynamic programming approach.

<h1>Algorithm</h1>

By the fundamental theorem of arithmetic, every number $n$ can be expressed as the product of prime numbers:

$$
\large \displaystyle
n = {p_1}^{\alpha_1} \cdot {p_2}^{\alpha_2} \cdot \cdots \cdot {p_k}^{\alpha_k} = \prod_{i=1}^{k} {p_i}^{\alpha_i}
$$

Let

$$
\large \displaystyle
\mathcal{P} = \{p_1, p_2, \cdots, p_k\}
$$

be the set of prime factors of $\large \displaystyle n$, and let

$$
\large \displaystyle
\mathcal{A} = \{\alpha_1, \alpha_2, \cdots, \alpha_k\}
$$

be the set of the degrees of each of the primes in the prime factorization of $\large \displaystyle n$, all so that

$$
\large \displaystyle
\forall i \in \{1,2,\cdots,k\} \land \forall j \in \{1,2,\cdots,k\} \land i < j
$$

$$
\large \displaystyle 
{p_i}^{\alpha_i} < {p_j}^{\alpha_j}
$$

<br>

Of course, every prime factor of $\large \displaystyle n$ is less than $\large \displaystyle n$ (except the case when $\large \displaystyle n$ is prime, hence only one prime factor $p$ with $\large \displaystyle \alpha=1$ $\large \displaystyle \iff$ $\large \displaystyle n = p$):

$$
\large \displaystyle
n = {p_1}^{\alpha_1} \cdot {p_2}^{\alpha_2} \cdot \cdots \cdot {p_k}^{\alpha_k} > {p_k}^{\alpha_k} > \cdots > {p_2}^{\alpha_2} > {p_1}^{\alpha_1}
$$

$$
\large \displaystyle
\implies
$$

$$
\large \displaystyle
n > p_k \land \cdots \land n > p_2 \land n > p_1
$$

<br>

If we have a set $\large \displaystyle \Omega$ of all the prime numbers less than the number $\large \displaystyle z$:

$$
\large \displaystyle
\Omega_z = \{p_{z_1}, p_{z_2}, \cdots, p_{z_m} \mid p_{z_j} < z \}
$$

we can get the the set $\large \displaystyle \Omega_{z+1}$ by:

$$
\large \displaystyle 
\Omega_{z+1} = 
\begin{cases}
\Omega_z \cup \{z\} &\text{if $z$ is prime} \\
\Omega_z &\text{otherwise}
\end{cases}
$$

We can check if $\large \displaystyle z$ is prime by dividing it with the primes of the set $\large \displaystyle \Omega_{z-1}$. More precisely (for optimization purposes), with all of the primes within that set that are less than or equal to the square root of $\large \displaystyle z$.

<br>

We start with the set $\large \displaystyle \Omega = \{2\}$, initial value for $\large \displaystyle z$ of $\large \displaystyle 3$, and check if $\large \displaystyle z$ is divisible with all the primes less than or equal to the square root of $\large \displaystyle z$ that are in $\large \displaystyle \Omega$. 

If $\large \displaystyle z$ is prime, we add it to the set; if it is composite we do nothing. After that we increment $\large \displaystyle z$ and continue the procedure until $\large \displaystyle z$ exceeds $\large \displaystyle n$.


## Table of Contents
1. [Overview](#implementation-of-an-algorithm-for-generating-prime-numbers)
2. [Content & Functionality](#content--functionality)
3. [C++ Implementation](#c-implementation)
4. [Usage](#usage)
5. [Benchmark](#benchmark)
6. [License](#license)

---

<h2>Content & Functionality</h2>

```
Prime-Generator/
├── pg.hpp
├── main.cpp
├── main.exe                 (need to be built)
│
├── README.md
└── LICENSE.txt
```

> **Note:** The compiled C++ binary intentionally uses the `.exe` suffix for naming consistency and clarity across platforms.  
> Although this project builds and runs on Linux, macOS, and Windows alike, the `.exe` extension is retained to clearly mark executable files and maintain uniformity in documentation and build scripts.

<h2>Usage</h2>  

<h3>C++</h3>

Inside the root directory (`Prime-Generator`) run:
```bash
g++ main.cpp -o main.exe
```
to compile `main.cpp` to `main.exe`.

The executable take 2 CLI arguments: 
1. $n$;
2. Indicator whether or not to print only the n-th prime or all the primes until it: 0 means that *only the n-th prime will be printed*; any other value means that *the first n primes will be printed*.

<br>
<br>

**In the end, the time it took to do the computations for calculating the prime(s) is printed.**

<br>
<br>
<br>
<br>

Example:
```bash
./main.exe 10000 0
```
prints only the 10000th prime number.

Output:
```bash
104729 
Time: 11.0478620000ms
```

<br>
<br>

Example:
```bash
./main.exe 9 1
```
prints the first 9 prime numbers.

Output:
```bash
2 3 5 7 11 13 17 19 23 
Time: 0.0013530000ms
```


<h3>C++ Initialization Note</h3>

The C++ executables include a small initialization function at startup:

```cpp
__attribute__((constructor)) void init() {
#ifdef FAST_IO
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
#endif
}
```

Details:
1. The `__attribute__((constructor))` syntax is **specific to GCC and Clang**. It ensures that `init()` executes automatically before `main()`.
2. On **MSVC (Microsoft Visual C++)**, this attribute is not supported, so the function will not run automatically. MSVC users would need to call **init()** manually if necessary.
3. What `init()` does: 
- Enables fast I/O if `FAST_IO` is defined.

> Users do not need to call this function manually on GCC/Clang platforms. It ensures that the program starts in a ready state for both sequential and concurrent computations.


<h2>Benchmark</h2>

### Setup

| Component        | Specification                                                 |
|------------------|---------------------------------------------------------------|
| CPU              | AMD Ryzen 7 5825U                                             |
| RAM              | 16 GiB DDR4 SDRAM                                             |
| OS               | openSUSE Tumbleweed                                           |
| C++ Compiler     | g++ (GCC) 14.2.1                                              |
| Fast I/O (C++)   | Enabled via `FAST_IO` macro                                   |

---

#### Results

| n          | Time (ms)     | Prime     |
|------------|---------------|------------|
| 10         | 0.001683      | 29         |
| 100        | 0.007735      | 541        |
| 1,000      | 0.128610      | 7,919      |
| 10,000     | 2.591009      | 104,729    |
| 50,000     | 24.166586     | 611,953    |
| 100,000    | 57.822811     | 1,299,709  |
| 500,000    | 535.955632    | 7,368,787  |
| 1,000,000  | 1395.451468   | 15,485,863 |
| 2,000,000  | 3795.409274   | 32,452,843 |
| 4,000,000  | 9918.877565   | 67,867,967 |

<h2>Changelog</h2>

- Added optimization:
    - Step of 2 to check only odd numbers;
    - Break the for loop checking divisors of the number when a divisor is found.

<h2>Soon</h2>

- Planned support for arbitrary precision (via **GMP**). 

<h2>License</h2>

Copyright (c) 2025 epsill0n epsill0n.  
**All rights reserved.**

This project may be used for **personal, academic, or research purposes only**.  
Commercial use, redistribution, or modification is strictly prohibited without explicit written permission from the author.  

You are welcome to **study the code, suggest improvements, or propose collaborations**.  
See the [LICENSE.txt](LICENSE.txt) file for full terms.
