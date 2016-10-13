#include <iostream>
#include <algorithm>
#include <fstream>

const int numberOfRows = 15;

int** readTriangle() {
    int **triangle = new int*[numberOfRows];
    for(int i = 0; i < numberOfRows; i++) {
        triangle[i] = new int[numberOfRows];
    }
    std::ifstream triangleFile;
    triangleFile.open("triangle.txt");
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

int findMaxSum(int** triangle) {
    int maxSum[numberOfRows][numberOfRows] = {0};
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
    int** triangle = readTriangle();
    std::cout << findMaxSum(triangle) << std::endl;
    for(int i = 0; i < numberOfRows; i++) {
        delete[] triangle[i];
    }
    delete[] triangle;
}

