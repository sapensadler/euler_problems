#include <iostream>
#include <fstream>
#include <cstdlib>
#include <sstream>

/*
   Numbers are 50 digits long. Reads in the last 10 digits of number (modulo 10) and
   convert to long long
*/
long long readNextNumber(std::ifstream& inputFile) {
    std::string number;
    inputFile >> number;
    if (!inputFile) {
        return 1;
    }
    return atoll(number.substr(0, 11).c_str());
}

int main() {
    std::ifstream inFile("numbers.dat");
    long long value = 1;
    while (inFile) {
       value = (value + readNextNumber(inFile)); 
    }
    std::stringstream sstream;
    sstream << value;
    std::string result;
    sstream >> result;
    std::cout << result.substr(0, 10) << std::endl;
}

