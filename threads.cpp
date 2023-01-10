#include <iostream>
#include <cmath>
#include <vector>
#include <numeric>
#include <chrono>
#include <fstream>
#include <thread>
using namespace std;

// This sets the upper limit of the range of numbers to check for primes. 
// The value is set to 1e8 + 1, which is equivalent to 100,000,001
const int N = 1e8 + 1;
// This creates a vector of boolean values representing whether 
// each number in the range is prime or not. Initially, all values are set to true.
vector<bool> is_prime(N, true);

// This function is used to perform the sieve of Eratosthenes algorithm on a given range of numbers. 
// It takes two parameters start and end, which represent the start and end of the range of numbers to check. 
// Inside the function it runs the sieve of Eratosthenes algorithm by using two for loop, in the first for loop 
// it starts from 2 and check till sqrt(end) and check is_prime of i is true, in the second for loop it starts 
// from i*i and it's the start_idx, also it check till end, if j is prime it set it as false.
void sieve_of_eratosthenes(int start, int end) {
    for (int i = 2; i <= sqrt(end); i++) {
        if (is_prime[i]) {
            int start_idx = max(i * i, (start + i - 1) / i * i);
            for (int j = start_idx; j <= end; j += i)
                is_prime[j] = false;
        }
    }
}

int main() {
    auto start_time = chrono::high_resolution_clock::now();
    // This creates a new thread and assigns it to run the sieve_of_eratosthenes() function. 
    // The first parameter passed to the function is the start of the range, 2, and the second parameter is the end of the range, N/8. 
    // Similar lines are used to create the other 7 threads with different ranges.
    thread one (sieve_of_eratosthenes, 2, N/8);
    thread two (sieve_of_eratosthenes, N/8 + 1, 2*N/8);
    thread three (sieve_of_eratosthenes, 2*N/8 + 1, 3*N/8);
    thread four (sieve_of_eratosthenes, 3*N/8 + 1, 4*N/8);
    thread five (sieve_of_eratosthenes, 4*N/8 + 1, 5*N/8);
    thread six (sieve_of_eratosthenes, 5*N/8 + 1, 6*N/8);
    thread seven (sieve_of_eratosthenes, 6*N/8 + 1, 7*N/8);
    thread eight (sieve_of_eratosthenes, 7*N/8 + 1, 8*N/8);
    // This tells the main thread to wait for the first thread to finish before moving on to the next line of code. 
    // The join() method is used to wait for each of the 8 threads to finish before moving on.
    one.join();
    two.join();
    three.join();
    four.join();
    five.join();
    six.join();
    seven.join();
    eight.join();

    auto end_time = chrono::high_resolution_clock::now();
    auto execution_time = chrono::duration_cast<chrono::milliseconds>(end_time - start_time).count();
    // This creates an empty vector called 'primes', which will store all the prime numbers found by the algorithm
    vector<int> primes;
    //This for loop runs from 2 to N and check if the number is prime or not, if it's prime, it will store it in primes vector.
    for (int i = 2; i <= N; i++) {
        if (is_prime[i]) {
            primes.push_back(i);
        }
    }

    //The following lines of code are used to calculate the results and write to a file called 'primes.txt'.
    int num_primes = primes.size();
    unsigned int sum_primes = accumulate(primes.begin(), primes.end(), 0);

    ofstream output_file("primes.txt");
    output_file << execution_time << "ms " << num_primes << " " << sum_primes << '\n';
    sort(primes.begin(),primes.end());
    int n = primes.size();
    for(int i = n-1; i>n-11;i--)
    output_file << primes[i] << " ";
    output_file.close();
    return 0;
}
