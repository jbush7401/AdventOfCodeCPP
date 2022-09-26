#include <iostream>
#include <fstream>
#include <filesystem>
#include <vector>

using namespace std;

int day1part1() {
	ifstream f("../Day1/input.txt");
	int increased = 0;
	if (f.is_open()) {
		string line;
		std::getline(f, line);
		int current = stoi(line);
		while (f >> line) {
			if (stoi(line) > current)
				increased++;
			current = stoi(line);
		}
	}
	return increased;
}

int day1part2() {
	ifstream f("../Day1/input.txt");
	string line;
	int increased = 0;

	vector<int> nums;
	while (f >> line) {
		nums.push_back(stoi(line));
	}

	for (int i = 0; i < nums.size()-3; i++) {
		if ((nums[i + 1] + nums[i + 2] + nums[i + 3]) > (nums[i] + nums[i+1] + nums[i+2]))
			increased++;
	}
	return increased;
}