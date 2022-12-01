#include "Day11/day11.h"
#include <iostream>
#include <chrono>

using namespace std::chrono;

int main(int argc, char* argv[]) { 
	auto start = high_resolution_clock::now();

	std::cout << "Part 1: " << day11part1() << std::endl;
	std::cout << "Part 2: " << day11part2() << std::endl;

	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);
 
    std::cout << "Time taken: "
         << duration.count() << " ms" << std::endl;
	return 0;
}