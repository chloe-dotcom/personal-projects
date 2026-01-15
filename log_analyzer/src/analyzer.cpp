#include "analyzer.h"
#include <fstream>
#include <sstream>

AnalysisResult analyze_lines(
    const std::vector<std::string>& lines,
    size_t start,
    size_t end
) {
    AnalysisResult result{0, 0, {}};

    for (size_t i = start; i < end; ++i) {
        result.line_count++;

        std::istringstream iss(lines[i]);
        std::string word;

        while (iss >> word) {
            result.word_count++;
            result.freq[word]++;
        }
    }

    return result;
}

AnalysisResult merge_results(
    const AnalysisResult& a,
    const AnalysisResult& b
) {
    AnalysisResult result;
    result.line_count = a.line_count + b.line_count;
    result.word_count = a.word_count + b.word_count;
    result.freq = a.freq;

    for (const auto& [word, count] : b.freq) {
        result.freq[word] += count;
    }

    return result;
}

