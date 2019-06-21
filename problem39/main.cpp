#include <iostream>
#include <cmath>


int main() {
    int p = 12;
    int max_count = 1;
    int p_max = 12;
    for(;p<1000;p++) {
        int current_count = 0;
        for(int i=1; i < p; i++) {
            for(int j=1; i+j < p; j++) {
                int k = p-i-j;
                if(i*i+j*j==k*k) {
                    current_count++;
                }
            }
        }
        if (current_count > max_count) {
            max_count = current_count;
            p_max = p;
        }
    }
    std::cout << p_max << std::endl;

    return 0;
}

