#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

/**
 * Save the Planet.
 * Use less Fossil Fuel.
 **/
int main()
{
    int N; // the number of points used to draw the surface of Mars.
    cin >> N; cin.ignore();
    vector<int>LX_VEC;
    vector<int>LY_VEC;
    int LX;
    int LY;
    for (int i = 0; i < N; i++) {
        int LAND_X; // X coordinate of a surface point. (0 to 6999)
        int LAND_Y; // Y coordinate of a surface point. By linking all the points together in a sequential fashion, you form the surface of Mars.
        cin >> LAND_X >> LAND_Y; cin.ignore();
        LX=LAND_X;
        LY=LAND_Y;
        LX_VEC.push_back(LX);
        LY_VEC.push_back(LY);
    }
    int y_prev=0;
    int x_prev=0;
    int y_flatA=0;
    int x_flatA=0;
    int y_flatB=0;
    int x_flatB=0;
    for(int i=0; i < N; i++){
        if(y_prev == LY_VEC.at(i)){
            x_flatA = x_prev;
            y_flatA = y_prev;
            x_flatB = LX_VEC.at(i);
            y_flatB = LY_VEC.at(i);
        }
        y_prev = LY_VEC.at(i);
        x_prev = LX_VEC.at(i);
    }
    
    // game loop
    while (1) {
        int X;
        int Y;
        int HS; // the horizontal speed (in m/s), can be negative.
        int VS; // the vertical speed (in m/s), can be negative.
        int F; // the quantity of remaining fuel in liters.
        int R; // the rotation angle in degrees (-90 to 90).
        int P; // the thrust power (0 to 4).
        cin >> X >> Y >> HS >> VS >> F >> R >> P; cin.ignore();

        // Write an action using cout. DON'T FORGET THE "<< endl"
        // To debug: cerr << "Debug messages..." << endl;
        
        if(x_flatA > X){
            //Travelling to the first boundary
            if(HS < 60){
                if(y_flatA+300 > Y){
                    R = 0;
                    P = 4;
                }else{
                    R = -45 * (1-(X/x_flatA));
                }
            } else {
                R = 45;
            }
            P = 4;
        } 
        else if(x_flatB < X){
            //Travelling to the second boundary
            if(HS > -50){
                if(y_flatA+300 > Y){
                    R = 0;
                    P = 4;
                } else {
                    R = 45 * (1-(x_flatB/X));
                }
            } else {
                R = -45;
            }
            P = 4;
        }
        else { //Landing process
        if(HS > 4 || HS < -5){
            R = 45 * (HS/(abs(HS)));
            P = 4;
        } 
        else {
            R = 0;
        }
        if(R == 0 && VS > -39){
            P = 3;
        } else { P = 4; }
        }
        cout << R << " " << P << endl; // R P. R is the desired rotation angle. P is the desired thrust power.
    }
}
