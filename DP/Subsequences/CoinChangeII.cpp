#include<iostream>
#include<vector>
#include<cmath>
#include<limits.h>
using namespace std;

int mem(int i, int k, vector<int>& coins, vector<vector<int>> dp){
        if(i==0) return (k % coins[0] == 0); //1 if possible else 0

        if(dp[i][k] != -1)
            return dp[i][k];

        int excl = mem(i-1, k, coins, dp);
        int incl = 0;
        if(k >= coins[i]) incl += mem(i, k-coins[i], coins, dp);

        return dp[i][k] = incl + excl;
    }
    /*TC >> O(2^n) -> O(n x k)
    SC >> O(n) -> O(n) + O(n x k) */

    int tab(int n, int amount, vector<int>& coins){
        vector<vector<int>> dp(n, vector<int> (amount+1, 0));

        for(int k=0; k<=amount; k++)
            dp[0][k] = (k % coins[0] == 0);

        for(int i=1; i<n; i++){
            for(int k=0; k<=amount; k++){
                int excl = dp[i-1][k];

                int incl = 0;
                if(k >= coins[i]) incl += dp[i][k-coins[i]];

                dp[i][k] = incl + excl;
            }
        }
        return dp[n-1][amount];
    }
    // O(n x k), O(n x k)

    int space(int n, int amount, vector<int>& coins){
        vector<long long> prev(amount+1, 0);
        
        for(int k=0; k<=amount; k++)
           if(k % coins[0] == 0) prev[k] = 1;

        for(int i=1; i<n; i++){
            vector<long long> curr(amount+1, 0);
            for(int k=0; k<=amount; k++){
                long long excl = prev[k];

                long long incl = 0;
                if(k >= coins[i]) incl = curr[k-coins[i]];

                curr[k] = (incl + excl) ;
            }
            prev = curr;
        }
        return prev[amount];
    }
    // O(n x k), O(k)

int main(){
    vector<int> coins = {3,5,7,8,9,10,11};
    int amount = 1000;
    cout<<space(coins.size(), amount, coins)<<endl;
}