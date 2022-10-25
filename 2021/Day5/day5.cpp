#include <iostream>
#include <fstream>
#include <vector>
#include <string>

struct line{
    int x1;
    int y1;
    int x2;
    int y2;
};

std::vector<line> lines;
int biggestX = 0;
int biggestY = 0;

std::vector<std::vector<int>> vents;

void readInput(){
     std::ifstream f("../Day5/input.txt");

    std::string temp;
    line l;

     while (std::getline(f, temp)) {
        //Parse the individual lines to their x and y components.
        l.x1 = std::stoi(temp.substr(0, temp.find(',')));
        l.y1 = std::stoi(temp.substr(temp.find(',')+1, (temp.find('-')-2) - temp.find(',')));
        l.x2 = std::stoi(temp.substr(temp.find('>')+2, (temp.find('>')+2) - temp.find_last_of(',')));
        l.y2 = std::stoi(temp.substr(temp.find_last_of(',')+1));
        
        //Get the size for the 2d vector vents
        if (l.x2 > biggestX)
            biggestX = l.x2;
        if (l.x1 > biggestX)
            biggestX = l.x1;
        if (l.y2 > biggestY)
            biggestY = l.y2;
        if (l.y1 > biggestY)
            biggestY = l.y1;
        lines.push_back(l);
     }

     // Initialize the vents to 0;
     for(int y = 0; y <= biggestY;y++){
        vents.push_back(std::vector<int>());
        for(int x = 0; x <= biggestX;x++)
            vents[y].push_back(0);
    }

}

void printVents(){
    for(int x = 0;x < vents[0].size(); x++){
        for(int y = 0;y < vents.size();y++){
            std::cout << vents[x][y];
        }
        std::cout << std::endl;
    }
}

int totalPoints(){
    int total = 0;
    for(int x = 0;x < vents[0].size()-1; x++)
        for(int y = 0;y < vents.size()-1;y++){
             if(vents[x][y] > 1)
                total++;
        }
    return total;
}

int day5part1(){
    readInput();
    for(line l: lines){
        if(l.x1 == l.x2){
            if(l.y1 < l.y2){
                for(int j = l.y1;j <= l.y2;j++)
                    vents[j][l.x1] += 1;
            }
        else{
            for(int j = l.y1;j >= l.y2;j--)
                    vents[j][l.x1] += 1;
            }
        }
        if(l.y1 == l.y2){
            if(l.x1 < l.x2){
                 for(int j = l.x1;j <= l.x2;j++)
                    vents[l.y1][j] += 1;
            }
        else{
            for(int j = l.x1;j >= l.x2;j--)
                    vents[l.y1][j] += 1;
            }
        }
    }
    return totalPoints();
}

int day5part2(){
    return 0;
}