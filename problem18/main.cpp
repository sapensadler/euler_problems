#include <iostream>
#include <algorithm>
#include <fstream>
#include <array>

/**
  * Find a route from top to bottom of the triangle in triangle.txt with the highest sum
  * Best algorithm is to go bottom to top to avoid an algorithm with exponential time complexity
  */

const int numberOfRows = 15;

std::array<std::array<int, numberOfRows>, numberOfRows> readTriangle() {
    std::array<std::array<int, numberOfRows>, numberOfRows> triangle {0};
    std::ifstream triangleFile;
    triangleFile.open("triangle.txt");
    if(triangleFile.fail()) {
        std::cout << "Unable to open triangle file" << std::endl;
        std::exit(1);
    }
    int row = 0 , col = 0;
    while(row < numberOfRows) {
        col = 0;
        while(col <= row) {
            triangleFile >> triangle[row][col++];
        }
        row++;
    }
    triangleFile.close();
    return triangle;
}

int findMaxSum(std::array<std::array<int, numberOfRows>, numberOfRows> triangle) {
    std::array<std::array<int, numberOfRows>, numberOfRows> maxSum = {0};
    for(int i =0 ; i < numberOfRows; i++) {
        maxSum[numberOfRows - 1][i] = triangle[numberOfRows-1][i];
    }
    for(int i = numberOfRows - 2; i >=0; i--) {
        for(int j = 0; j <= i; j++) {
           maxSum[i][j] = triangle[i][j] + std::max(maxSum[i+1][j], maxSum[i+1][j+1]);
        }
    }
    return maxSum[0][0];
}


int main() {
    std::array<std::array<int, numberOfRows>, numberOfRows> triangle = readTriangle();
    std::cout << findMaxSum(triangle) << std::endl;
}

