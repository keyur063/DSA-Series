#include<iostream>
#include<vector>
#include<cmath>
#include<limits.h>
using namespace std;

int solveRec(int day, vector<vector<int>>& tasks, int last){
    if(day==0){
        int maxi = 0;
        for(int i=0; i<3; i++){
            if(i != last) maxi = max(maxi, tasks[0][i]); //return max of remaining 2 values
        }
        return maxi;
    }

    int maxi = 0;
    for(int i=0; i<3; i++){
        if(i != last){
            int points = tasks[day][i] + solveRec(day-1, tasks, i);
            maxi = max(maxi, points);
        }
    }
    return maxi;
}

int solveMem(int day, vector<vector<int>>& tasks, int last, vector<vector<int>>& dp){
    if(day==0){
        int maxi = 0;
        for(int i=0; i<3; i++){
            if(i != last) maxi = max(maxi, tasks[0][i]); //return max of remaining 2 values
        }
        return maxi;
    }

    if(dp[day][last] != -1)
        return dp[day][last];

    int maxi = 0;
    for(int i=0; i<3; i++){
        if(i != last){
            int points = tasks[day][i] + solveMem(day-1, tasks, i, dp);
            maxi = max(maxi, points);
        }
    }
    return dp[day][last] = maxi;
}
//TC- O(Nx4)x3 mem x 3
//SC- O(N) + O(Nx4)

int solveTab(int day, vector<vector<int>>& tasks, int last){
    int n = tasks.size();
    vector<vector<int>> dp(n, vector<int> (4,0));
    dp[0][0] = max(tasks[0][1], tasks[0][2]);
    dp[0][1] = max(tasks[0][0], tasks[0][2]);
    dp[0][2] = max(tasks[0][1], tasks[0][0]);
    dp[0][3] = max(tasks[0][0], max(tasks[0][1], tasks[0][2]));

    for(day=1; day<n; day++){
        for(int last=0; last<4; last++){
            dp[day][last] = 0;
            for(int task=0; task<3; task++){
                if(last != task){
                    int points = tasks[day][task] + dp[day-1][task]; 
                    dp[day][last] = max(dp[day][last], points);
                }
            }
        }
    }
    return dp[n-1][3];
}
//TC- O(Nx4x3)
//SC- O(Nx4)

int solveSO(int day, vector<vector<int>>& tasks, int last){
    int n = tasks.size();
    vector<int> prev(4, 0);

    prev[0] = max(tasks[0][1], tasks[0][2]);
    prev[1] = max(tasks[0][0], tasks[0][2]);
    prev[2] = max(tasks[0][1], tasks[0][0]);
    prev[3] = max(tasks[0][0], max(tasks[0][1], tasks[0][2]));

    for(day=1; day<n; day++){
        vector<int> curr(4, 0);
        for(int last=0; last<4; last++){
            curr[last] = 0;
            for(int task=0; task<3; task++){
                if(last != task){
                    int points = tasks[day][task] + prev[task]; 
                    curr[last] = max(curr[last], points);
                }
            }
        }
        prev = curr;
    }
    return prev[3];
}
//TC- O(Nx4x3)
//SC- O(4)

int main(){
    vector<vector<int>> tasks = {{2,1,3}, {3,4,6}, {10,1,6}, {8,3,7}};
    int n = tasks.size();
    vector<vector<int>> dp(n ,vector<int> (4,-1));
    cout<<solveSO(n-1, tasks, 3)<<endl;
}