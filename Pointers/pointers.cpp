#include <iostream>
using namespace std;

int main(){
    int a = 10;
    int* ptr = &a;
    int** parPtr = &ptr;

    cout<<&a<<' '<<ptr<<endl;
    cout<<&ptr<<' '<<parPtr<<endl;

    cout<<*ptr<<' '<<a<<endl;
    cout<<**parPtr<<' '<<*ptr<<endl;
    return 0;
}