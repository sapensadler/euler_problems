#include <gmpxx.h>
#include <iostream>

int main() {
    
    mpz_class fib_num = 1;
    mpz_class fib_num_next = 1;
    int i = 1;
    for(; fib_num.get_str().length() < 1000; i++) {
        mpz_class tmp(fib_num_next);
        fib_num_next += fib_num;
        fib_num = tmp;
    }
    std::cout << i << std::endl;
    return 0;
}

