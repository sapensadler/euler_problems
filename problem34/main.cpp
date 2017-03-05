#include <iostream>
#include <map>
#include <vector>

/**
  * Returns a vector of digits of a number
  */
std::vector<int> getDigits(int x) {
    std::vector<int> result;
    while (x > 0 ) {
        result.push_back(x%10);
        x /= 10;
    }
    return result;
}

/* Returns factorial of the digit n */
int getFactorial(int n) {
    static std::map<int, int> digitFactorials {{0,1},{1,1},{2,2},{3,6},{4,24},
                                        {5,120},{6,720},{8,40320},{9,362880}};
    return digitFactorials[n];
}

long long sumOfDigitsFactorial(long long n) {
    long long sum = 0;
    for(int digit : getDigits(n)) {
        sum += getFactorial(digit);
    }
    return sum;
}

/**
  * Find all numbers st the sum of the factorial of each digit equals itself
  * e.g. 145 = 1! + 4! + 5!
  * We can limit the search space by noticing that an n digit number a is
  * sum (i=0 to n) of 10^ia_i is larger than 10^n
  * and the sum (i=1 to n-1) of a_i ! < (n) * 9! Find n st 10^(n-1) > n*9!
  * This is always true for n>8. So we now have a limit of 2540160 (7*9!)
  */
int main() {
    long long sum = 0;
    for(long long int i = 3; i <= 2540160; i++) {
        if(i == sumOfDigitsFactorial(i)) {
            sum += i;
        }
    }
    std::cout << sum << std::endl;
}

