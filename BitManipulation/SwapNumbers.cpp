#include <iostream>
using namespace std;

pair<int, int> swapNos(int a, int b){
    a = a^b;
    b = a^b;
    a = a^b;

    return {a, b};
}

int main(){
    int a, b;
    cin>>a>>b;

    pair<int, int> p = swapNos(a, b);
    cout << p.first << " " << p.second << endl;
}