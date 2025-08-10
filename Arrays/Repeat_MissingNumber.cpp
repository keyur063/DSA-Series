#include <iostream> 
#include <vector> 
#include <algorithm>
using namespace std;

void solve(vector<int> A, int n, vector<int>& ans){
    sort(A.begin(), A.end());
    
    for(int i=1; i<n; i++){
        if(A[i] == A[i-1]){
            ans.push_back(A[i]);
        }
    }
    
    int arrSum = 0, numSum=0;
    for(int i=0; i<n; i++){
        arrSum += A[i];
        numSum += i+1;
    }
    arrSum -= ans[0];
    
    ans.push_back(numSum-arrSum);
}

int main(){
    vector<int> arr = {3, 1, 2, 5, 3};
    vector<int> ans;

    solve(arr, 5, ans);
    for(int i=0; i<ans.size();i++){
        cout << ans[i] << " ";
    }
    cout << endl;
}