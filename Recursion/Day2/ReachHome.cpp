#include <iostream>
using namespace std;

void reachHome(int src, int dest){
    cout << "Source " << src << " Destination " << dest << endl;
    
    if(src == dest){
        cout << "Reached..." << endl;
        return;
    }

    // Processing
    src++;

    reachHome(src, dest);
}

int main(){
    int src, dest;
    cin >> src >> dest;

    reachHome(src, dest);
    cout << endl;
}