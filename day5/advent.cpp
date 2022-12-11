#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

void part_one(){
    ifstream file; 
    file.open("advent.txt");

    vector <vector<string> > crates;
    crates.resize(9);
    for(int a = 0; a < 8; ++a){
        string input;
        getline(file, input);
        for(int i = 0; i < 8 ; ++i){
            string temp = input.substr(1, 1);
            input.erase(0, 4);
            if(temp != " "){
                crates[i].insert(crates[i].begin(), temp);
            }   
        }
        string temp = input.substr(1,1);
        if(temp != " "){
            crates[8].insert(crates[8].begin(), temp);
        } 
    }
    //getting the rest of the inputs
    string trash;
    getline(file, trash);
    getline(file, trash);

    vector <int> number;
    vector <int> start;
    vector <int> end;
    while(!file.eof()){
        string input;
        string temp;
        getline(file, input);
        
        temp = input.substr(input.find("m")+5, input.find("f") - 6);
        number.push_back(stoi(temp));

        temp = input.substr(input.find("f")+5, input.find("f") - 5);
        start.push_back(stoi(temp));

        temp = input.substr(input.find("t")+3, input.find("t")+3);
        end.push_back(stoi(temp));
    }
    //moving
    for(int i = 0; i < number.size(); ++i){ //start moving
        for(int j = 0; j < number[i]; ++j){ //for number of boxes
            string value = crates.at(start[i] - 1).at(crates[start[i] - 1].size() - 1);
            crates[end[i] - 1].push_back(value);
            crates[start[i] - 1].pop_back();
        }
    }
    //output
    for(int i = 0; i < 9; ++i){
        for(int j = 0; j < crates[i].size(); ++j){
            cout << crates[i][j] << " ";
        }
        cout << endl;
    }
    file.close();
}

void part_two(){
    ifstream file; 
    file.open("advent.txt");

    vector <vector<string> > crates;
    crates.resize(9);
    for(int a = 0; a < 8; ++a){
        string input;
        getline(file, input);
        for(int i = 0; i < 8 ; ++i){
            string temp = input.substr(1, 1);
            input.erase(0, 4);
            if(temp != " "){
                crates[i].insert(crates[i].begin(), temp);
            }   
        }
        string temp = input.substr(1,1);
        if(temp != " "){
            crates[8].insert(crates[8].begin(), temp);
        } 
    }
    //getting the rest of the inputs
    string trash;
    getline(file, trash);
    getline(file, trash);

    vector <int> number;
    vector <int> start;
    vector <int> end;
    while(!file.eof()){
        string input;
        string temp;
        getline(file, input);
        
        temp = input.substr(input.find("m")+5, input.find("f") - 6);
        number.push_back(stoi(temp));

        temp = input.substr(input.find("f")+5, input.find("f") - 5);
        start.push_back(stoi(temp));

        temp = input.substr(input.find("t")+3, input.find("t")+3);
        end.push_back(stoi(temp));
    }

    //moving
    for(int i = 0; i < number.size(); ++i){ //start moving
        vector <string> temp;
        for(int j = 0; j < number[i]; ++j){ //for number of boxes
            string value = crates.at(start[i] - 1).at(crates[start[i] - 1].size() - 1);
            temp.push_back(value);
            crates[start[i] - 1].pop_back();
        }
        for(int j = 0; j < number[i]; ++j){
            string value = temp.at(temp.size() - 1);
            crates[end[i] - 1].push_back(value);
            temp.pop_back();
        }
    }

    //output
    for(int i = 0; i < 9; ++i){
        for(int j = 0; j < crates[i].size(); ++j){
            cout << crates[i][j] << " ";
        }
        cout << endl;
    }
    file.close();
}

int main(){
    part_one();
    part_two();
    return 0;
}



