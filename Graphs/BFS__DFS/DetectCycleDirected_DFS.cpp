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
    }

    vector<vector<int>> getAdjList(){
        return adj; 
    }
};

bool dfs(int node, vector<vector<int>>& adj, vector<int>& vis, vector<int>& pathVis){
    vis[node] = 1;
    pathVis[node] = 1;

    for(auto adjNode: adj[node]){
        if(!vis[adjNode]){
            if(dfs(adjNode, adj, vis, pathVis)) return true;
        } else if(pathVis[adjNode]){
            return true;
        }
    }

    pathVis[node] = 0;
    return false;
}

int main(){
    int n = 10;

    Graph g(10);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,4);
    g.addEdge(4,5);
    g.addEdge(5,6);
    g.addEdge(3,7);
    g.addEdge(7,5);
    g.addEdge(8,2);
    g.addEdge(8,9);
    g.addEdge(9,10);
    g.addEdge(10,8);

    vector<vector<int>> adj = g.getAdjList();
    vector<int> vis(n+1, 0);
    vector<int> pathVis(n+1, 0);

    for(int i=0; i<n; i++){
        if(!vis[i]){
            if(dfs(i, adj, vis, pathVis)){
                cout<<"True"<<endl;
                return 0;
            }
        }
    }
    cout<<"False"<<endl;
}
//TC- O(N + E)
//SC- O(N) x 2