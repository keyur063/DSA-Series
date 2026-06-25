#include<iostream>
using namespace std;

// int findPow(int n, int m){
//     long long ans = 1;
//     while(m > 0){
//         if(m&1){
//             ans *= n;
//             m--;
//         }
//         else{
//             n *= n;
//             m /= 2;
//         }
//     }
//     return ans;
// }

int func(int mid, int m, int n){
    long long ans = 1;
    for(int i=1; i<=n; i++){
        ans *= mid;
        if(ans > m) return 2;
    }

    if(ans == m) return 1;
    return 0;
}

int NthRoot(int m, int n){ //nth root of m
    int low=1, high=m;
    while(low <= high){
        int mid = low + (high-low)/2;

        // if(findPow(mid, n) == m)
        //     return mid;
        // else if(findPow(mid, n) < m)
        //     low = mid+1;
        // else    
        //     high = mid-1;

        int midN = func(mid, m, n);
        if(midN == 1)
            return mid;
        else if(midN == 0)
            low = mid+1;
        else
            high = mid-1;
    }
    return -1;
}

int main(){
    cout << NthRoot(27, 3) << endl;
    cout << NthRoot(10,2) << endl;
}