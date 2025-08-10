#include<iostream>
#include<vector>
#include<queue>
using namespace std;

//ALIEN DICTIONARY-> GFG

bool topoSort(int n, vector<vector<int>>& adj){
    vector<int> indegree(n, 0);
    for(int i=0; i<n; i++){
        for(auto it: adj[i]){
            indegree[it]++;
        }
    }

    queue<int> q;
    for(int i=0; i<n; i++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }

    //vector<int> ans;
    int cnt = 0;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        //ans.push_back(node);
        cnt++;

        for(auto it: adj[node]){
            indegree[it]--;
            if(indegree[it] == 0) q.push(it);
        }
    }
    return (cnt == n);
}

int main(){
    vector<string> words = {"baa", "abcd", "abca", "cab", "cad"}; //sorted as per alien order
    int k = 4; //first k letters of english alphabet
    int n = words.size();

    vector<vector<int>> adj(k);
    for(int i=0; i<n-1; i++){
        string s1 = words[i];
        string s2 = words[i+1];
        int len = min(s1.size(), s2.size());

        bool vis = false;
        for(int j=0; j<len; j++){
            if(s1[j] != s2[j]){
                adj[s1[j] - 'a'].push_back(s2[j] - 'a');
                vis = true;
                break;
            }
        }

        //1st edge case
        if(!vis && s1.size() > s2.size()){
            cout<<"False"<<endl;
            return 0;
        }
    }

    // vector<int> topo = topoSort(k, adj);
    // string ans = "";

    // for(auto it: topo){
    //     ans += char(it+'a');
    // }
    // cout<<ans<<endl;

    //2nd edge case
    if(topoSort(k, adj)){
        cout<<"True"<<endl;
        return 0;
    }
    cout<<"False"<<endl;

    /* 2 edge cases
    1-> abcd len(s[i]) > len(s[i+1])
        abc
    2-> aba  a<b<a cyclic dependency
        bab
        abb */
}