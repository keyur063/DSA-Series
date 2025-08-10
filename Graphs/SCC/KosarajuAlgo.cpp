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

void dfs(int node, vector<int>& vis, vector<vector<int>>& adj, stack<int>& s){
    vis[node] = 1;

    for(auto it: adj[node]){
        if(!vis[it])
            dfs(it, vis, adj, s);
    }

    s.push(node);
}

void dfs3(int node, vector<int>& vis, vector<vector<int>>& adjT){
    vis[node] = 1;

    for(auto it: adjT[node]){
        if(!vis[it])
            dfs3(it, vis, adjT);
    }
}

int kosaraju(int v, vector<vector<int>>& adj){
    vector<int> vis(v, 0);
    stack<int> s;

    //sort by finishing time
    //O(V + E)
    for(int i=0; i<v; i++){
        if(!vis[i])
            dfs(i, vis, adj, s);
    }

    //reverse edges
    //O(V + E)
    vector<vector<int>> adjT(v);
    for(int i=0; i<v; i++){
        vis[i] = 0; //reuse vis
        for(auto it: adj[i]){
            adjT[it].push_back(i);
        }
    }

    //dfs on adj transpose
    //O(V + E)
    int scc = 0;
    while(!s.empty()){
        int node = s.top();
        s.pop();

        if(!vis[node]){
            scc++;
            dfs3(node, vis, adjT);
        }
    }
    return scc;
}

int main(){
    int n = 8;

    Graph g(n);

    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,0);
    g.addEdge(2,3);
    g.addEdge(3,4);
    g.addEdge(4,7);
    g.addEdge(4,5);
    g.addEdge(5,6);
    g.addEdge(6,4);
    g.addEdge(6,7);

    vector<vector<int>> adj = g.getAdjList();
    cout<<kosaraju(n, adj)<<endl;
}