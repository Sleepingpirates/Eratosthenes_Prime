# Programming Assignment 1
Finding primes numbers from 0 to 10^8 using the sieve of Eratosthenes algorithm and 8 threads

## Run 

1. First build the program 
```
g++ -std=c++11 -pthread  threads.cpp -o primes
```

2. Run program
```
./primes
```

3. See result in primes.txt
```
cat primes.txt
```

## Efficiency

Sieve of Eratosthenes is one of the most efficient ways to find primes. The time complexity using Sieve of Eratosthenes is O(N log log N) , where N is the upper limit of the range of numbers being checked for primes.

## Benchmarks

Tested on 14" MBP with M1 pro chip:

```
Model Name:	MacBook Pro
Model Identifier:	MacBookPro18,3
Chip:	Apple M1 Pro
Total Number of Cores:	8 (6 performance and 2 efficiency)
Memory:	16 GB
```
**Result: Average run time of ~350ms.**

Tested on Pc with Ryzen 3900x (On WSL 2.0):

```
OS: Ubuntu 22.04.1 LTS on Windows 10 x86_64
Kernel: 5.15.79.1-microsoft-standard-WSL2
CPU: AMD Ryzen 9 3900X (24) @ 3.800GHz
Memory: 402MiB / 32051MiB
```

**Result: Average run time of ~950ms.**
