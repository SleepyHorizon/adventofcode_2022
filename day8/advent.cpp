#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

int main(){
    //2d array created
    vector < vector < int > > map;
    ifstream file; 
    file.open("advent.txt");
    while(!file.eof()){
        vector < int > row;
        string input;
        
        file >> input;
        int length = input.length();

        for(int i = 0; i < length; ++i){
            int push = input[i] - '0';
            row.push_back(push);
        }
        map.push_back(row);
    }
    for(int i = 0; i < map.size(); ++i){
        for(int j = 0; j < map[i].size(); ++j){
            cout << map[i][j];
        }
        cout << endl;
    }

    int counter = 0;
    for(int i = 0; i < map[i].size(); ++i){
        for(int j = 0; j < map[i].size(); ++j){ //for every square
            int value = map[i][j];
            bool visible = false;

            int y = i;
            int x = j;             
            while(true){ //check north
                y--;
                if(y < 0){
                    visible = true;
                    break;
                }
                else if (value <= map[y][j]){
                    break;
                }
            }
            y = i;
            x = j;             
            while(true){ //check south
                y++;
                if(y >= map.size()){
                    visible = true;
                    break;
                }
                else if (value <= map[y][j]){
                    break;
                }
            }
            y = i;
            x = j;             
            while(true){ //check east
                x++;
                if(x >= map.size()){
                    visible = true;
                    break;
                }
                else if (value <= map[i][x]){
                    break;
                }
            }
            y = i;
            x = j;             
            while(true){ //check west
                x--;
                if(x < 0){
                    visible = true;
                    break;
                }
                else if (value <= map[i][x]){
                    break;
                }
            }

            if(visible){
                counter++;
            }
        }
    }
    cout << "counter: " << counter << endl;

    //part 2
    vector <int> scenic;

    for(int i = 0; i < map[i].size(); ++i){
        for(int j = 0; j < map[i].size(); ++j){ //for every square
            int value = map[i][j];
            bool visible = false;

            int y = i;
            int x = j;            
            int north = 0; 
            while(true){ //check north
                y--;
                if(y < 0){
                    visible = true;
                    break;
                }
                else if (value <= map[y][j]){
                    north++;
                    break;
                }
                north++;
            }
            y = i;
            x = j;        
            int south = 0;     
            while(true){ //check south
                y++;
                if(y >= map.size()){
                    visible = true;
                    break;
                }
                else if (value <= map[y][j]){
                    south++;
                    break;
                }
                south++;
            }
            y = i;
            x = j;            
            int east = 0; 
            while(true){ //check east
                x++;
                if(x >= map.size()){
                    visible = true;
                    break;
                }
                else if (value <= map[i][x]){
                    east++;
                    break;
                }
                east++;
            }
            y = i;
            x = j;           
            int west = 0;  
            while(true){ //check west
                x--;
                if(x < 0){
                    visible = true;
                    break;
                }
                else if (value <= map[i][x]){
                    west++;
                    break;
                }
                west++;
            }

            int mult = north * west * east * south;
            scenic.push_back(mult);
        }
    }
    //get max
    int winner = 0;
    int win_index = 0;
    for(int i = 0; i < map.size() * map.size(); ++i){
        if(scenic[i] > winner){
            winner = scenic[i];
            win_index = i;
        }
    }
    cout << "scenic: " << scenic[win_index] << endl;

    file.close();
    return 0;
}
