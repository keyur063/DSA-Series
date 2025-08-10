#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> powerSet(vector<int>& arr, vector<vector<int>>& ans){
    int n = arr.size();
    int subsets = 1 << n;

    for(int i=0; i<subsets; i++){
        vector<int> subset;
        for(int j=0; j<n; j++){
            if((i & (1<<j)) != 0)
                subset.push_back(arr[j]);
        }
        ans.push_back(subset);
    }
    return ans;
}

int main(){
    vector<int> arr = {1, 2, 3};
    vector<vector<int>> ans;
    ans = powerSet(arr, ans);

    for (const auto& row : ans) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
}