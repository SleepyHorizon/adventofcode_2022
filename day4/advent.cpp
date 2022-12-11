#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

int main(){
    ifstream file; 
    file.open("advent.txt");
    int count = 0;
    int count_b = 0;
    while(!file.eof()){
        string input;
        file >> input;

        string one_a = input.substr(0, input.find("-")); //token = string between 0 char and first delimiter
        input.erase(0, input.find("-") + 1); //delete string
        string one_b = input.substr(0, input.find(",")); //token = string between 0 char and first delimiter
        input.erase(0, input.find(",") + 1); //delete string
        string two_a = input.substr(0, input.find("-")); //token = string between 0 char and first delimiter
        input.erase(0, input.find("-") + 1); //delete string
        string two_b = input;

        int oa = stoi(one_a);
        int ob = stoi(one_b);
        int ta = stoi(two_a);
        int tb = stoi(two_b);

        if(
            oa <= ta //two is in range
            && ob >= tb 
            || oa >= ta // one is in range
            && ob <= tb
        ){
            count++;
        }

        //part 2
        if(
            oa <= ta //check if two is in range at all
            && ta <= ob
            || oa <= tb
            && tb <= ob
            || ta <= oa //check if one is in range at all
            && oa <= tb
            || ta <= ob
            && ob <= tb
        ){
            cout << "trigger" << endl;
            count_b++;
        }

    }
    cout << "count: " << count << endl;
    cout << "count b: " << count_b << endl;
    file.close();
    return 0;
}



