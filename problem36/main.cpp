#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>

/**
  * Checks whether string s is palindromic
  */
bool isPalindrome(std::string s) {
    auto start = s.begin();
    auto end = s.end() - 1;
    bool isPalindrome = true;

    while(start < end  && isPalindrome) {
        if(*start != *end) {
            isPalindrome = false;
        }
        start++;
        end--;
    }
    return isPalindrome;
}

/**
  * Convert i to a string using binary representation
  */
std::string intToBinaryString(long long i) {
    std::string binaryString;
    while (i != 0) {
        binaryString = std::to_string(i%2) + binaryString;
        i /= 2;
    }
    return binaryString;
}

/**
  * Check whether i is palindromic in both decimal and binary representations 
  */
bool isDoublePalindromic(long long i) {
    return isPalindrome(intToBinaryString(i)) && isPalindrome(std::to_string(i));
}

/** 
  * Find the sum of all numbers less than a million that are palindromic
  * in their binary and decimal representations
  */
int main() {
    long long max = 999999;
    std::vector<long long> nums(max);
    long long x = 1;
    std::generate(nums.begin(), nums.end(), [&x]{return x++;});
    std::cout << std::accumulate(nums.begin(), std::remove_if(nums.begin(), nums.end(), [](auto n){return !isDoublePalindromic(n);}), 0) << std::endl;
    return 0;
}

