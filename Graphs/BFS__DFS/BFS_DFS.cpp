#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
#include<list>
using namespace std;

class Graph{
public:
    unordered_map<int, list<int>> adj;

    void addEdge(int u, int v){
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
};

vector<int> bfs(int v, unordered_map<int, list<int>> adj){
    int vis[v+1] = {0}; //1-indexed
    vis[1] = 1;

    queue<int> q;
    q.push(1);
    vector<int> bfs;

    while(!q.empty()){ //O(N)
        int node = q.front();
        q.pop();
        bfs.push_back(node);

        for(auto it: adj[node]){ //O(degrees)
            if(!vis[it]){
                vis[it] = 1;
                q.push(it);
            }
        }
    }
    return bfs;
}
//TC- O(N) + O(2E) 2E=degrees

void dfsHelper(int node, unordered_map<int, list<int>>& adj, vector<int>& vis, vector<int>& dfs){
    vis[node] = 1;
    dfs.push_back(node);

    for(auto it: adj[node]){
        if(!vis[it]) 
            dfsHelper(it, adj, vis, dfs);
    }
}

vector<int> dfs(int v, unordered_map<int, list<int>> adj){
    vector<int> vis(v+1, 0); //1-indexed
    vector<int> dfs;
    int start = 1; //starting node

    dfsHelper(start, adj, vis, dfs);
    return dfs;
}
//TC- O(2E) + O(N) sum of degrees + rec
//SC- O(N) + O(N) ~ O(N) vis + recursion

int main(){
    Graph g;
    g.addEdge(1,2);
    g.addEdge(1,6);
    g.addEdge(2,3);
    g.addEdge(2,4);
    g.addEdge(6,7);
    g.addEdge(6,9);
    g.addEdge(4,5);
    g.addEdge(5,8);
    g.addEdge(7,8);

    vector<int> ans = dfs(9, g.adj);
    
    for(int val: ans)
        cout<<val<<" ";
    cout<<endl;
}
