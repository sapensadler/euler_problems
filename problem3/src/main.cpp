#include <iostream>
#include <cmath>
#include "PrimeGenerator.h"

/**
  *  Finds the largest prime factor of number
  */
const long number = 600851475143;
const long max_prime_factor = sqrt(number);

int main() {
    // Generate primes up to the sqrt of number
    PrimeGenerator<long long> p(max_prime_factor);
    const std::vector<long long> primes = p.getPrimes();
    // Test each prime in reverse order until divisor found
    for(auto it = primes.rbegin(); it != primes.rend(); it++ ) {
        if(number % *it == 0) {
            std::cout << *it << std::endl;
            break;
        }
    }
}

