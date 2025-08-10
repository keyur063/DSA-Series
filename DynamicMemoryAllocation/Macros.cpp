#include <iostream>
using namespace std;
#define PI 3.17

int main(){
    int r = 5;
    double area = PI * r * r;
    // PI = PI + 1; not possible to change value
    cout << "The area of the circle is " << area << endl;

    return 0;
}