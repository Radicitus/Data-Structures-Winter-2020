#include <iostream>
#include "proj0.hpp"

int main()
{

    std::string s1 = "CAT";
    std::string s2 = "DOG";
    std::string s3 = "PIG";

    std::map<char, unsigned> solution = { {'A', 5}, {'C', 02}, {'D', 0001}, {'G', 06}, {'I', 9}, {'O', 4}, {'P', 03}, {'T', 0} };

    bool check = verifySolution(s1, s2, s3, solution);
    std::cout << check << std::endl;
    return 0;
}



