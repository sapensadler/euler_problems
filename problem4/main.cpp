#include <sstream>
#include <iostream>
#include <string>

bool isPalindrome(int n) {
    std::ostringstream oss;
    oss << n;
    std::string strNumber = oss.str();
    auto start = strNumber.begin();
    auto revStart= strNumber.rbegin();
    for(; start <= revStart.base(); start++, revStart++) {
        if(*start != *revStart) {
            return false;
        }
    }
    return true;
}

int main() {
    int largestPalindome =  0;
    for (int i = 100; i < 1000; i++) {
        for(int j = i; j < 1000; j++) {
            int number = i*j;
            if(isPalindrome(number) && number > largestPalindome) {
                largestPalindome = number;
            }
        }
    }
    std::cout << largestPalindome << std::endl;
}

