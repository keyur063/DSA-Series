#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

vector<int> arr;
vector<int> segTree;

void buildSegTree(int idx, int low, int high){
    if(low == high){
        segTree[idx] = arr[low];
        return;
    }
    int mid = (low+high)/2;

    buildSegTree(2*idx+1, low, mid);
    buildSegTree(2*idx+2, mid+1, high);
    segTree[idx] = max(segTree[2*idx+1], segTree[2*idx+2]);
}
//O(N)

int query(int idx, int low, int high, int l, int r){
    if(low<=l && high>=r) return segTree[idx];
    if(high<l || low>r) return INT_MIN;

    int mid = (low+high)/2;
    int left = query(2*idx+1, low, mid, l, r);
    int right = query(2*idx+2, mid+1, high, l, r);
    return max(left, right);
}
//O(logN)

int main(){
    arr = {5,2,4,1,3,7,6,4,5};
    int n = arr.size();
    segTree.resize(4*n, 0);

    buildSegTree(0, 0, n-1);

    int q;
    cout<<"Enter queries: ";
    cin>>q;
    while(q--){
        int l, r;
        cout<<"Enter left and right: ";
        cin>>l>>r;
        cout<<query(0, 0, n-1, l, r);
    }
}