#include <iostream>
#include <cmath>
#include "PrimeGenerator.h"

const long long number = 10000;

/**
  * Find the 10001st Prime number
  */

int main() {
    PrimeGenerator<long long> p(32);
    while(p.getPrimes().size() <= number) {
        p.setMax(p.getMax() * 2);
    }
        std::cout << p.getPrimes()[number] << std::endl;
}

