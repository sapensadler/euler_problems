#include <iostream>
#include <algorithm>

/**
  * Print the millionth lexicographical permutation of '0123456789'
  */

int main() {
    char numbers[] = { '0','1','2','3','4','5','6','7','8','9' };
    for(int i = 0; i < 999999; i++)
    {
        std::next_permutation(numbers, numbers+10);
    }
    for(int i = 0; i < 10; i++) {
        std::cout << numbers[i] ;
    }
    std::cout << std::endl;

}

