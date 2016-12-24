#include <iostream>

/**
  * Calculate the diference between the sum of squares for the first 100 natural numbers
  * and the square of the sum of the first 100 natural numbers
  */

int main() {
    constexpr long long n = 100;
    constexpr long long sum2 = (n*n*(n+1)*(n+1))/4;
    constexpr long long sumn2 = (n*(2*n+1)*(n+1))/6;
    std::cout << sum2 - sumn2 << std::endl;
}
