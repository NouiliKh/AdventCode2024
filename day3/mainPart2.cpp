//
// Created by Khalil Nouili on 05.12.24.
//

#include <iostream>
#include <fstream>
#include <string>
#include <regex>


int main() {
    std::ifstream inputFile("input.txt"); // Open the file
    if (!inputFile) {
        std::cerr << "Error: Could not open the file!" << std::endl;
        return 1; // Exit with error
    }

    std::string line;
    std::string input;

    while (std::getline(inputFile, line)) { // Read each line into 'line'
        input.append(line);
    }


    inputFile.close();
    std::vector<std::string>  vec;
    int result = 0;


    std::regex regexp("do\\(\\)|don't\\(\\)|mul\\(([0-9]+),([0-9]+)\\)");

    std::smatch matches;
    std::string::const_iterator searchStart(input.cbegin());
    bool isEnabled = true;

    while (std::regex_search(searchStart, input.cend(), matches, regexp)) {
        if (isEnabled and matches[1] != "" ) {
            result +=  std::stoi(matches[1]) * std::stoi(matches[2]);
        }
        if (matches[0] == "do()"){
            isEnabled= true;
        }
        if (matches[0] == "don't()"){
            isEnabled= false;
        }
        searchStart = matches.suffix().first;
    }

    std::cout << result << std::endl;


    return 0;


}
