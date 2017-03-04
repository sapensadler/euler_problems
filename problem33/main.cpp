#include <iostream>
#include <string>
#include <vector>

/**
  * Returns a vector of digits for a two digit numer
  * e.g 48 returns 4 andn 8
  */
std::vector<int> getDigits(int x) {
    std::vector<int> result;
    result.push_back(x/10);
    result.push_back(x%10);
    return result;
}
/**
  * Removes a digit from number eg
  * 48 and 4 would return 8
  * Assumes the digig is in the number already and that num > 10
  */
int removeDigit(int num, int digit) {
    if(num % 10 == digit) {
        return num / 10;
    } else {
        return num % 10;
    }
}
/** Standard euclidean algorithm 
  */
int gcd(int a, int b) {
    if(b==0) {
        return a;
    } else {
        return gcd(b, a%b);
    }
}
/** Returns true iff n1/d1 == n2/d2
  */
bool fractionsEqual(int n1, int d1, int n2, int d2) {
    int gcd1 = gcd(n1, d1);
    n1/=gcd1;
    d1/=gcd1;
    int gcd2 = gcd(n2,d2);
    n2/=gcd2;
    d2/=gcd2;
    return n1==n2 && d1==d2;
}

/** 49/98 = 4/8. A student learing fractions may mistake this as cancelling the 9's.
  * There are 4 such fractions that with numerator and denominator < 99. Finds the 
  * denominator of the prodcut of these four numbers in lowest common form.
  * Note that this excludes obvious candidates such as 10/90 and 11/11. Fractionst must
  * be less than 1
  */
int main() {
    long long prod_num = 1, prod_denum = 1;
    // Works through all numerators 11 to 98
    for(int numerator = 11; numerator < 99; numerator++) {
        // Excluded obvious number
        if ( numerator % 10 == 0) {
            continue;
        }
        std::vector<int> digits = getDigits(numerator);
        for(int digit : digits) {
            for(int i = 1; i < 10 ; i++) {
                // Generate denominator with common digit with common digit being the first digit
                // Could user 10*x + y here. Would save on need for remove digit
                int denominator = std::stoi(std::to_string(digit) + std::to_string(i));
                // New fraction with incorrect cancelling
                int new_numerator = removeDigit(numerator, digit);
                int new_denominator = i;
                if(numerator < denominator && fractionsEqual(numerator, denominator, new_numerator, new_denominator)) {
                        prod_num *= new_numerator;
                        prod_denum *= new_denominator;
                }
                // Generate denominator with common digit with common digit being the second digit
                denominator = std::stoi(std::to_string(i) + std::to_string(digit));
                if(numerator < denominator && fractionsEqual(numerator, denominator, removeDigit(numerator, digit), i)) {
                        prod_num *= new_numerator;
                        prod_denum *= new_denominator;
                }
            }
        }
    }
    std::cout << prod_denum / gcd(prod_num, prod_denum) << std::endl;

    return 0;
}

