#include<iostream>
#include<vector>
#include<cmath>
#include<limits.h>
using namespace std;

//Consider all positive elements

int main(){
        vector<int> nums = {3,7,2,1,5,6};
        int n = nums.size();
        int sum = 0;
        for(int i=0; i<n; i++) sum += nums[i];

        int target = sum;
        vector<bool> prev(target+1, 0);
        prev[0] = true;
        if(nums[0] <= target) prev[nums[0]] = true;

        for(int i=1; i<n; i++){   
            vector<bool> curr(target+1, 0);
            curr[0] = true;    
            for(int j=1; j<=target; j++){
                bool incl = false;
                if(j >= nums[i]) incl = prev[j-nums[i]];
                bool excl = prev[j];
                curr[j] = incl || excl;
            }
            prev = curr;
        }
       
        int mini = 1e9;
        for(int s1=0; s1<=sum/2; s1++){
            if(prev[s1]) mini = min(mini, abs((sum-s1) - s1));
        }
        cout<<mini<<endl;    
}