#include "proj1.hpp"
#include <map>
#include <string>
#include <set>
//#include <iostream>


bool puzzleSolver(std::string s1, std::string s2, std::string s3, std::map<char, unsigned> & mapping) {
    std::set<int> digits = {1,2,3,4,5,6,7,8,9};

}







bool verifySolution(std::string s1, std::string s2, std::string s3, const std::map<char, unsigned> & mapping) {
    std::string stringVals[3] = {"", "", ""};
    std::string strings[3] = {std::move(s1), std::move(s2), std::move(s3)};
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < strings[i].length(); j++) {
            stringVals[i] += std::to_string(mapping.at(strings[i][j]));
            //std::cout << stringVals[i] << "-" << strings[i][j] << "-" << mapping.at(strings[i][j]) << std::endl;
        }
    }
    //std::cout << stringVals[0] << "-" << stringVals[1] << "-" << stringVals[2] << std::endl;
    //std::cout << std::stoi(stringVals[0]) + std::stoi(stringVals[1]) << std::endl;
    return std::stoi(stringVals[0]) + std::stoi(stringVals[1]) == std::stoi(stringVals[2]);
}

bool initializeMap(const std::set<std::string>& tempStrings, std::map<char, unsigned> & mapping, std::set<int> & digits) {
    if (mapping.empty()) {
        for (const std::string& string : tempStrings) {
            for (char c : string) {
                if (mapping.count(c) == 0) {
                    
                }
            }
        }
    }
}