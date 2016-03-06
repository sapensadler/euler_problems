#include <iostream>

int main() {
    constexpr long long n = 100;
    constexpr long long sum2 = (n*n*(n+1)*(n+1))/4;
    constexpr long long sumn2 = (n*(2*n+1)*(n+1))/6;
    std::cout << sum2 - sumn2 << std::endl;
}
