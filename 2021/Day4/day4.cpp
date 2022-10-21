#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

struct bingoNumber{
    int number  = -1;
    bool checked = false;

};

class bingoBoard{
    public:
        bingoNumber board[25];
        bool won = false;
        void callNumber(int i){
            for(int n = 0;n < 25;n++) {
                if (board[n].number == i){
                    board[n].checked = true;
                }
            }
        }

        bool checkBoard(){
            bool checkHor = true;
            bool checkVer = true;
            for(int x = 1;x <= 5;x++){
                checkHor = true;
                checkVer = true;
                for(int y = (5*(x-1)); y < (5*(x-1))+5;y++){
                    if(board[y].checked == false){
                        checkHor = false;
                        break;
                    }
                }
                for(int y = x; y <= 25; y += 5)
                     if(board[y].checked == false){
                        checkVer = false;
                        break;
                    }
                if(checkHor == true || checkVer == true){
                    won = true;
                    return true;
                }
            }
            return false;
        }

       

};

int part1 = 0;
int part2 = 0;

int day4part1(){
    std::ifstream f("../Day4/input.txt");

    std::string temp;

    //Load the numbers to call array

    std::getline(f, temp);
    std::vector<int> numbersToCall;

    std::stringstream ss(temp);
    std::string num;

    while(std::getline(ss, num, ',')){
        numbersToCall.push_back(std::stoi(num));
    }

    //Load the bingo boards into the vector

    int counter = 0;
    std::vector<bingoBoard> boards;
    std::vector<bingoBoard> wonBoards;

    bingoBoard board;
    while (std::getline(f, temp)) {
        if (temp == "") continue;
        
        for(int i = 0; i <= 13; i += 3){
            board.board[counter].number = std::stoi(temp.substr(i, 2));
            counter++;
        }
        if (counter == 25){
            counter = 0;
            if(board.board[0].number > -1)
                boards.push_back(board);
            board = bingoBoard();
        }

    }
    
    // Run Numbers
    for(int n : numbersToCall){
        //First check all numbers
        for(int i = 0; i < boards.size(); i++){
            if(boards[i].won == false){
            boards[i].callNumber(n);
            bool check = boards[i].checkBoard();
            if(check == true){
                int total = 0;
                if(wonBoards.size() == 0){
                    for(int n = 0;n < 25;n++) {
                        if(boards[i].board[n].checked == false)
                            total += boards[i].board[n].number;
                        }
                    part1 = total * n;
                    total = 0;
                }
                
                wonBoards.push_back(boards[i]);
                if(wonBoards.size() == boards.size()){
                    for(int n = 0;n < 25;n++) {
                        if(boards[i].board[n].checked == false)
                            total += boards[i].board[n].number;
                        }
                    part2 = total * n;
                }
            }
            }
        }
    }
    return part1;
}

int day4part2(){
    return part2;
}