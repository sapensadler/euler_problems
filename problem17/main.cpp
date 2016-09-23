#include <iostream>
#include <string>

std::string convertZeroToTwentyToWords(int i) {
    const static std::string zeroToTwenty[] = {"zero", "one", "two", "three", "four","five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen", "twenty"};
    return zeroToTwenty[i];
}

std::string convertZeroToNinetyNineToWords(int i) {
    if ( i <= 20) {
        return convertZeroToTwentyToWords(i);
    }
    const static std::string tensStrings[]= { "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
    int numberOfTens = i / 10;
    int units = i % 10;
    return tensStrings[numberOfTens-2] + ((units == 0) ? std::string("") : convertZeroToTwentyToWords(units));
}

const std::string convert0To999ToWords(int i) {
    const std::string hundred = "hundred";
    if (i <= 99) {
        return convertZeroToNinetyNineToWords(i);
    }
    int hundreds = i / 100;
    int partSmallerThanHundred = i % 100;
    return convertZeroToTwentyToWords(hundreds) + hundred + 
            ((partSmallerThanHundred == 0) ? std::string("") : std::string("and") + convertZeroToNinetyNineToWords(i % 100));
}

int main() {
    long long len = 0;
    for (int i = 1; i < 1000; i++) {
        len += convert0To999ToWords(i).length();
    }
    len += std::string("onethousand").length();
    std::cout << len << std::endl;
    return 0;
}

