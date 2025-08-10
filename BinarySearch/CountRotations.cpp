#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

int main(){
    vector<int> nums = {4,4,5,5,6,7,0,1,2,3,3};
    int n = nums.size();
    int low=0, high=n-1, ans=INT_MAX, index=-1;

    while(low <= high){
        int mid = low + (high-low)/2;

        if(nums[low] == nums[mid] && nums[mid] == nums[high]){
            low++;
            high--;
            continue;
        }

        //whole array is already sorted
        if(nums[low] <= nums[high]){
            if(nums[low] < ans){
                index = low;
                ans = nums[low];
            }
            break;
        }

        if(nums[low] <= nums[mid]){ //left sorted
            if(nums[low] < ans){
                index = low;
                ans = nums[low];
            }
            low = mid+1;
        } else{ //right sorted
            if(nums[mid] < ans){
                index = mid;
                ans = nums[mid];
            }
            high = mid-1;
        }
    }
    cout << index << endl;
}