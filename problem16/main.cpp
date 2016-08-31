#include <iostream>
#include <gmpxx.h>

int main() {
    mpz_class num;
    mpz_ui_pow_ui(num.get_mpz_t(), 2, 1000);
    mpz_class sum = 0;
    const mpz_class base = 10;
    while (num > 0) {
        sum += num % base;
        num /= base;
    }
    std::cout << sum.get_str() << std::endl;
    return 0;
}

