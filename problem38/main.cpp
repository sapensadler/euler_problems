#include <iostream>
#include <algorithm>
#include <string>


bool isPandigital(std::string number) {
    std::sort(number.begin(), number.end());
    return number == "123456789";
}

int main() {
    int max_pandigital = 0;
    for(int i=1; i < 10000; i++) {
        std::string number = std::to_string(i);
        for(int n = 2; n < 10; n++) {
            number += std::to_string(n*i);
            if(isPandigital(number)) {
                max_pandigital = std::stoi(number);
            }
        }
    }
    std::cout << max_pandigital << std::endl;
    return 0;
}

