#include <iostream>

void calculate(int * result) {
    for(int i = 1; i < 999; i++) {
        for(int j = 998 - i; i + j <= 999 && i <= j && j > 0; j--) {
            int k = 1000 - i - j;
            if(i*i + j*j == k*k) {
                result[0] = i;
                result[1] = j;
                result[2] = k;
                return;
            }
        }
    }
}

int main() {
    int result[3];
    calculate(result);
    std::cout << result[0]*result[1]*result[2] << std::endl;
    return 0;
}

