#include <locale>
#include <algorithm>
#include <map>
#include <fstream>
#include <vector>
#include <iostream>

int calculateNameScore(std::string name) {
    int score = 0;
    for(char c : name) {
        score += 1 + c - 'A';
    }
    return score;
}

struct colons_and_quotes_are_space : std::ctype<char> {
    colons_and_quotes_are_space() : std::ctype<char>(get_table()) {}
    static mask const* get_table()
    {
        static mask rc[table_size];
        rc[':'] = std::ctype_base::space;
        rc[','] = std::ctype_base::space;
        rc['"'] = std::ctype_base::space;
        rc['\n'] = std::ctype_base::space;
        return &rc[0];
    }
};

void readNames(std::ifstream& namesFile, std::vector<std::string>& names) {

    colons_and_quotes_are_space* type = new colons_and_quotes_are_space;
    namesFile.imbue(std::locale(std::cin.getloc(), type));
    std::string name;
    while(namesFile >> name) {
        names.push_back(name);
    }
    delete type;
}

int main() {
    std::ifstream namesFile;
    namesFile.open("names.txt");
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

