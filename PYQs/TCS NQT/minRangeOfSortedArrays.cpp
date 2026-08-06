#include<bits/stdc++.h>
using namespace std;

/*
    Given K sorted arrays, find smallest range [L, R] such that 
    atleast one element from each array lies in the range.
*/

struct Node {
    int val, row, col;

    Node(int v, int r, int c) {
        this -> val = v;
        this -> row = r;
        this -> col = c;
    }
};

struct Compare {
    bool operator() (Node a, Node b) {
        return a.val > b.val;
    }
};

pair<int, int> smallestRange(vector<vector<int>>& nums) {
    priority_queue<Node, vector<Node>, Compare> pq; // minHeap
    int currMax = INT_MIN;
    
    // insert 1st element of each row
    for(int i=0; i<nums.size(); i++) {
        pq.push(Node(nums[i][0], i, 0));
        currMax = max(currMax, nums[i][0]);
    }

    int start = 0, end = INT_MAX;

    while(true) {
        Node currMin = pq.top();
        pq.pop();

        int currRange = currMax - currMin.val;
        int bestRange = end - start;

        if(currRange < bestRange) {
            start = currMin.val;
            end = currMax;
        }

        int row = currMin.row;
        int col = currMin.col;

        // out of bounds
        if(col + 1 >= nums[row].size()) break;

        int nextVal = nums[row][col+1];
        pq.push(Node(nextVal, row, col + 1));
        
        currMax = max(currMax, nextVal);
    }

    return {start, end};
}


int main() {
    vector<vector<int>> nums = {
    {4, 10, 15, 24, 26},
    {0, 9, 12, 20},
    {5, 18, 22, 30}};

    pair<int, int> p = smallestRange(nums);
    cout << p.first << " " << p.second;

    return 0;
}