#include <iostream>
#include <cmath>

/** Returns the sum of x's x's digit to the power of 5
  * ie 1234 would return 1^4 + 2^4 + 3^4 + 4^4
  */
long long sumOfPowerDigits(long long x) {
    long long digitSum = 0;
    while(x > 0) {
        digitSum += pow(x%10,5);
        x /= 10;
    }
    return digitSum;

}

/** A PDI is a number whose sum of digit to some power n is equal to itself 
  * i.e 153 = 1^3 + 5^3 + 3^3. 
  * This prints the sum of perfect digital invariants for the power 5
  * To find a limit we consider the fact that a number x written in decimal
  * notation with n digits is x = a1*10^(n-1) + a2*10^(n-2) + ... a[(n-1]*10^(n-n)
  * and that n is larger than 10^(n-1)
  * and that the sum is always less than (n)*9^5.
  * When n >= 7, n*9^5 is always < 10^(n-1) so we limit ourselves to 6 digit numbers
  */


int main() {
    long long sumOfPerfectDigitalInvariants = 0;
    long long max = 354294; 
    for(int i = 2; i <= max; i++) {
        if(sumOfPowerDigits(i) == i) {
            sumOfPerfectDigitalInvariants += i;
        }
    }
    std::cout << sumOfPerfectDigitalInvariants << std::endl;
    return 0;
}

