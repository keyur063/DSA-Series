#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

/*
    Given an array, replace each element with its rank in a sorted list starting from 1.
*/

int main() {
    vector<int> arr = {23, 6, 4, 6, 1};
    vector<int> temp = arr;

    sort(temp.begin(), temp.end());
    temp.erase(unique(temp.begin(), temp.end()), temp.end());

    unordered_map<int, int> rank;
    for(int i=0; i<temp.size(); i++)
        rank[temp[i]] = i + 1;
    
    for(int i=0; i<arr.size(); i++) 
        arr[i] = rank[arr[i]];

    for(int num: arr)
        cout << num << " ";

    return 0;
}