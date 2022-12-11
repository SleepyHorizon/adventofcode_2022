#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

int main(){
    ifstream file; 
    file.open("advent.txt");
    string input;
    file >> input;
    int length = input.length();
    int index = 0;
    for(int i = 3; i < length; ++i){
        if(
            input[i-3] == input[i-2]
            || input[i-3] == input[i-1]
            || input[i-3] == input[i]
            || input[i-2] == input[i - 1]
            || input[i-2] == input[i]
            || input[i-1] == input[i]
        ){
        }
        else{
            index = i + 1;
            break;
        }
    }

    int index2;
    for(int i = 13; i < length; ++i){
        int counter = 0;
        for(int j = i - 13; j < i; ++j){
            for(int k = j + 1; k <= i; ++k){
                if(input[j] == input[k]){
                    counter++;
                }
            }
        }
        if(counter == 0){
            index2 = i + 1;
            break;
        }
    }

    cout << "index: " << index << endl;
    cout << "index2: " << index2 << endl;

    file.close();
    return 0;
}



