#include <iostream>
#include <cmath>
#include "PrimeGenerator.h"

const long long number = 10000;

int main() {
    PrimeGenerator<long long> p(32);
    while(p.getPrimes().size() < number) { 
        p.increaseMax(p.getMax() * 2);
    }
        std::cout << p.getPrimes()[number] << std::endl;
}

