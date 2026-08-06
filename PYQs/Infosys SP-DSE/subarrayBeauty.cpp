#include<bits/stdc++.h>
using namespace std;

/*
    Given integer array nums of N integers, find beauty of every subarray of size K.
    Beauty is defined as:
        xth smallest negative integer in subarray
        0 if negative integers < x
    Return array of size n-k+1 representing beauty of each subarray.

    -50 <= nums[i] <= 50
*/

vector<int> beauty(vector<int>& nums, int k, int x) {
    int n = nums.size();
    vector<int> ans;

    int freq[101] = {0};

    // first window
    for(int i=0; i<k; i++)
        freq[nums[i] + 50]++;

    // find beauty of current window
    auto findBeauty =[&]() {
        int cnt = 0;

        // must have x negatives else 0
        for(int val=-50; val<=-1; val++) {
            cnt += freq[val + 50];

            if(cnt >= x) return val;
        }

        return 0;
    };

    ans.push_back(findBeauty());

    // sliding window
    for(int i=k; i<n; i++) {
        freq[nums[i-k] + 50]--;
        freq[nums[i] + 50]++;
        ans.push_back(findBeauty());
    }

    return ans;
}

int main() {
    int N, K, X;
    cin >> N >> K >> X;

    vector<int> nums(N);
    for(int i=0; i<N; i++)
        cin >> nums[i];

    for(int x: beauty(nums, K, X))
        cout << x << " ";

    return 0;
}