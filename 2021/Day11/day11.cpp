#include <iostream>
#include <vector>
#include <fstream>

struct point{
    int x;
    int y;
};


std::vector<std::vector<int>> octopii;
std::vector<point> toPop;

void processSingle(int x, int y){
    if(octopii[y][x] == 9){
        octopii[y][x] = 0;
        toPop.push_back({x, y});
    } 
    else if(octopii[y][x] > 0)
        octopii[y][x]++;
}

void popOctos(){
    while(toPop.size() > 0){
        std::vector<point> temp = toPop;
        toPop.clear();
        for(point p:temp){
            //Top Left
            if(p.y-1 >=0 && p.x-1 >=0)
                processSingle(p.x-1, p.y-1);
            //Top
            if(p.y-1 >= 0)
                processSingle(p.x, p.y-1);
            //Top Right
            if(p.y-1 >=0 && p.x+1 < octopii[0].size())
                processSingle(p.x+1, p.y-1);
            //Left
            if(p.x-1 >= 0)
                processSingle(p.x-1, p.y);
            //Right
            if(p.x+1 < octopii[0].size())
                processSingle(p.x-1, p.y);
            //Bottom Left
            if(p.y+1 < octopii.size() && p.x-1 >=0)
                processSingle(p.x-1, p.y+1);
            //Bottom
            if(p.y+1 < octopii.size())
                processSingle(p.x, p.y+1);
            //Bottom Right
            if(p.y+1 < octopii.size() && p.x+1 < octopii[0].size())
                processSingle(p.x+1, p.y+1);
            //Left
        }
    }
}



int day11part1(){
    std::ifstream f("../Day11/input.txt");
    std::string temp;

    while(std::getline(f, temp)){
        std::vector<int> line;
        for(char i:temp)
            line.push_back(i-'0');
        octopii.push_back(line);
    }

    for (int i = 1; i <= 200;i++){
        for(int y = 0; y < octopii.size();y++)
            for(int x = 0; x < octopii[0].size(); x++){
                processSingle(x, y);
            }
        popOctos();
    }
    
    return 0;
}
int day11part2(){
    return 0;
}