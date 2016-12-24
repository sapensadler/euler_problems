#include <iostream>
#include <algorithm>

/**
  * Returns the sum of all amicable pairs under 1000
  */

int sumOfProperDivisors(int x) {
    int sum = 0;
    for(int i = 1; i < x; i++) {
        if(x % i == 0) {
            sum += i;
        }
    }
    return sum;
}

bool isAmicable(int x) {
    int sum = sumOfProperDivisors(x);
    return x != sum && x == sumOfProperDivisors(sum);
}

int main() {
    int sum = 0;
    for(int i = 2 ; i < 10000; i++) {
        if(isAmicable(i)) {
            sum += i;
        }
    }
    std::cout << sum << std::endl;
    return 0;
}

