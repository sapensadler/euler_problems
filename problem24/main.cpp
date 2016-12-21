#include <iostream>
#include <algorithm>
const int maxNum = 28123;

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

