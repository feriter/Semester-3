#include "WordCounter.h"

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cout << "Few arguments";
        return 0;
    }
    auto counter = new CSV::WordCounter();
    counter->CountWords(argv[0]);
    counter->MakeCSVFile(argv[1]);
    return 0;
}
