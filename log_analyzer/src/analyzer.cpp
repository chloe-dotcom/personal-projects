#include "analyzer.h"
#include <fstream>
#include <sstream>

AnalysisResult analyze_file(const std::string& filename) {
    AnalysisResult result{0, 0, {}};

    std::ifstream file(filename);
    std::string line;

    while (std::getline(file, line)) {
        result.line_count++;

        std::istringstream iss(line);
        std::string word;
        while (iss >> word) {
            result.word_count++;
            result.freq[word]++;
        }
    }

    return result;
}
