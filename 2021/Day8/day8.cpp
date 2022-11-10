#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>

class Code{
    public:
        std::string uniSigPats[10];
        std::string ordered[10];
        std::string outputVal[4];
};

std::vector<Code> codes;

char difference(std::string longer, std::string shorter){
    char d;
    bool in;
    for(char l : longer){
        in = false;
        for(char s : shorter){
            if(s == l)
                in = true;
        }
        if (in == false)
            d = l;
    }
    return d;
}

int day8part1(){
    std::ifstream f("../Day8/input.txt");
    
    std::vector<std::string> tempCodes;
    std::string temp;
    std::string s;
    int counter = 0;
    int uniSegs = 0;
    while(std::getline(f, temp)){
        std::stringstream ss(temp);
        Code c;
        while(std::getline(ss, s, ' ')){
            std::sort(s.begin(), s.end());
            if(s[0] == '|')
                continue;
            //Load First 10 Strings into Unique Signal Patterns
            if(counter <= 9){
                c.uniSigPats[counter] = s;
            }
            //Load Last 4 strings into output digits
            else{
                if(s.length() == 2 || s.length() == 3 || s.length() == 4 || s.length() == 7){
                    uniSegs++;
                }
                c.outputVal[counter-10] = s;
            }
            counter++;
        }
        codes.push_back(c);
        counter = 0;
    }

    return uniSegs;
}


int day8part2(){
    //Top = 0, Top Left = 1 Top Right = 2, Middle = 3, Bottom Left = 4, Bottom Right = 5, Bottom = 6
    char positions[7];
    int finalAns = 0;
    //Solve Top
    for(Code &c : codes){
        for(std::string &us : c.uniSigPats){
            if(us.size() == 2){
                c.ordered[1] = us;
                us = "";
            }
            if(us.size() == 3){
                c.ordered[7] = us;
                us = "";
            }
            if(us.size() == 4){
                c.ordered[4] = us;
                us = "";
            }
            if(us.size() == 7){
                c.ordered[8] = us;
                us = "";
            }
        }
        //Get the top position
        positions[0] = difference(c.ordered[7], c.ordered[1]);

        //Find the number 6
        for(std::string &us : c.uniSigPats){
            if(us.size() == 6){
                if(us.find(c.ordered[1][0]) == std::string::npos){
                    c.ordered[6] = us;
                    us = "";
                    positions[2] = c.ordered[1][0];
                    positions[5] = c.ordered[1][1];
                    break;
                }
                 if(us.find(c.ordered[1][1]) == std::string::npos){
                    c.ordered[6] = us;
                    us = "";
                    positions[2] = c.ordered[1][1];
                    positions[5] = c.ordered[1][0];
                    break;
                }
            }
        }
        for(std::string &us : c.uniSigPats){
            if(us.size() == 5){
                if(us.find(c.ordered[1][0]) != std::string::npos && us.find(c.ordered[1][1]) != std::string::npos){
                    c.ordered[3] = us;
                }
                else if(us.find(positions[2]) != std::string::npos){
                    c.ordered[2] = us;
                }
                else {
                    c.ordered[5] = us;
                }
            }
        }

        for(char f: c.ordered[2]){
            if(c.ordered[3].find(f) == std::string::npos){
                positions[4] = f;
                break;
            }
        }
         for(std::string &us : c.uniSigPats){
            if(us.size() == 6 && us.find(positions[4]) != std::string::npos){
                c.ordered[0] = us;
            }
            else if(us.size() == 6)
                c.ordered[9] = us;
         }
            
        //return the code
        int outputValue = 0;
        int counter = 0;
        int multi = 1000;
        for(std::string s: c.outputVal){
            for(std::string ord: c.ordered){
                if(s == ord){
                    outputValue += counter * multi;
                    multi /= 10;
                    break;
                }
                counter++;
            }
            counter = 0;
        }
        finalAns += outputValue;
    }
    return finalAns;
}