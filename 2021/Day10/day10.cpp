#include <iostream>
#include <vector>
#include <fstream>
#include <stack>
#include <algorithm>

std::vector<std::stack<char>> incomplete;

int day10part1(){
    std::ifstream f("../Day10/input.txt");
    std::string temp;

    // 0 = ), 1 = ], 2 = }, 3 = >
    int score;
    
    int sum = 0;
    while(std::getline(f, temp)){
        std::stack<char> s;
        bool incom = true;
        for(char c:temp){
            if(c == '(' || c == '[' || c == '{' || c == '<')
                s.push(c);
            else if(c == ')'){
                if (s.top() == '(')
                    s.pop();
                else{
                    score += 3;
                    incom = false;
                    break;
                }
            }
            else if(c == ']'){
                if (s.top() == '[')
                    s.pop();
                else{
                    score += 57;
                    incom = false;
                    break;
                }
            }
            else if(c== '}'){
                if (s.top() == '{')
                    s.pop();
                else{
                    score += 1197;
                    incom = false;
                    break;
                }
            }
            else if(c== '>'){
                if (s.top() == '<')
                    s.pop();
               else{
                    score += 25137;
                    incom = false;
                    break;
                }
            }
        }
        if (s.size() > 0 && incom == true)
                incomplete.push_back(s);
    }
    return score;
}

int day10part2(){
    std::vector<long> scores;
    for(std::stack<char> s:incomplete){
        long score = 0;
        while(!s.empty()){
            if(s.top() == '(')
                score = score * 5 + 1;
            else if(s.top() == '[')
                score = score * 5 + 2;
            else if(s.top() == '{')
                score = score * 5 + 3;
            else if(s.top() == '<')
                score = score * 5 + 4;
            s.pop();
        }
        scores.push_back(score);
    }
    std::sort(scores.begin(), scores.end());

    return scores[scores.size()/2];
}