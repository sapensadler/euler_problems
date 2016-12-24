#include <iostream>
#include <fstream>
#include <algorithm>

/**
  * Find the largest product of 4 consecutive numbers in the grid in any direction
  * Grid is read in via file numbers.dat
  */

const int SIZE = 20;
const int ADJACENT_NUMBERS = 4;

long long traverse(long long array[SIZE][SIZE]) {
    long long max = 0;
    for(int i = 0; i < SIZE; i++) {
        for(int j = 0 ; j < SIZE; j++) {
            long long productHoriz = 1;
            long long productVert = 1;
            long long productDiagSE = 1;
            long long productDiagNE = 1;

            for(int k = 0; k < ADJACENT_NUMBERS; k++) {
                if(j < SIZE + 1 - ADJACENT_NUMBERS) {
                    productHoriz *= array[i][j+k];
                }
                if(i < SIZE + 1 - ADJACENT_NUMBERS) {
                    productVert *= array[i+k][j];
                }
                if(i < SIZE + 1 - ADJACENT_NUMBERS && j < SIZE + 1 - ADJACENT_NUMBERS) {
                    productDiagSE *= array[i+k][j+k];
                }
                if(i >= ADJACENT_NUMBERS - 1 && j < SIZE +1 - ADJACENT_NUMBERS) {
                    productDiagNE *= array[i-k][j+k];
                }
            }
            max = std::max(productHoriz, max);
            max = std::max(productVert, max);
            max = std::max(productDiagSE, max);
            max = std::max(productDiagNE, max);
        }
    }
    return max;
}

int main() {
    long long array[SIZE][SIZE];
    std::ifstream numbersFile("numbers.dat");
    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++) {
            numbersFile >> array[i][j];
        }
    }
    std::cout << traverse(array) << std::endl;
}

