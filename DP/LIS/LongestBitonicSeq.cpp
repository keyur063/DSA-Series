#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

int main(){
    vector<int> nums = {1,11,2,10,4,5,2,1}; //increase then decrease
    int n = nums.size();

    vector<int> dp1(n, 1);
    for(int i=0; i<n; i++){
        for(int prev=0; prev<i; prev++){
            if(nums[i] > nums[prev])  
                dp1[i] = max(dp1[i], 1 + dp1[prev]);
        }
    }

    int maxi = 0;
    vector<int> dp2(n, 1);
    for(int i=n-1; i>=0; i--){
        for(int prev=n-1; prev>i; prev--){
            if(nums[i] > nums[prev])  
                dp2[i] = max(dp2[i], 1 + dp2[prev]);
        }
        maxi = max(maxi, dp2[i] + dp1[i] - 1);
    }
    cout<<maxi<<endl;
}