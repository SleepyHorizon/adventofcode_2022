#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

int main(){
    ifstream file; 
    file.open("advent.txt");

    vector<int> p1;
    vector<int> p2;
    while(!file.eof()){
        string p1_in;
        string p2_in;
        file >> p1_in;
        file >> p2_in;
        if(p1_in == "A"){p1.push_back(1);} //rock
        else if(p1_in == "B"){p1.push_back(2);} //paper
        else if(p1_in == "C"){p1.push_back(3);} //scissor

        if(p2_in == "X"){p2.push_back(1);} //rock
        else if(p2_in == "Y"){p2.push_back(2);} //paper 
        else if(p2_in == "Z"){p2.push_back(3);} //scissor
    }

    int score = 0;
    for(int i = 0; i < p1.size(); ++i){
        if(p2[i] % 3 == (p1[i] + 1) % 3){
            score += (p2[i] + 6);
        } //lost
        else if(p2[i] % 3 == (p1[i] + 2) % 3){
            score += (p2[i] + 0);
        } //won
        else if(p2[i] % 3 == p1[i] % 3){
            score += (p2[i] + 3);
        }
    }
    cout << "score: " << score << endl;

//part 2
    for(int i = 0; i < p1.size(); ++i){
        if(
            p1[i] == 1 && p2[i] == 2 //rock draw
            || p1[i] == 3 && p2[i] == 3 //rock win
            || p1[i] == 2 && p2[i] == 1 //rock draw
        ){p2[i] = 1;} //rock
        else if(
            p1[i] == 1 && p2[i] == 3 //win
            || p1[i] == 2 && p2[i] == 2 //draw
            || p1[i] == 3 && p2[i] == 1 //lose
        ){p2[i] = 2;} //paper
        else if(
            p1[i] == 2 && p2[i] == 3 //win
            || p1[i] == 3 && p2[i] == 2 //draw
            || p1[i] == 1 && p2[i] == 1 //lose
        ){p2[i] = 3;} //scissor
    }
    //recalculation
    score = 0;
    for(int i = 0; i < p1.size(); ++i){
        if(p2[i] % 3 == (p1[i] + 1) % 3){
            score += (p2[i] + 6);
        } //lost
        else if(p2[i] % 3 == (p1[i] + 2) % 3){
            score += (p2[i] + 0);
        } //won
        else if(p2[i] % 3 == p1[i] % 3){
            score += (p2[i] + 3);
        }
    }
    cout << "score: " << score << endl;
    return 0;
}
