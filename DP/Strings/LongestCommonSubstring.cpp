#include<iostream>
#include<vector>
#include<cmath>
#include<limits.h>
using namespace std;

int main(){
    string a = "abcjklp";
    string b = "acjkp";
    int n = a.length();
    int m = b.length();

    vector<int> prev(m+1, 0), curr(m+1, 0);
    int ans = 0;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(a[i-1] == b[j-1]){
                curr[j] = 1 + prev[j-1];
                ans = max(ans, curr[j]);
            }
            else curr[j] = 0; //max(dp[i-1][j], dp[i][j-1]) change here
        }
        prev = curr;
    }
    cout<<ans<<endl;
}