#include <iostream>
#include <algorithm>
#include <cmath>
#include "PrimeGenerator.h"

/**
  *  Finds the largest prime factor of number
  */
const long long max = 1000000;

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

int main() {
    // Generate primes up to the sqrt of number
    PrimeGenerator<long long> p(max);
    int count = 0;
    std::vector<long long> primes = p.getPrimes();
    for(auto it = primes.begin(); it != primes.end(); it++ ) {
        long long n = *it;
        long long rotation = rotateNumber(n);
        bool flag = true;
        while(n != rotation && flag) {
            if(std::find(primes.begin(), primes.end(), rotation) == primes.end()) {
            flag = false;
            } else {
                rotation = rotateNumber(rotation);
            }
        }
        if (flag) {
            count++;
            primes.erase(std::remove(primes.begin(), primes.end(), rotation), primes.end());
            rotation = rotateNumber(rotation);
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

