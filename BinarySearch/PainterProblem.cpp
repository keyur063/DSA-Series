#include <iostream>
#include <vector>
using namespace std;

bool isValid(vector<int> &arr, int n, int m, int maxTime){
    int time=0, painters=1;
    for(int i=0; i<n; i++){
        if(arr[i] > maxTime) return false;

        if(time + arr[i] <= maxTime)
            time += arr[i];
        else{
            painters++;
            time = arr[i];
        }
    }
    return painters > m ? false: true;
}

//n-no. of boards, m-no.of painters
int allocatePainter(vector<int> &arr, int n, int m){
    if(m > n) return -1;

    int sum=0;
    for(int i=0; i<n; i++){
        sum += arr[i];
    }

    int st=0, end=sum; //Range of possible ans
    while(st<=end){
        int mid = st + (end-st)/2;

        if(isValid(arr, n, m, mid)) //left
            end = mid-1;
        else //right
            st = mid+1;
    }
    return st;
}

int main(){
    vector<int> arr = {40, 30, 10, 20};

    cout<<allocatePainter(arr, 4, 2)<<endl;
    return 0;
}