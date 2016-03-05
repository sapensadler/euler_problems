#include <iostream>
#include <cmath>
#include "PrimeGenerator.h"

const long number = 600851475143;
const long max_prime_factor = sqrt(number);


int main() {
    PrimeGenerator<long long> p(max_prime_factor);
    const std::vector<long long> primes = p.getPrimes();
    for(auto it = primes.rbegin(); it != primes.rend(); it++ ) {
        if(number % *it == 0) {
            std::cout << *it << std::endl;
            break;
        }
    }
}

