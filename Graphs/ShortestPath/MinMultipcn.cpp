#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int minMul(vector<int>& arr, int s, int e){
    queue<pair<int, int>> q;
    vector<int> dist(1e4, 1e9);

    int mod = 1e4;
    e %= mod;

    q.push({s, 0});
    dist[s] = 0;

    //O(1e4 * n)
    while(!q.empty()){
        int node = q.front().first;
        int step = q.front().second;
        q.pop();

        for(auto it: arr){
            int num = (it * node) % mod;
            
            if(num == e) return step + 1;

            if(step + 1 < dist[num]){
                dist[num] = step + 1;
                q.push({num, step+1});
            }
        }
    }
    return -1;
}

int main(){
    vector<int> arr = {3, 4, 65};
    int start = 7, end = 66175;

    cout<<minMul(arr, start, end)<<endl;
}