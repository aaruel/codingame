#include <iostream>
#include <stdlib.h>
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
    int W; // width of the building.
    int H; // height of the building.
    cin >> W >> H; cin.ignore();
    int N; // maximum number of turns before game over.
    cin >> N; cin.ignore();
    int X0;
    int Y0;
    cin >> X0 >> Y0; cin.ignore();
    
    vector<int> x;
    vector<int> y;
    vector<int> tempx;
    vector<int> tempy;
    
    for(int i=0; i<W; i++) x.push_back(1);
    for(int i=0; i<H; i++) y.push_back(1);
    
    // game loop
    while (1) {
        string BOMB_DIR; // the direction of the bombs from batman's current location (U, UR, R, DR, D, DL, L or UL)
        cin >> BOMB_DIR; cin.ignore();
        
        if(BOMB_DIR == "D"){
            for(int i=W; i>X0; i--){
                x[i] = 0;
            }
            for(int i=0; i<X0; i++){
                x[i] = 0;
            }
            for(int i=0; i<=Y0; i++){
                y[i] = 0;
            }
        }
        
        if(BOMB_DIR == "DR"){
            for(int i=0; i<=X0; i++){
                x[i] = 0;
            }
            for(int i=0; i<=Y0; i++){
                y[i] = 0;
            }
        }
        
        if(BOMB_DIR == "U"){
            for(int i=W; i>X0; i--){
                x[i] = 0;
            }
            for(int i=0; i<X0; i++){
                x[i] = 0;
            }
            for(int i=H; i>=Y0; i--){
                y[i] = 0;
            }
        }
        
        if(BOMB_DIR == "UR"){
            for(int i=0; i<=X0; i++){
                x[i] = 0;
            }
            for(int i=H; i>=Y0; i--){
                y[i] = 0;
            }
        }
        
        if(BOMB_DIR == "R"){
            for(int i=0; i<=X0; i++){
                x[i] = 0;
            }
            for(int i=H; i>Y0; i--){
                y[i] = 0;
            }
            for(int i=0; i<Y0; i++){
                y[i] = 0;
            }
        }
        
        if(BOMB_DIR == "UL"){
            for(int i=W; i>=X0; i--){
                x[i] = 0;
            }
            for(int i=H; i>=Y0; i--){
                y[i] = 0;
            }
        }
        
        if(BOMB_DIR == "L"){
            for(int i=W; i>=X0; i--){
                x[i] = 0;
            }
            for(int i=H; i>Y0; i--){
                y[i] = 0;
            }
            for(int i=0; i<Y0; i++){
                y[i] = 0;
            }
        }
        
        if(BOMB_DIR == "DL"){
            for(int i=W; i>=X0; i--){
                x[i] = 0;
            }
            for(int i=0; i<=Y0; i++){
                y[i] = 0;
            }
        }
        
        for(int i=0; i<W; i++){
            for(int j=0; j<H; j++){
                if(x[i] == 1 and y[j] == 1){
                    tempx.push_back(i);
                    tempy.push_back(j);
                }
            }
        }
        
        //int randomx = rand() % tempx.size();
        //int randomy = rand() % tempy.size();
        
        int randomx = tempx.size()/2;
        int randomy = tempy.size()/2;
        
        // Write an action using cout. DON'T FORGET THE "<< endl"
        // To debug: cerr << "Debug messages..." << endl;
        
        int redundantx = tempx[randomx];
        int redundanty = tempy[randomy];
        
        X0 = redundantx;
        Y0 = redundanty;
        
        cout << redundantx << " " << redundanty << endl; // the location of the next window Batman should jump to.
        tempx.erase(tempx.begin(), tempx.end());
        tempy.erase(tempy.begin(), tempy.end());
    }
}
