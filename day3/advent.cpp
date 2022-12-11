#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

int main(){
    ifstream file; 
    file.open("advent.txt");
    int score = 0;
    while(!file.eof()){
        string input;
        file >> input;
        int length = input.length()/2;

        //concatenate
        string A;
        string B;        
        for(int i = 0; i < length; ++i){
            A += input[i];
            B += input[i + length];
        }        
        //find char
        bool error = false;
        char dupe;
        for(int i = 0; i < length; ++i){
            for(int j = 0; j < length; ++j){
                if(A[i] == B[j]){
                    error = true;
                    dupe = A[i];
                }
            }            
        }
        //assign values
        if(error == true){
            if(int(dupe) >= 97 && int(dupe) <= 122) score += (int(dupe) - 96);
            else score += int(dupe) - 38;
        }
    }
    cout << "score 1: " << score << endl;
    file.close();

    //part 2
    file.open("advent.txt");
    score = 0;
    while(!file.eof()){
        string A, B, C;
        file >> A >> B >> C;
        int length_A = A.length();
        int length_B = B.length();
        int length_C = C.length();
        char dupe;
        for(int i = 0; i < length_A; ++i){
            for(int j = 0; j < length_B; ++j){
                for(int k = 0; k < length_C; ++k){
                    if(A[i] == B[j] && A[i] == C[k]){
                        dupe = A[i];
                    }
                }
            }            
        }
        if(int(dupe) >= 97 && int(dupe) <= 122) score += (int(dupe) - 96);
        else score += int(dupe) - 38;
    }
    cout << "score 2: " << score << endl;
    return 0;
}
