#include <string>
#include <map>
#include <fstream>
#include <list>
#include <algorithm>
#include <iostream>

namespace CSV {
    class WordCounter {
        std::map <std::string, int> wordsCount;
        unsigned int wordCount;
        unsigned int maxWordLength;

    public:
        void CountWords(std::string filePath);
        void MakeCSVFile(std::string filePath);
        WordCounter() { wordVariety = 0; maxWordLength = 0; wordCount = 0; }
        ~WordCounter() = default;
    };
}
