#include<iostream>
#include<vector>
using namespace std;

bool mem(int i, int n, vector<int>& arr, int target, vector<vector<int>>& dp){
    if(target==0) return true;
    if(i==0) return (arr[0] == target);

    if(dp[i][target] != -1)
        return dp[i][target];

    bool incl = false;
    if(target >= arr[i]) incl = mem(i-1, n, arr, target-arr[i], dp);
    bool excl = mem(i-1, n, arr, target, dp);

    return dp[i][target] = (incl || excl);
}
//TC- O(2^n) -> O(n x target)
//SC- O(n) -> O(n x target) + O(n)

bool tab(int n, vector<int>& arr, int target){
    vector<vector<bool>> dp(n, vector<bool>(target+1, 0));

    for(int i=0; i<n-1; i++) dp[i][0] = 1;
    if(arr[0] <= target) dp[0][arr[0]] = 1;

    for(int i=1; i<n; i++){
        for(int j=1; j<=target; j++){
            bool incl = false;
            if(j >= arr[i]) incl = dp[i-1][j-arr[i]];
            bool excl = dp[i-1][j];
            dp[i][j] = incl || excl;
        }
    }
    return dp[n-1][target];
}
//TC- O(n x target)
//SC- O(n x target)

bool space(int n, vector<int>& arr, int target){
    vector<bool> prev(target+1, 0);
    vector<bool> curr(target+1, 0);
    prev[0] = curr[0] = 1;
    if(arr[0] <= target) prev[arr[0]] = 1;

    for(int i=1; i<n; i++){       
        for(int j=1; j<=target; j++){
            bool incl = false;
            if(j >= arr[i]) incl = prev[j-arr[i]];
            bool excl = prev[j];
            curr[j] = incl || excl;
        }
        prev = curr;
    }
    return prev[target];
}
//TC- O(n x target)
//SC- O(target)

int main(){
    vector<int> arr = {1,2,3,4};
    int n = arr.size();
    int target = 7;

    vector<vector<int>> dp(n, vector<int>(target+1, -1));
    cout<<space(n, arr, target)<<endl;
}