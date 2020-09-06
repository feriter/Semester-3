#include <map>
#include <string>
#include <fstream>

namespace CSV {
    bool IsLetterOrNumber(char c) {
        return ((c >= 'a' && c <= 'z') ||
                (c >= 'A' && c <= 'Z') || (c >='0' && c <='9'));
    }

    class CSVConverter {
    private:
        std::map <std::string, int> wordsCount;
        int wordVariety;
    public:
        CSVConverter() { wordVariety = 0; };
    ~CSVConverter();
    };
}