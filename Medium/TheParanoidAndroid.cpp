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
    int nbFloors; // number of floors
    int width; // width of the area
    int nbRounds; // maximum number of rounds
    int exitFloor; // floor on which the exit is found
    int exitPos; // position of the exit on its floor
    int nbTotalClones; // number of generated clones
    int nbAdditionalElevators; // ignore (always zero)
    int nbElevators; // number of elevators
    cin >> nbFloors >> width >> nbRounds >> exitFloor >> exitPos >> nbTotalClones >> nbAdditionalElevators >> nbElevators; cin.ignore();
    vector<int> ElvPos;
    vector<int> ElvFlo;
    
    for (int i = 0; i < nbElevators; i++) {
        int elevatorFloor; // floor on which this elevator is found
        int elevatorPos; // position of the elevator on its floor
        cin >> elevatorFloor >> elevatorPos; cin.ignore();
        ElvPos.push_back(elevatorPos);
        ElvFlo.push_back(elevatorFloor);
    }
    int clock=0;
    int count=0;
    cerr << nbFloors << endl;
    // game loop
    while (1) {
        f:
        int cloneFloor; // floor of the leading clone
        int clonePos; // position of the leading clone on its floor
        string direction; // direction of the leading clone: LEFT or RIGHT
        int vecFloor,vecFloorCur,nbBlocks;
        cin >> cloneFloor >> clonePos >> direction; cin.ignore();
        if(nbFloors == 1){
            if(direction == "RIGHT"){
                cout << "BLOCK" << endl;
            } else {
                cout << "WAIT" << endl;
            }
            goto f;
        }
        if(nbFloors > 1){
        for(int i = 0; i < nbFloors; i++){
            if(cloneFloor - 1 == ElvFlo[i]){
                vecFloor = i;
                break;
            }
        }
        for(int i = 0; i < nbFloors; i++){
            if(cloneFloor == ElvFlo[i]){
                vecFloorCur = i;
                break;
            }
        }
        }
        clock++;
        if(cloneFloor == nbFloors - 1){
            count++;
        }
        // Write an action using cout. DON'T FORGET THE "<< endl"
        // To debug: cerr << "Debug messages..." << endl;
        if(clonePos == (width-1) or clonePos == 0){
            cout << "BLOCK" << endl; // action: WAIT or BLOCK
        } else if(cloneFloor != 0 and ElvPos[vecFloor] == clonePos-1 and direction == "RIGHT" and clonePos > ElvPos[vecFloorCur] and count < 3 and nbFloors != 2){
            nbBlocks++;
            cout << "BLOCK" << endl;
        } else if(cloneFloor != 0 and ElvPos[vecFloor] == clonePos+1 and direction == "LEFT" and clonePos < ElvPos[vecFloorCur] and count < 3 and nbFloors != 2){
            nbBlocks++;
            cout << "BLOCK" << endl;
        }
        else {
            cout << "WAIT" << endl;
        }
    }
}
