#include <locale>
#include <algorithm>
#include <map>
#include <fstream>
#include <vector>
#include <iostream>

/**
  * Score names based on the product of the position in the file and
  *  the sum of the character values in the name
  */

int calculateNameScore(std::string name) {
    int score = 0;
    for(char c : name) {
        score += 1 + c - 'A';
    }
    return score;
}

/**
  * This struct is used to change the default string separator to include
  * comma, spaces and quotes
  */

struct comma_and_quotes_are_space : std::ctype<char> {
    comma_and_quotes_are_space() : std::ctype<char>(get_table()) {}
    static mask const* get_table()
    {
        static mask rc[table_size];
        rc[' '] = std::ctype_base::space;
        rc[','] = std::ctype_base::space;
        rc['"'] = std::ctype_base::space;
        rc['\n'] = std::ctype_base::space;
        return &rc[0];
    }
};

void readNames(std::ifstream& namesFile, std::vector<std::string>& names) {
    std::string name;
    while(namesFile >> name) {
        names.push_back(name);
    }
}

int main() {
    std::ifstream namesFile;
    namesFile.open("names.txt");
    if(namesFile.fail()) {
        std::cout << "Unable to open names file" << std::endl;
        std::exit(1);
    }
    // DO NOT FREE the locale pointer. It is freed by the standard library, in the destructor
    // WIERD!!!! https://stackoverflow.com/a/7304184/3168708
    // See also http://en.cppreference.com/w/cpp/locale/locale/locale
    namesFile.imbue(std::locale(std::cin.getloc(), new comma_and_quotes_are_space));
    std::vector<std::string> names;
    readNames(namesFile, names);
    namesFile.close();
    std::sort(names.begin(), names.end());
    int pos = 1;
    long long totalScore = 0;
    for(std::string name : names) {
        totalScore += calculateNameScore(name) * pos++;
    }
    std::cout << totalScore << std::endl;
    return 0;
}

