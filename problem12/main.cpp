#include <iostream>
#include <cassert>

long long getNumberOfDivisors(long long n) {
    assert(n > 0);

    if (n < 2) {
        return 1;
    }
    int divisors = 2;
    for (int i = 1; i*i <= n; i++) {
        if (n % i == 0) {
            divisors += (i*i != n) ? 2 : 1;
        }
    }
    return divisors;
}
long long getTriangleNumber(long long n) {
    return (n*(n+1))/2;
}

/**
  *Find the smallest triangle number with at least 500 divisors
  */

int main() {
    int i = 0;
    while(getNumberOfDivisors(getTriangleNumber(++i)) < 500) ;
    std::cout << getTriangleNumber(i) << std::endl;

}

