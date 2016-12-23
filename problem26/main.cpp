#include <cmath>
#include <iostream>
#include <string>

int ten_pow_mod_denom(int pow, int denominator) {
    int result = 1;
    for(int i = 0; i < pow; i++) {
        result = (result * 10) % denominator;
    }
    return result;
}


int get_cycle_length(int denominator) {
        int remainder = -1;
        int count = 1;
        while (denominator % 2 == 0)
            denominator /= 2;
        while (denominator % 5 == 0) 
            denominator /= 5;
        while(remainder != 0 && remainder != 1) {
            remainder = ten_pow_mod_denom(count++, denominator);
        }
    return remainder ? count-1 : 0;
}

int main() {
    int max_cycle_length = 1;
    int longest_cycle_denominator = -1;
    for(int i = 2; i < 1000; i++) {
        int current_cycle_length = get_cycle_length(i);
        if(current_cycle_length > max_cycle_length) {
            max_cycle_length = current_cycle_length;
            longest_cycle_denominator = i;
        }
    }
    std::cout << longest_cycle_denominator << " " << max_cycle_length << std::endl;
    return 0;
}

