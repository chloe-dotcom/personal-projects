CXX = g++
CXXFLAGS = -std=c++20 -O2 -Wall

analyzer: src/main.cpp src/analyzer.cpp
	$(CXX) $(CXXFLAGS) -Iinclude $^ -o analyzer

clean:
	rm -f analyzer
