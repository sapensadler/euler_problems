#include <iostream>

int calculateSum(const int n) {
    return (n*(n+1))/2;
}

int calculateSumOfMultiples(const int multiple1, const int multiple2, const int max) {
    int sum = 0;
    sum += multiple1 * calculateSum(max / multiple1);
    sum += multiple2 * calculateSum(max / multiple2);
    sum -= multiple1 * multiple2 * calculateSum(max / (multiple2 * multiple1));
    return sum;
}

int main() {
    std::cout << calculateSumOfMultiples(3, 5, 999) << std::endl;
    return 0;
}

