#include <numeric>
#include "PrimeGenerator.h"
#include <iostream>

/**
  * Find the sum of all primes under two million
  */

int main() {
    PrimeGenerator<long long> pg(2000000L);
    long long sum = 0;
    std::cout << std::accumulate(pg.getPrimes().begin(), pg.getPrimes().end(), sum) << std::endl;
}


