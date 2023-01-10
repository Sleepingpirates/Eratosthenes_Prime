#include <iostream>
#include <cmath>
#include <vector>
#include <numeric>
#include <chrono>
#include <fstream>
using namespace std;

const int N = 1e8 + 1;
vector<bool> is_prime(N, true);

void sieve_of_eratosthenes(int limit) {
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= sqrt(limit); i++) {
        if (is_prime[i]) {
            for (int j = 2 * i; j <= limit; j += i)
                is_prime[j] = false;
        }
    }
}

int main() {
    auto start_time = chrono::high_resolution_clock::now();
    sieve_of_eratosthenes(N);
    vector<int> primes;
    for (int i = 2; i <= N; i++) {
        if (is_prime[i]) {
            primes.push_back(i);
        }
    }
    auto end_time = chrono::high_resolution_clock::now();
    auto execution_time = chrono::duration_cast<chrono::milliseconds>(end_time - start_time).count();
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
