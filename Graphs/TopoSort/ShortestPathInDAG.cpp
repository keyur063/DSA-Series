#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class Graph{
public:
    vector<vector<pair<int, int>>> adj;

    Graph(int n){
        adj.resize(n);
    }

    void addEdge(int u, int v, int w){
        adj[u].push_back({v,w});
    }

    vector<vector<pair<int, int>>> getAdjList(){
        return adj; 
    }
};

void topoSort(int node, vector<int>& vis, stack<int>& s, vector<vector<pair<int, int>>>& adj){
    vis[node] = 1;

    for(auto it: adj[node]){
        int v = it.first;
        if(!vis[v]){
            topoSort(v, vis, s, adj);
        }
    }

    s.push(node);
}

int main(){
    int n = 7;

    Graph g(n);

    g.addEdge(0,1,2);
    g.addEdge(1,3,1);
    g.addEdge(2,3,3);
    g.addEdge(4,0,3);
    g.addEdge(4,2,1);
    g.addEdge(5,4,1);
    g.addEdge(6,4,2);
    g.addEdge(6,5,3);

    vector<vector<pair<int, int>>> adj = g.getAdjList();
    int src = 6; 
    vector<int> vis(n, 0);
    stack<int> s;

    //O(V+E)
    for(int i=0; i<n; i++){
        if(!vis[i]){
            topoSort(i, vis, s, adj);
        }
    }

    vector<int> dist(n, 1e9);
    dist[src] = 0;

    //O(V+E)
    while(!s.empty()){
        int node = s.top();
        s.pop();
        //runs for num of pairs ie. edges so O(E)
        for(auto it: adj[node]){
            int v = it.first;
            int w = it.second;

            //update dist
            if(dist[node] + w < dist[v]){
                dist[v] = dist[node] + w;
            }
        }
    }

    for(int val: dist){
        cout<<val<<" ";
    }
}