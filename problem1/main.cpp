#include <iostream>

/**
  * Calculates the sum from 1 up to n
  */
int calculateSum(const int n) {
    return (n*(n+1))/2;
}

/**
  * Returns sum multiple1*n from n = 1 to max/multiple1 plus
  * Returns sum multiple2*n from n = 1 to max/multiple2 minus
  * Returns sum multiple1*multiple2*n from n = 1 to max/(multiple1*multiple2)
  */
int calculateSumOfMultiples(const int multiple1, const int multiple2, const int max) {
    int sum = 0;
    sum += multiple1 * calculateSum(max / multiple1);
    sum += multiple2 * calculateSum(max / multiple2);
    sum -= multiple1 * multiple2 * calculateSum(max / (multiple2 * multiple1));
    return sum;
}

/**
  * Display the sums of the multiples of 3 and 5 between 1 and a thousand
  */

int main() {
    std::cout << calculateSumOfMultiples(3, 5, 999) << std::endl;
    return 0;
}

