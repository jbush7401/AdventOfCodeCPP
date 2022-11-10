#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>

std::vector<int> crabs;
int maxCrab = 0;
int minCrab = INT8_MAX;

int FuelCost(const int position){
    int fuelCost = 0;
    for (int x: crabs){
        fuelCost += abs(x - position);
    }
    return fuelCost;
}

int FixedFuelCost(const int position){
    int fuelCost = 0;
     for (int x: crabs){
        fuelCost += (abs(x - position) * (abs(x - position)+1))/2;
    }
    return fuelCost;
}

int day7part1(){
    std::ifstream f("../Day7/input.txt");
    std::string temp;
    std::getline(f, temp);

    std::stringstream ss(temp);
    for(int i; ss >>i;){
        crabs.push_back(i);
        if(ss.peek() == ',')
            ss.ignore();
    }

    for (int x: crabs){
        if(x > maxCrab)
            maxCrab = x;
        if(x < minCrab)
            minCrab = x;
    }

    int position = minCrab;
    int lowestFuelCost = FuelCost(position);
    int tempFuelCost;

    for (int i = minCrab+1; i<=maxCrab;i++){
        int fuelCostCheck = FuelCost(i);
        if (fuelCostCheck > lowestFuelCost)
            return lowestFuelCost;
        else
            lowestFuelCost = fuelCostCheck;
    }
    return -1;
}

int  day7part2(){
    int position = minCrab;
    int lowestFuelCost = FixedFuelCost(position);
    int tempFuelCost;

    for (int i = minCrab+1; i<=maxCrab;i++){
        int fuelCostCheck = FixedFuelCost(i);
        if (fuelCostCheck > lowestFuelCost)
            return lowestFuelCost;
        else
            lowestFuelCost = fuelCostCheck;
    }
    return -1;
}