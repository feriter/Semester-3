#include "WordCounter.h"

namespace CSV {
    bool CompareFunc(const std::pair <std::string, int> & p1, const std::pair <std::string, int> & p2) {
        return (p1.second > p2.second);
    }

    // Without russian letters
    bool IsLetterOrNumber(const char c) {
        return ((c >= '0' && c <= '9') ||
                (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
    }

    void WordCounter::CountWords(std::string filePath) {
        std::ifstream fin(filePath);
        if (!fin) {
            throw std::exception("Unable to read from file");
        }
        char bufferChar;
        std::string bufferString;
        while ((bufferChar = fin.get()) != EOF) {
            if (IsLetterOrNumber(bufferChar)) {
                bufferString += bufferChar;
            } else if (!bufferString.empty()) {
                this->wordsCount[bufferString]++;
                this->maxWordLength = std::max(this->maxWordLength, bufferString.length());
                bufferString = "";
                this->wordCount++;
            }
        }
        if (!bufferString.empty()) {
            this->wordsCount[bufferString]++;
            this->maxWordLength = std::max(this->maxWordLength, bufferString.length());
        }
        fin.close();
    }

    void WordCounter::MakeCSVFile(std::string filePath) {
        std::ofstream fout(filePath);
        if (!fout) {
            throw std::exception("Unable to write in file");
        }
        std::list <std::pair <std::string, int> > sortedByNumberMap;
        for (const auto& it : this->wordsCount) {
            sortedByNumberMap.insert(sortedByNumberMap.begin(), it);
        }
        sortedByNumberMap.sort(CompareFunc);
        // Everything below is just for pretty view of file
        fout << "Word";
        for (int i = 0; i < this->maxWordLength + 2; ++i) {
            fout << " ";
        }
        fout << "Count     Frequency" << std::endl;
        for (const auto& it : sortedByNumberMap) {
            fout << it.first;
            for (int i = 0; i < this->maxWordLength - it.first.length() + 6; ++i) {
                fout << " ";
            }
            fout << it.second;
            for (int i = 0; i < 9 - floor(log10(it.second)); ++i) {
                fout << " ";
            }
            fout << (float)it.second / (float)this->wordCount * 100 << "%" << std::endl;
        }
        fout.close();
    }
}
