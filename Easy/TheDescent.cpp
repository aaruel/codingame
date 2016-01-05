#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
int main()
{
    vector<int>mountain;
    // game loop
    while (1) {
        int spaceX;
        int spaceY;
        cin >> spaceX >> spaceY; cin.ignore();
        for (int i = 0; i < 8; i++) {
            int mountainH; // represents the height of one mountain, from 9 to 0. Mountain heights are provided from left to right.
            cin >> mountainH; cin.ignore();
            mountain.push_back(mountainH);
        }
        string gun = "";
        // Write an action using cout. DON'T FORGET THE "<< endl"
        // To debug: cerr << "Debug messages..." << endl;
        int mountX;
        int H;
        int C=0;
        for(int i=0; i < 8; i++){
            H = mountain.at(i);
            if(H>C){
                C=H;
                mountX = i;
            }
        }
        for(int i=0; i<8; i++){
            if(spaceY == C+i && spaceX == mountX){
                gun = "FIRE";
                goto brk;
            } else {
                gun = "HOLD";
            }
        }
        brk:
        cout << gun << endl; // either:  FIRE (ship is firing its phase cannons) or HOLD (ship is not firing).
        cerr << spaceX << "," << mountX << "," << gun << endl;
        mountain.clear();
    }
}
