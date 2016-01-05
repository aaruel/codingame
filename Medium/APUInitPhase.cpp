#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector<vector<int>> array2d_t;

/**
 * Don't let the machines win. You are humanity's last hope...
 **/
int main()
{
    int width; // the number of cells on the X axis
    cin >> width; cin.ignore();
    int height; // the number of cells on the Y axis
    cin >> height; cin.ignore();
    
    
    
    vector<vector<bool>> grid(width, vector<bool>(height, false));
    for (int i = 0; i < height; i++) {
        string line; // width characters, each either 0 or .
        getline(cin, line);
        
        for(int j=0; j < line.size(); j++) {
            if(line[j] == '0'){
                grid[j][i] = true;
            }
        }
    }
    
    unsigned int x,y;
    for (unsigned int i=0; i<height; i++){
        for(unsigned int j=0; j<width; j++) {
            if(grid[j][i]){
            cout << j << " " << i << " ";
            bool found = false;
            for(unsigned int w = j+1; w < width; w++){
                if(grid[w][i]){
                    cout << w << " " << i << " ";
                    found = true;
                    break;
                } 
            }
            if(!found){
                cout << "-1 -1 ";
            }
            found = false;
            
            for(unsigned int h = i+1; h < height; h++){
                if(grid[j][h]){
                    cout << j << " " << h << endl;
                    found = true;
                    break;
                }
            }
            if(!found){
                cout << "-1 -1 " << endl;  
            }
        }
        }
        
    }
    
    // Write an action using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;

    //cout << "0 0 1 0 0 1" << endl; // Three coordinates: a node, its right neighbor, its bottom neighbor
    //cout << "1 0 -1 -1 -1 -1" << endl;
    //cout << "0 1 -1 -1 -1 -1" << endl;
}
