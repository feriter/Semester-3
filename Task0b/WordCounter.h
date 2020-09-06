#include <string>
#include <map>
#include <fstream>
#include <list>
#include <algorithm>
#include <iostream>

namespace CSV {
    bool CompareFunc(std::pair <std::string, int> p1, std::pair <std::string, int> p2);

    bool IsLetterOrNumber(char c);

    class WordCounter {
        std::map <std::string, int> wordsCount;
        unsigned int wordVariety;
        unsigned int wordCount;
        unsigned int maxWordLength;

    public:
        void CountWords(std::string fileName = "input.txt");
        void MakeCSVFile(std::string fileName = "output.csv");
        WordCounter() { wordVariety = 0; maxWordLength = 0; wordCount = 0; }
        ~WordCounter() = default;
    };
}