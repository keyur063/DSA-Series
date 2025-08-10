#include<iostream>
#include<vector>
#include<queue>
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

int main(){
    int n = 9;

    Graph g(9);

    g.addEdge(0,1);
    g.addEdge(0,3);
    g.addEdge(1,2);
    g.addEdge(1,3);
    g.addEdge(2,6);
    g.addEdge(3,4);
    g.addEdge(4,5);
    g.addEdge(5,6);
    g.addEdge(6,7);
    g.addEdge(6,8);
    g.addEdge(7,8);

    vector<vector<int>> adj = g.getAdjList();
    int src = 5;

    vector<int> dist(n, 1e9);
    dist[src] = 0;

    queue<int> q;
    q.push(src);

    while(!q.empty()){
        int node = q.front();
        q.pop();

        for(auto it: adj[node]){
            if(dist[node] + 1 < dist[it]){
                dist[it] = dist[node] + 1;
                q.push(it);
            }
        }
    }

    vector<int> ans(n, -1);
    for(int i=0; i<n; i++){
        if(dist[i] != 1e9)
            ans[i] = dist[i];      
    }
    
    for(int val: ans){
        cout<<val<<" ";
    }
}