#include <iostream>
#include <exception>

/**
  * Find a pythagorean tripple a^2 + b^2 = c^2 st a+b+c=1000
  */

long long findPythagoreanTriple() {
    for(long long i = 1; i < 999; i++) {
        for(long long j = 998 - i; i + j <= 999 && i <= j && j > 0; j--) {
            long long k = 1000 - i - j;
            if(i*i + j*j == k*k) {
                return i*j*k;
            }
        }
    }
    // Not found
    throw new std::exception();
}

int main() {
    std::cout << findPythagoreanTriple() << std::endl;
    return 0;
}

