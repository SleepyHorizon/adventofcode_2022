#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

int main(){
    ifstream file; 
    file.open("advent1.txt");
    int index = 0;
    int count = 0;
    int num = 0;
    vector<int> elves(1, 0);
    while(!file.eof()){
        string str;
        getline(file, str);
        cout << str << endl;
        if(str.empty()){
            cout << "test" << endl;
        }
        if(!str.empty()){
            num = stoi(str);
            elves[index] += num;
        }
        if(str.empty()){
            elves.push_back(0);
            index++;
            count++;
        }
    }

    for(int i = 0; i < count; ++i){
        cout << "Elf " << i << ": " << elves[i] << endl;
    }

    int winner1 = elves[0];
    int win1_index = 0;
    for(int i = 0; i < count; ++i){
        if(i != count && elves[i + 1] > winner1){
            winner1 = elves[i + 1];
            win1_index = i + 1;
        }
        
    }
    elves[win1_index] = 0;
    int winner2 = elves[0];
    int win2_index = 0;
    for(int i = 0; i < count; ++i){
        if(i != count && elves[i + 1] > winner2){
            winner2 = elves[i + 1];
            win2_index = i + 1;
        }
        
    }
    elves[win2_index] = 0;
    int winner3 = elves[0];
    int win3_index = 0;
    for(int i = 0; i < count; ++i){
        if(i != count && elves[i + 1] > winner3){
            winner3 = elves[i + 1];
            win3_index = i + 1;
        }
        
    }

    cout << "winner1: " << winner1 << endl;
    cout << "winner2:" << winner2 << endl;
    cout << "winner3:" << winner3 << endl;
    cout << "Sum: " << winner1 + winner2 + winner3 << endl;
    return 0;
}
