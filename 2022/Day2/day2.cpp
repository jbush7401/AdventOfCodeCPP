#include <iostream>
#include <fstream>
#include <vector>

enum RPS{
    Rock=1, Paper=2, Scissors=3
};

class PlayerSelection{
    public:
        PlayerSelection(char c){
            if(c == 'A' | c == 'X')
                choice = Rock;
            else if (c == 'B' | c == 'Y')
                choice = Paper;
            else
                choice = Scissors;
        }

        PlayerSelection(char c, PlayerSelection them){
            if (c == 'Y')
                choice = them.choice;
            else {
                if (them.choice == Rock){
                    if(c == 'X')
                        choice = Scissors;
                    else
                        choice = Paper;
                } else if (them.choice == Paper){
                    if(c == 'X')
                        choice = Rock;
                    else
                        choice = Scissors;
                } else if (them.choice == Scissors){
                    if(c == 'X')
                        choice = Paper;
                    else
                        choice = Rock;
                }
            }
        }
        RPS choice;

        int scoreForRound(PlayerSelection them){
            if (choice == them.choice)
                return 3 + choice;
            else if ((choice == Rock & them.choice == Scissors) || (choice == Scissors & them.choice == Paper) || (choice == Paper & them.choice == Rock))
            {
                return 6 + choice;
            }
            else
                return choice;
        }
};

std::ifstream f("../Day2/input.txt");
 int totScore = 0;
int totScoreP2 = 0;

int day2part1(){
    std::string temp;
    while (std::getline(f, temp)) {
        totScore += PlayerSelection(temp[2]).scoreForRound(PlayerSelection(temp[0]));
        totScoreP2 += PlayerSelection(temp[2], PlayerSelection(temp[0])).scoreForRound(PlayerSelection(temp[0]));
    }
    return totScore;
}

int day2part2(){
    return totScoreP2;
}