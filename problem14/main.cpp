#include <iostream>
#include <algorithm>

long long countSequenceSize(long long n) {
    int count = 1;

    while (n != 1) {
        if (n%2==0) {
            n /= 2;
        } else {
            n = 3*n + 1;   
        }
        count++;
    }
    return count;
}

int main() {
    long long longestChainLength = 1;
    long long longestChainStartNumber = 1;
    for(long long i = 1; i < 1000000; i++) {
        long long currentChainLength = countSequenceSize(i);
        if(longestChainLength < currentChainLength) {
            longestChainLength = currentChainLength;
            longestChainStartNumber = i;
        }
    }
    std::cout << longestChainStartNumber << std::endl;
}

