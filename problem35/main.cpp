#include <iostream>
#include <algorithm>
#include <cmath>
#include "PrimeGenerator.h"

const long long max = 1000000;

/**
  * Rotate a number n. E.g. 197 becomes 719.
  */
long long rotateNumber(long long n) {
    if(n < 10) {
        return n;
    }
    int lastDigit = n % 10;
    n /= 10;
    if(n== 1)
        return n + lastDigit * std::pow(10, 1);
    return n + lastDigit * std::pow(10, std::ceil(std::log10(n)));
}

/**
  * Count the number of circular primes below max (1000000). 
  * A circular prime is a number, for which all its rotations are prime
  * e.g. 197 is prime as well as its rotations 719 and 971.
  */
int main() {
    // Generate primes up to the sqrt of number
    PrimeGenerator<long long> p(max);
    int count = 0;
    std::vector<long long> primes = p.getPrimes();
    for(auto it = primes.begin(); it != primes.end(); it++ ) {
        long long n = *it;
        long long rotation = rotateNumber(n);
        bool isRotatablePrime = true;
        // Check if this primes rotations are also prime
        while(n != rotation && isRotatablePrime) {
            if(std::find(primes.begin(), primes.end(), rotation) == primes.end()) {
            isRotatablePrime = false;
            } else {
                rotation = rotateNumber(rotation);
            }
        }
        if (isRotatablePrime) {
            count++;
            primes.erase(std::remove(primes.begin(), primes.end(), rotation), primes.end());
            rotation = rotateNumber(rotation);
            // Remove all rotations from the prime list and count them
            while(n != rotation) {
                primes.erase(std::remove(primes.begin(), primes.end(), rotation), primes.end());
                rotation = rotateNumber(rotation);
                count++;
            }
            it--;
        }
    }
    std::cout << count << std::endl;

}

