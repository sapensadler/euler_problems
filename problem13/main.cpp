#include <iostream>
#include <fstream>
#include <cstdlib>
#include <sstream>

/**
  * Find the first 10 digits of the sum of 100, 50 digit numbers in numbers.dat
  * Could alternatively use gmp library here.
  * Numbers are 50 digits long. Reads in the first 11  digits of the number and
  * convert to long long as the resulting number will be 13 digits long, hence the
  * 12th+ number can not affect the 10th resultant digit
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
    if(inFile.fail()) {
        std::cout << "Unable to open data file" << std::endl;
        std::exit(1);
    }
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

