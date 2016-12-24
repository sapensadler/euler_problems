#include <gmpxx.h>
#include "PrimeGenerator.h"
#include <iostream>

bool isPrime(PrimeGenerator<long long>& pg, long long num) {
    pg.increaseMax(num);
    return std::find(pg.getPrimes().begin(), pg.getPrimes().end(), num) != pg.getPrimes().end();
}

/** 
  * Returns the number of consecutive primes n^2 + a*n + b produces for n = 0,1...
  */
long long generatePrimesLength(PrimeGenerator<long long>& pg, long long a, long long b) {
    int n = 0;
    while(isPrime(pg, std::abs(n*n + a*n + b))) {
        n++;
    }
    return n;
}

int main() {
    PrimeGenerator<long long> pg(1000); 
    std::vector<long long> b_range(pg.getPrimes());
    long long max_primes_length = 0;
    long long max_a = 0;
    long long max_b = 0;
    for(auto a = -999; a < 1000; a++ )
    {
        for(auto b : b_range) {
            long long current_primes_length = generatePrimesLength(pg, a, b);
            if (current_primes_length > max_primes_length ) {
                max_primes_length = current_primes_length;
                max_a = a;
                max_b = b;
            }
            current_primes_length = generatePrimesLength(pg, a, -b);
            if (current_primes_length > max_primes_length ) {
                max_primes_length = current_primes_length;
                max_a = a;
                max_b = -b;
            }
        }
    }
    std::cout << max_a * max_b << std::endl;
    return 0;
}

