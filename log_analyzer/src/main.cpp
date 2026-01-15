#include "analyzer.h"

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <thread>
#include <chrono>

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: ./analyzer <file>\n";
        return 1;
    }

    // -----------------------------
    // Read entire file into memory
    // -----------------------------
    std::vector<std::string> lines;
    std::ifstream file(argv[1]);
    std::string line;

    while (std::getline(file, line)) {
        lines.push_back(line);
    }

    // -----------------------------
    // Parallel analysis
    // -----------------------------
    AnalysisResult r1, r2;
    size_t mid = lines.size() / 2;

    auto start = std::chrono::high_resolution_clock::now();

    std::thread t1([&] {
        r1 = analyze_lines(lines, 0, mid);
    });

    std::thread t2([&] {
        r2 = analyze_lines(lines, mid, lines.size());
    });

    t1.join();
    t2.join();

    AnalysisResult final = merge_results(r1, r2);

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;

    // -----------------------------
    // Output results
    // -----------------------------
    std::cout << "Lines: " << final.line_count << "\n";
    std::cout << "Words: " << final.word_count << "\n";
    std::cout << "Unique words: " << final.freq.size() << "\n";
    std::cout << "Time: " << elapsed.count() << " seconds\n";

    return 0;
}
