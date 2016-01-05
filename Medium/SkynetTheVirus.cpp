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
    int N; // the total number of nodes in the level, including the gateways
    int L; // the number of links
    int E; // the number of exit gateways
    cin >> N >> L >> E; cin.ignore();
    
    vector<string> gateway;
    for (int i = 0; i < L; i++) {
        int N1; // N1 and N2 defines a link between these nodes
        int N2;
        cin >> N1 >> N2; cin.ignore();
        string N3 = to_string(N1);
        string N4 = to_string(N2);
        string loader = N3+" "+N4;
        gateway.push_back(loader);
    }
    
    vector<int> exitnode;
    
    for (int i = 0; i < E; i++) {
        int EI; // the index of a gateway node
        cin >> EI; cin.ignore();
        exitnode.push_back(EI);
    }
    
    vector<string> exitlink;
    for(int j = 0; j < exitnode.size(); j++){
        for(int i = 0; i < L; i++){
            if(gateway[i].substr(2,1) == to_string(exitnode.at(j))){
                exitlink.push_back(gateway[i]);
            }
        }
    }
    
    // game loop
    while (1) {
        a:
        int SI; // The index of the node on which the Skynet agent is positioned this turn
        cin >> SI; cin.ignore();
        int flag = 0;
        string node1 = to_string(SI);
        string node2;
        string loader;
        for(int i = 0; i < exitnode.size(); i++){
            node2 = to_string(exitnode[i]);
            loader = node1 + " " + node2;
            string loaderREV = node2 + " " + node1;
            for(int h = 0; h < L; h++){
            if(loader == gateway[h] or loaderREV == gateway[h]){
                cout << gateway[h] << endl;
                goto a;
            }
        }}
                for(int h = 0; h < L; h++){
                    if(loader != gateway[h]){
                        for(int k = 0; k < N; k++){
                            string node3 = to_string(k);
                            string randlink = node1 + " " + node3;
                                for(int l = 0; l < L; l++){
                                    if(randlink == gateway[l]){
                                    cout << randlink << endl;
                                    goto a;
                                }
                            }
                        }
                    }
                }
            
        }
        
        // Write an action using cout. DON'T FORGET THE "<< endl"
        // To debug: cerr << "Debug messages..." << endl;
        
        //cout << SI << " " << SI+1 << endl; // Example: 0 1 are the indices of the nodes you wish to sever the link between
        
}
