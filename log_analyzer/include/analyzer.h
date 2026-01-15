#pragma once
#include <string>
#include <unordered_map>

struct AnalysisResult {
    size_t line_count;
    size_t word_count;
    std::unordered_map<std::string, size_t> freq;
};

AnalysisResult analyze_file(const std::string& filename);
