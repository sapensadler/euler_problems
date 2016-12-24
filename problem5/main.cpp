#include <iostream>
#include <numeric>
#include <vector>
#include <algorithm>

/**
  * Greatest common divisor or Highest common factor
  * Returns the largest integer that evenly divides both a and b
  */

long long gcd(long long a, long long b) {
    while(b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

/**
  * Lowest common multiple - returns the smallest number for which both a and b evenly divide
  */

long long lcm(long long a, long long b) {
    return (a*b)/gcd(a, b);
}

/**
  * Find the lowest common multiple of 1 through 20
  */

int main() {
    std::vector<long long> v;
    v.reserve(20);
    for(long long i = 1; i <= 20; i++) {
        v.push_back(i);
    }
    std::cout << std::accumulate(v.begin(), v.end(), 1L, lcm) << std::endl;
}

