#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

int max(int index, vector<int>& elves){
    int winner = 0;
    int win_index = 0;
    for(int i = 0; i < index; ++i){
        if(i != index && elves[i] > winner){
            winner = elves[i];
            win_index = i;
        }
    }
    elves[win_index] = 0;  
    return winner;  
}

int main(){
    ifstream file; 
    file.open("advent1.txt");
    int index = 0;
    vector<int> elves(1, 0);
    while(!file.eof()){
        string str;
        getline(file, str);
        if(!str.empty()){
            int num = stoi(str);
            elves[index] += num;
        }
        else{
            elves.push_back(0);
            index++;
        }
    }
    int winner1 = max(index, elves); 
    int winner2 = max(index, elves);
    int winner3 = max(index, elves);

    cout << "w1: "  << winner1 << endl;
    cout << "w2: " << winner2 << endl;
    cout << "w3: " << winner3 << endl;
    cout << "Sum: " << winner1 + winner2 + winner3 << endl;
    return 0;
}
