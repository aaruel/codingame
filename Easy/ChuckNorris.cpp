//I was lazy with this one to be honest

#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
int main()
{
    int i=0;
    int store=2;
    string MESSAGE;
    getline(cin, MESSAGE);

    // Write an action using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;

    char load0[100];
    strcpy(load0, MESSAGE.c_str());
    int binary[7];
    int load1=0;
    while(load0[i] != NULL){
        load1 = (int) load0[i];
        for(int i=0; i<7; i++){
            binary[6-i] = load1%2;
            load1 /= 2;
        }
        for(int i=0; i<7; i++){
            if(binary[i] == 0){
                if(store == 0){
                    store = 2;
                    cout << "0";
                }
                else if(binary[i-1] == 0 and i != 0){
                    cout << "0";
                } else {
                    if(i != 0){
                        cout << " ";
                    }
                    cout << "00 0";
                }
            }
            if(binary[i] == 1){
                if(store == 1){
                    store = 2;
                    cout << "0";
                }
                else if(binary[i-1] == 1 and i != 0){
                    cout << "0";
                } else {
                    if(i != 0){
                        cout << " ";
                    }
                    cout << "0 0";
                }
            }
        }
        i++;
        store = binary[6];
    }
    
    cout << endl;
}
