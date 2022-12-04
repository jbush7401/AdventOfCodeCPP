#include <iostream>
#include <fstream>

int totOverlaps;
int totLength = 0;

int day4part1(){
    std::ifstream f("../Day4/input.txt");
    std::string temp;

    int nums[] = {0, 0, 0, 0};
    int totFullyContains = 0;

    while (std::getline(f, temp)) {
        
        nums[0] = std::stoi(temp.substr(0, temp.find('-')));
        nums[1] = std::stoi(temp.substr(temp.find('-') + 1, temp.find(',') - temp.find('-') - 1));
        nums[2] = std::stoi(temp.substr(temp.find(',') + 1, temp.find_last_of('-') - temp.find(',') - 1));
        nums[3] = std::stoi(temp.substr(temp.find_last_of('-') + 1, temp.size() - temp.find_last_of('-') - 1));

        if ((nums[2] >= nums[0] && nums[3] <= nums[1]) || (nums[0] >= nums[2] && nums[1] <= nums[3]))
            totFullyContains++;

        if (((nums[2] > nums[1] && nums[3] > nums[1]) || (nums[2] < nums[0] && nums[3] < nums[0])) || ((nums[0] > nums[3] && nums[1] > nums[3]) || (nums[0] < nums[2] && nums[1] < nums[2])))
            totOverlaps++;
        totLength++;
    }
    return totFullyContains;
}
int day4part2(){
    return totLength - totOverlaps;
}