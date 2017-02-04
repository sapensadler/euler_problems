#include <iostream>
#include <string>
#include <set>
#include <algorithm>

std::string digits = "123456789";

/**
  * Find the sum of all pandigital produts. A pandigital product is a number c
  * such that a * b == c and each digit 1-9 is contained in exclusivley a,b or c exactly once. 
  * e.g. 39*186=7254
  * This algorithm tests each permutation of digits 1-9, placing * and = in every possible place and then
  * tests whether the a*b == c.
  */

int main() {
    std::set<int> pandigitalProducts;
    do {
        for(int i = 1; i < 8; i++)
        {
            for(int j = i + 1; j < 9; j++) {
                auto firstNum = std::stoi(digits.substr(0, i));
                auto secondNum = std::stoi(digits.substr(i, j-i));
                auto lastNum = std::stoi(digits.substr(j, 9-j));
                if(firstNum * secondNum == lastNum) {
                    pandigitalProducts.insert(lastNum);
                }
            }
        }
    } while (std::next_permutation(digits.begin(), digits.end()));

    std::cout << std::accumulate(pandigitalProducts.begin(), pandigitalProducts.end(), 0, [](int x, int y) { return x + y; } ) << std::endl;
    return 0;
}

