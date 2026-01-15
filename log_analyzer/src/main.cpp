#include "analyzer.h"
#include <iostream>
#include <chrono>

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: ./analyzer <file>\n";
        return 1;
    }

    auto start = std::chrono::high_resolution_clock::now();
    AnalysisResult result = analyze_file(argv[1]);
    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> elapsed = end - start;

    std::cout << "Lines: " << result.line_count << "\n";
    std::cout << "Words: " << result.word_count << "\n";
    std::cout << "Unique words: " << result.freq.size() << "\n";
    std::cout << "Time: " << elapsed.count() << " seconds\n";

    return 0;
}
