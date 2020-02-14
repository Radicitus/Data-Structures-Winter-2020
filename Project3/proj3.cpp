#include "proj3.hpp"
#include "Wordset.hpp"
#include <iostream>
#include <sstream>
#include <queue>
#include <map>
#include <stack>

// You should not need to change this function.
void loadWordsIntoTable(WordSet & words, std::istream & in)
{
	std::string line, word;
	std::stringstream ss;

	while(	getline(in, line) )
	{
		ss.clear();
		ss << line;
		while( ss >> word )
		{
			words.insert( word );
		}
	}

}


std::stringstream toString(const std::string& s1, const std::string& s2, std::map<std::string, std::string> & trail) {
    std::stringstream stringTrail;
    std::stack<std::string> flip;

    std::string key = s2;

    while (key != s1 && !trail.empty()) {
        if (key != s2) {flip.push(key);}
        key = trail.at(key);
       
    }


    stringTrail << s1 << " --> ";
    int flipSize = flip.size();
    for (int i = 0; i < flipSize; ++i) {
        stringTrail << flip.top() << " --> ";
        flip.pop();
    }

    stringTrail << s2;

    return stringTrail;
}

// You probably want to change this function.
std::string convert(std::string s1, std::string s2, const WordSet & words)
{
    std::map <std::string, std::string> stringTrail;
    std::queue <std::string> breadthSearch;
    breadthSearch.push(s1);

    //if (!words.contains(s2)) {return s1;}

    while (!breadthSearch.empty()) {

        int currentSize = breadthSearch.size();

        for (int i = 0; i < currentSize; ++i) {
            std::string currentWord = breadthSearch.front();
            breadthSearch.pop();

            for (int j = 0; j < s1.size(); ++j) {

                std::string rootString = currentWord;
                char rootChar = currentWord[j];

                for (char c = 'a'; c <= 'z'; ++c) {

                    currentWord[j] = c;

                    if (currentWord == s2) {
                    	stringTrail.insert( {s2, rootString} );
                        return toString(s1, s2, stringTrail).str();
                    }

                    if (words.contains(currentWord) && (stringTrail.find(currentWord) == stringTrail.end())) {
                        stringTrail.insert( {currentWord, rootString} );
                        breadthSearch.push(currentWord);
                    }
                }

                currentWord[j] = rootChar;

            }
        }
    }

    return toString(s1, s2, stringTrail).str();

}