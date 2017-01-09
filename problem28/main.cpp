#include <iostream>

/**
  * Calculates the sum of the numbers which appear on the diagonal of a square starting from 1 
  * and spiralling in a clockwise direction up to max
  * e.g 1 + 3 + 5 + 7 + 9 = 25
  * 7 8 9
  * 6 1 2
  * 5 4 3
  */
unsigned long long sumOfDiagonalNumbers(unsigned long long max) {
	unsigned long long nextNumber = 1;
	unsigned long long sum = 0;
	unsigned long long increment = 2;
	while(nextNumber <= max) {
		for( unsigned long long i = 0; i < 4; i++ )
		{
			if(nextNumber <= max) {
				sum += nextNumber;
				nextNumber += increment;
			}
			else {
				return sum;
			}
		}
		increment += 2;
	}
	//Error
	return -1;
}

/**
  * Calculate the sum of Diagonal NUmbers for a 1001 x 1001 size square 
  */

int main() {
	std::cout << sumOfDiagonalNumbers(1001ull * 1001ull) << std::endl;
}
