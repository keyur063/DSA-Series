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
    }

    vector<vector<int>> getAdjList(){
        return adj; 
    }
};

void dfs(int node, vector<int>& vis, stack<int>& s, vector<vector<int>>& adj){
    vis[node] = 1;

    for(auto adjNode: adj[node]){
        if(!vis[adjNode]){
            dfs(adjNode, vis, s, adj);
        }
    }
    s.push(node);
}

int main(){
    int n = 6;

    Graph g(n);
    g.addEdge(2,3);
    g.addEdge(3,1);
    g.addEdge(4,0);
    g.addEdge(4,1);
    g.addEdge(5,0);
    g.addEdge(5,2);

    vector<vector<int>> adj = g.getAdjList();
    vector<int> vis(n, 0);
    stack<int> s;

    for(int i=0; i<n; i++){
        if(!vis[i]){
            dfs(i, vis, s, adj);
        }
    }

    vector<int> ans;
    while(!s.empty()){
        ans.push_back(s.top());
        s.pop();
    }

    for(int val: ans){
        cout<<val<<" ";
    }
}