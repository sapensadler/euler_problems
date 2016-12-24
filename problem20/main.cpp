#include <iostream>
#include <gmpxx.h>

/**
  * Calculate the sum of the digits of 100!
  */

mpz_class factorial(mpz_class n) {
    mpz_class factorial = 1;
    while(n >= 1) {
        factorial *= n;
        n = n - 1;
    }
    return factorial;
}

int main() {
    mpz_class num = factorial(mpz_class(100));
    mpz_class sum = 0;
    const mpz_class base = 10;
    while (num > 0) {
        sum += num % base;
        num /= base;
    }
    std::cout << sum.get_str() << std::endl;
    return 0;
}

