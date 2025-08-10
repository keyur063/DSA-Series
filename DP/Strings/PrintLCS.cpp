#include<iostream>
#include<vector>
#include<cmath>
#include<limits.h>
using namespace std;

int main(){
    string a = "abcde";
    string b = "bdgek";
    int n = a.length();
    int m = b.length();

    vector<vector<int>> dp(n+1 , vector<int> (m+1, 0));
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(a[i-1] == b[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }

    int len = dp[n][m]; //using dp table
    string ans = "";
    for(int i=0; i<len; i++) ans += '#';

    int idx = len-1;
    int i=n, j=m;
    while(i>0 && j>0){
        if(a[i-1] == b[j-1]){
            ans[idx] = a[i-1];
            idx--;
            i--; j--;
        } else if(dp[i-1][j] > dp[i][j-1]) i--;
        else j--;
    }
    cout<<ans<<endl;
}
//n+m