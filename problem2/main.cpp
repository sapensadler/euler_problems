#include <iostream>

const int MAX = 4000000;

/**
  * Generates fibonnacci numbers and keeps a running total of even numbers less
  * then four million
  */

int main() {
    int sumOfEvenFibNums = 0;
    int fib_previous = 1;
    int fib_current = 2;
    while(fib_current < MAX) {
        if(fib_current % 2 == 0) {
            sumOfEvenFibNums += fib_current;
        }

        int temp = fib_current;
        fib_current += fib_previous;
        fib_previous = temp;
    }
    std::cout << sumOfEvenFibNums << std::endl;
}

