#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

std::vector<int> calories;

int day1part1(){
    std::ifstream f("../Day1/input.txt");
    std::string temp;
    int totCals = 0;

    while (std::getline(f, temp)) {
        if(temp == ""){
            calories.push_back(totCals);
            totCals = 0;
        } else
        totCals += stoi(temp);
    }
    std::sort(calories.begin(), calories.end(), std::greater<>());
    return calories[0];
}

int day1part2(){
    return calories[0] + calories[1] + calories[2];
}