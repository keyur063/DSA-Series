#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isValid(vector<int> &arr, int N, int C, int minAllowedDist){  //O(N)
    int cows=1, lastStallPos=arr[0];

    for(int i=1; i<N; i++){
        if(arr[i] - lastStallPos >= minAllowedDist){
            cows++;
            lastStallPos = arr[i];
        }

        if(cows >= C) return true;
    }
    return false;
}

//n- no. of stalls, c- no. of cows
int minDistance(vector<int> &arr, int N, int C){
    sort(arr.begin(), arr.end()); //O(NlogN)

    if(C > N) return -1; 
    int low = 1;
    int high = arr[N-1] - arr[0];

    while(low <= high){ //O(log(Range)*N)
        int mid = low + (high - low)/2;

        if(isValid(arr, N, C, mid)){ // dist can be increased
            low = mid + 1;
        }
        else{ // dist must reduce
            high = mid - 1;
        }
    }
    return high;
}

int main(){
    vector<int> arr = {1, 2, 8, 4, 9};

    cout<<minDistance(arr, 5, 3)<<endl;
    return 0;
}