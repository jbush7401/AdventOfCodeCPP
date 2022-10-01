#include <iostream>
#include <fstream>
#include <vector>

 std::vector<std::vector <int>> nums;

int day3part1(){
    std::ifstream f("../Day3/input.txt");

    std::string temp;

     while (std::getline(f, temp)) {
        std::vector<int> row;
        for(char& c : temp){
            row.push_back(c-'0');
        }
        nums.push_back(row);
    }

    int count0 = 0;
    int count1 = 0;
    std::string gammaRate, epsilonRate = "";

    int rowLength = nums[0].size();

    for(int i = 0; i < rowLength; i++){
        for(std::vector<int> j : nums){
            if (j[i] == 0)
                count0++;
            else
                count1++;
        }
            if (count0 > count1){
                gammaRate += "0";
                epsilonRate += "1";
            }
            else{
                gammaRate += "1";
                epsilonRate += "0";
            }
            count0 = 0;
            count1 = 0;
            
    }
    
    return std::stoi(gammaRate, 0 , 2) *  std::stoi(epsilonRate, 0 , 2) ;
}

int day3part2(){

    int count0 = 0;
    int count1 = 0;
    std::string oxyGenRat, CO2ScrRat = "";

    std::vector<std::vector <int>> numsCopy = nums;
   
    int i = 0;
    //Getting Oxygen Generator Rate
    while(numsCopy.size() > 1){
        for(std::vector<int> j : numsCopy){
            if (j[i] == 0)
                count0++;
            else
                count1++;
        }

        if (count0 > count1){
            oxyGenRat = "0";
        }
        else {
            oxyGenRat = "1";
        }

        std::vector< std::vector<int>> numsTemp;

        for(std::vector<int> j : numsCopy){
            if (j[i] == std::stoi(oxyGenRat)){
                numsTemp.push_back(j);
            }
        }

        numsCopy = numsTemp;
        
        i++;
        count0 = 0;
        count1 = 0;
       
    }
    oxyGenRat = "";

    for(int i : numsCopy[0])
        oxyGenRat += std::to_string(i);  

    numsCopy = nums;
    i = 0;

    // Find CO2 scrubber rating
    while(numsCopy.size() > 1){

        for(std::vector<int> j : numsCopy){
            if (j[i] == 0)
                count0++;
            else
                count1++;
        }

        if (count0 <= count1){
            CO2ScrRat = "0";
        }
        else {
            CO2ScrRat = "1";
        }

        std::vector< std::vector<int>> numsTemp;

        for(std::vector<int> j : numsCopy){
            if (j[i] == std::stoi(CO2ScrRat)){
                numsTemp.push_back(j);
            }
        }

        numsCopy = numsTemp;
        i++;
        count0 = 0;
        count1 = 0;
    }

    CO2ScrRat = "";

    for(int i : numsCopy[0])
        CO2ScrRat += std::to_string(i);  
    
    return std::stoi(oxyGenRat, 0 , 2) *  std::stoi(CO2ScrRat, 0 , 2);
}