#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

std::vector<std::vector<int>> heightmap;
std::vector<std::vector<int>> basins;

struct point{
    int x;
    int y;
};



int getBasinSize(point p){
    std::vector<point> toCheck;
    toCheck.push_back(p);
    int size = 1;
    while(toCheck.size() > 0){
        std::vector tempCheck = toCheck;
        for(point q: tempCheck){
            if(q.y > 0)
                if(heightmap[q.y-1][q.x] != 9 && basins[q.y-1][q.x] != 1){
                    basins[q.y-1][q.x] = 1;
                    toCheck.push_back({q.x, q.y-1});
                    size++;
                }
            
            //Check Down
            if(q.y < heightmap.size()-1)
                if(heightmap[q.y+1][q.x] != 9 && basins[q.y+1][q.x] != 1){
                    basins[q.y+1][q.x] = 1;
                    toCheck.push_back({q.x, q.y+1});
                    size++;
                }
            //Check Left
            if(q.x > 0)
                if(heightmap[q.y][q.x-1] != 9 && basins[q.y][q.x-1] != 1){
                    basins[q.y][q.x-1] = 1;
                    toCheck.push_back({q.x-1, q.y});
                    size++;
                }
            //Check Right
            if(q.x < heightmap[0].size()-1)
                if(heightmap[q.y][q.x+1] != 9 && basins[q.y][q.x+1] != 1){
                    basins[q.y][q.x+1] = 1;
                    toCheck.push_back({q.x+1, q.y});
                    size++;
                }
            for(int toErase = 0; toErase < toCheck.size();toErase++){
                if(toCheck[toErase].x == q.x && toCheck[toErase].y == q.y){
                    toCheck.erase(toCheck.begin() + toErase);
                    break;
                }
            }    
        }
    }
    return size;
}

bool isLowPoint(int x, int y){
    //Check Up
    if(y > 0)
        if(heightmap[y-1][x] <= heightmap[y][x])
            return false;
    
    //Check Down
    if(y < heightmap.size()-1)
        if(heightmap[y+1][x] <= heightmap[y][x])
            return false;

    //Check Left
    if(x > 0)
        if(heightmap[y][x-1] <= heightmap[y][x])
            return false;
    //Check Right
    if(x < heightmap[0].size()-1)
        if(heightmap[y][x+1] <= heightmap[y][x])
            return false;
    
    return true;
}

int day9part1(){
    std::ifstream f("../Day9/input.txt");

    std::string temp;
    int sum = 0;
    while(std::getline(f, temp)){
        std::vector<int> i;
        std::vector<int> j;
        for(char c:temp){
            i.push_back((int)c-48);
            j.push_back(0);
    }
        heightmap.push_back(i);
        basins.push_back(j);
    }

    for(int y = 0; y < heightmap.size();y++){
        for(int x = 0; x < heightmap[0].size();x++){
            if(isLowPoint(x, y)){
                sum += heightmap[y][x] + 1;
                basins[y][x] = 1;
            }
        }
    }

    return sum;
}
int day9part2(){
    std::vector<point> lowPoints;
    std::vector<int> basinSizes;
    for(int y = 0; y < basins.size();y++){
        for(int x = 0; x < basins[0].size();x++){
            if(basins[y][x] == 1)
                lowPoints.push_back({x, y});
                
        }
    }
    
    for(auto a:lowPoints)
        basinSizes.push_back(getBasinSize(a));
    std::sort(basinSizes.begin(), basinSizes.end(), std::greater<>());
    return basinSizes[0] * basinSizes[1] * basinSizes[2];
}