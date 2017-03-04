#include <gmpxx.h>
#include <iostream>
#include <set>

/**
  * Find the number of unique integers of a^b for all a,b in [2,100] in Z
  */

mpz_class MIN = 2;
mpz_class MAX = 100;

int main() {

    std::set<mpz_class> numbers;
    for(mpz_class a = MIN; a <= MAX; a++) {
            mpz_class a_exp_b = a;
        for(mpz_class b=MIN; b <= MAX; b++) {
            a_exp_b *= a;
            numbers.insert(a_exp_b);
        }
    }
    std::cout << numbers.size() << std::endl;

    return 0;
}

