#include <iostream>
using namespace std;

// Using Loop
// bool isPower(int num){
//     if(num<=1)
//         return false;
// 
//     while(num>1){
//         if(num%2 != 0){
//             return false;
//         }
//         else{
//             num/=2;
//         }
//     }
//     return true;
// }

// Using Bit Manipulation
// bool isPower(int num){
//     if(num<=1)
//         return false;
    
//     while(num>1){
//         if(num & 1)
//             return false;
            
//         num >>= 1;
//     }
//     return true;
// }

bool isPower(int n){
    if((n & n-1) == 0)
        return true;
    else
        return false;
}

int main(){
    cout<< isPower(32)<< endl;
    cout<< isPower(324);
}