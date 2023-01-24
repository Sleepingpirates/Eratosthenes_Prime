# Programming Assignment 1
Finding prime numbers from 0 to 10^8 using the Sieve of Eratosthenes algorithm and 8 threads.

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

The Sieve of Eratosthenes is one of the most efficient ways to find prime numbers. Its time complexity is O(N log log N), where N is the upper limit of the range of numbers being checked for primes.

## Benchmarks

Tested on 14" MBP with M1 pro chip:

```
Model Name:	MacBook Pro
Model Identifier:	MacBookPro18,3
Chip:	Apple M1 Pro
Total Number of Cores:	8 (6 performance and 2 efficiency)
Memory:	16 GB
```
**Result: Average run time of ~335ms.**

Tested on Pc with Ryzen 3900x (On WSL 2.0):

```
OS: Ubuntu 22.04.1 LTS on Windows 10 x86_64
Kernel: 5.15.79.1-microsoft-standard-WSL2
CPU: AMD Ryzen 9 3900X (24) @ 3.800GHz
Memory: 402MiB / 32051MiB
```

**Result: Average run time of ~950ms.**

## Proof of correctness

My initial approach was to use trial division. This method involves dividing a number by all integers from 2 to its square root. If the number is not divisible by any of these integers, it is a prime number. However, this method would take forever for numbers up to 10^8. A quick Google search led me to the Sieve of Eratosthenes (https://www.geeksforgeeks.org/sieve-of-eratosthenes/), which is known to be one of the most efficient algorithms for finding prime numbers.

I first implemented a non-threaded version of this algorithm and then added 8 threads. I also recorded the results of both versions for experimental evaluation.

The Sieve of Eratosthenes is efficient as its time complexity is O(N log log N).

## Experimental evaluation

To evaluate the effectiveness of parallelizing this algorithm, I created a non-parallel version of the algorithm (experimental_withoutThreads.cpp). Running this version resulted in a runtime of 2908ms on my MacBook Pro.

```
Without parallel/ with parallel
2908ms/334ms
= 8.706
```

This means that the parallel version of this algorithm is about 8.7 times faster than the non-parallel version. This makes sense since we are using 8 threads for this algorithm.
