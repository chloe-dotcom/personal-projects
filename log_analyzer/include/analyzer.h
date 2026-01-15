#pragma once
#include <string>
#include <unordered_map>

struct AnalysisResult {
    size_t line_count;
    size_t word_count;
    std::unordered_map<std::string, size_t> freq;
};

AnalysisResult analyze_lines(
    // reference to a vector of strings
    const std::vector<std::string>& lines,
    size_t start,
    size_t end
);

AnalysisResult merge_results(
    const AnalysisResult& a,
    const AnalysisResult& b
);


AnalysisResult analyze_file(const std::string& filename);
