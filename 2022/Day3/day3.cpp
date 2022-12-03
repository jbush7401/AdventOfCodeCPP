#include <iostream>
#include <fstream>
#include <vector>

char commonChar(std::string a, std::string b){
    for(char c: a){
        if(b.find(c) != std::string::npos)
            return c;
    }
    return '0';
}

char commonChar(std::vector<std::string> s){
     for(char c: s[0])
        if (s[1].find(c) != std::string::npos & s[2].find(c) != std::string::npos)
            return c;
    return '0';
}

int priorityValue(char c) {
    if (isupper(c))
        return (int)c - 38;
    else
        return (int)c - 96;
}
    
std::vector<std::vector<std::string>> groupRugsacks;

int day3part1(){
    int totPriority = 0;
    
    std::ifstream f("../Day3/input.txt");

    std::string temp;

    std::vector<std::string> s;

    while (std::getline(f, temp)) {
        //Part 1
        totPriority += priorityValue(commonChar(temp.substr(0, temp.size()/2), temp.substr(temp.size()/2)));

        //For part 2
        s.push_back(temp);

        if(s.size() > 2){
            groupRugsacks.push_back(s);
            s.clear();
        }
    }
    return totPriority;
}
int day3part2(){
    int totPriority = 0;
    for(std::vector<std::string> s: groupRugsacks)
    {
        totPriority += priorityValue(commonChar(s));
    }
    return totPriority;
}