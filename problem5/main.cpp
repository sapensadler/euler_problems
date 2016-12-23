#include <iostream>
#include <numeric>
#include <vector>
#include <algorithm>

long long gcd(long long a, long long b) {
    while(b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

long long lcm(long long a, long long b) {
    return (a*b)/gcd(a, b);
}

int main() {
    std::vector<long long> v;
    v.reserve(20);
    for(long long i = 1; i <= 20; i++) {
        v.push_back(i);
    }
    std::cout << std::accumulate(v.begin(), v.end(), 1L, lcm) << std::endl;
}
