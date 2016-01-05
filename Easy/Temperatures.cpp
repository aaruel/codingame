#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
int main()
{
    int n; // the number of temperatures to analyse
    cin >> n; cin.ignore();\
    //string temps; // the n temperatures expressed as integers ranging from -273 to 5526
    //getline(cin, temps);

    // Write an action using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;
    
    int load1;
    vector<int> load0;
    for(int i=0; i<n; i++){
        cin >> load1;
        load0.push_back(load1);
    }
    int H=0;
    int C=5527;
    int low=0;
    int equal=0;
    for(int i=0; i<n; i++){
        H = abs(load0.at(i));
        if(H<C){
            C = abs(load0.at(i));
            low = i;
        } else if (H==C){
            if((load0.at(i) * load0.at(low)) > 0){
                equal = H * -1;
            } else {
                equal = H;
            }
        }
    }
    
    if(n==0){
        cout << n << endl;
    } else if(equal != 0){
        cout << equal << endl;
    }
    else{
        cout << load0.at(low) << endl;
    }
    cerr << load0.at(0);
}
