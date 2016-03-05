#include <iostream>

const int MAX = 4000000;

int main() {
    int runningTotal = 0;
    int previous = 1;
    int current = 2;
    while(current < MAX) {
        if(current % 2 == 0) {
            runningTotal += current;
        }
        int temp = current;
        current += previous;
        previous = temp;
    }
    std::cout << runningTotal << std::endl;
}

