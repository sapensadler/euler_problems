#include <iostream>
#include <vector>

/**
  * Calculate the sum of numbers that cannont be expressed as the sum of abundant numbers
  */

const int maxNum = 28123;

std::vector<int> getAbundantNumbers(int max = maxNum) {
    std::vector<int> abundantNumbers;
    for(int i = 12; i <= max; i++) {
        int sum = 1;
        for(int divisor = 2; divisor * divisor <= i; divisor++) {
            if (i % divisor == 0) {
                sum += divisor;
                if (i != divisor * divisor) {
                    sum += i / divisor;
                }
            }
        }
        if (sum > i) {
            abundantNumbers.push_back(i);
        }
    }
    return abundantNumbers;
}


int main() {
    std::vector<int> abundantNumbers = getAbundantNumbers();
    bool isAbundantSum [maxNum * 2 + 1] = {0};

    for(unsigned int i = 0; i < abundantNumbers.size(); i++) {
        for(unsigned int j = i; j < abundantNumbers.size(); j++) {
            isAbundantSum[abundantNumbers[i]+abundantNumbers[j]] = true;
        }
    }

    int sum = 0;
    for(int i = 1; i <= maxNum; i++)
        sum += isAbundantSum[i] ? 0 : i;

    std::cout << sum << std::endl;

}

