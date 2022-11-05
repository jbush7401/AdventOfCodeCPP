#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

unsigned long long lanternFish[9] = {0,0,0,0,0,0,0,0,0};
unsigned long long zeros;

int day6part1(){
    std::ifstream f("../Day6/input.txt");
    std::string temp;
    std::getline(f, temp);

    std::stringstream ss(temp);
    for(int i; ss >>i;){
        lanternFish[i]++;
        if(ss.peek() == ',')
            ss.ignore();
    }
    
    for(int i = 0; i <=79; i++){
        zeros = lanternFish[0];
        for(int k = 1; k < 9; k++){
            lanternFish[k-1] = lanternFish[k];
        }
        lanternFish[6] += zeros;
        lanternFish[8] = zeros;
    }
    int sum = 0;
    for(int x : lanternFish)
        sum += x;
    return sum;
}

long day6part2(){
    for(int i = 80; i <=255; i++){
        zeros = lanternFish[0];
        for(int k = 1; k < 9; k++){
            lanternFish[k-1] = lanternFish[k];
        }
        lanternFish[6] += zeros;
        lanternFish[8] = zeros;
    }
    long sum = 0;
    for(long x : lanternFish)
        sum += x;
    return sum;
}                      