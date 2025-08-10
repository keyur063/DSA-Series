#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class Graph{
public:
    vector<vector<int>> adj;

    Graph(int n){
        adj.resize(n+1);
    }

    void addEdge(int u, int v){
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<vector<int>> getAdjList(){
        return adj; 
    }
};

void dfs(int node, int parent, int& timer, vector<int>& vis, vector<int>& time, vector<int>& low, 
            vector<vector<int>>& adj, vector<int>& ap){
    vis[node] = 1;
    time[node] = low[node] = timer++;
    int child = 0;

    for(auto it: adj[node]){
        if(it == parent) continue;
        if(!vis[it]){
            dfs(it, node, timer, vis, time, low, adj, ap);
            low[node] = min(low[node], low[it]);

            //for non starting node
            if((low[it] >= time[node]) && (parent != -1)){
                ap[node] = 1;
            }
            child++;
        } else
            low[node] = min(low[node], time[it]);
    }

    //for starting node only if multiple children
    if((child > 1) && (parent == -1)) ap[node] = 1;
}

vector<int> articulationPoints(int n, vector<vector<int>> adj){
    vector<int> vis(n, 0);
    vector<int> time(n); //time of insertion
    vector<int> low(n); //lowest reach time without parent & visited
    vector<int> ap(n, 0);
    int timer = 0;

    for(int i=0;i<n; i++){
        if(!vis[i])
            dfs(i, -1, timer, vis, time, low, adj, ap);
    }

    vector<int> ans;
    for(int i=0; i<n; i++){
        if(ap[i] == 1)
            ans.push_back(i);
    }

    return (!ans.empty()) ? ans: vector<int>{-1}; 
}

int main(){
    int n = 7;

    Graph g(n);

    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(0,3);
    g.addEdge(2,3);
    g.addEdge(2,4);
    g.addEdge(2,5);
    g.addEdge(4,6);
    g.addEdge(5,6);

    vector<vector<int>> adj = g.getAdjList();
    
    vector<int> ans = articulationPoints(n, adj);
    for(int val: ans){
        cout<<val<<" ";
    }
}