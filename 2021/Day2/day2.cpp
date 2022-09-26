#include <iostream>
#include <fstream>
#include <vector>


int day2part1(){
    std::ifstream f("../Day2/input.txt");

    std::vector<std::string> outputs;
    std::string temp;

     while (std::getline(f, temp)) {
        outputs.push_back(temp);
    }

    int depth = 0;
    int horPos = 0;
    for(std::string s: outputs){
        if(s[0] == 'f'){
            horPos += std::stoi(s.substr(s.find_last_of(' ')+1));
        } else
        if(s[0] == 'u'){
            depth -= std::stoi(s.substr(s.find_last_of(' ')+1));
        } else
        if (s[0] == 'd'){
            depth += std::stoi(s.substr(s.find_last_of(' ')+1));
        }
    }

    return horPos * depth;
}

int day2part2(){
    std::ifstream f("../Day2/input.txt");

    std::vector<std::string> outputs;
    std::string temp;

     while (std::getline(f, temp)) {
        outputs.push_back(temp);
    }

    int depth = 0;
    int horPos = 0;
    int aim = 0;

    for(std::string s: outputs){
        if(s[0] == 'f'){
            horPos += std::stoi(s.substr(s.find_last_of(' ')+1));
            depth += aim * std::stoi(s.substr(s.find_last_of(' ')+1));
        } else
        if(s[0] == 'u'){
            aim -= std::stoi(s.substr(s.find_last_of(' ')+1));
        } else
        if (s[0] == 'd'){
            aim += std::stoi(s.substr(s.find_last_of(' ')+1));
        }
    }

    return horPos * depth;
}