#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
#include<list>
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

bool detectCycleBFS(int src, vector<int>& vis, vector<vector<int>>& adj){
    vis[src] = 1;
    queue<pair<int, int>> q;
    q.push({src, -1});

    while(!q.empty()){
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();

        for(auto adjNode: adj[node]){
            if(!vis[adjNode]){
                q.push({adjNode, node});
                vis[adjNode] = 1;
            } 
            else if(parent != adjNode)
                return true;
            
        }
    }
    return false;
}

bool detectCycleDFS(int node, int parent, vector<int>& vis, vector<vector<int>>& adj){
    vis[node] = 1;

    for(auto adjNode: adj[node]){
        if(!vis[adjNode])
            return detectCycleDFS(adjNode, node, vis, adj);
        else if(parent != adjNode) return true;
    }
    return false;
}

int main(){
    int n = 7;

    Graph g(n);
    g.addEdge(1,2);
    g.addEdge(1,3);
    g.addEdge(2,5);
    g.addEdge(3,4);
    g.addEdge(3,6);
    g.addEdge(5,7);
    g.addEdge(6,7);

    vector<vector<int>> adj = g.getAdjList();
    vector<int> vis(n+1, 0); //1-indexed

    for(int i=1; i<=n; i++){
        if(!vis[i]){
            if(detectCycleDFS(1, -1, vis, adj)){ //detectCycleBFS(i, vis, adj)
                cout<<"true"<<endl;
                return 0;
            }
        }
    }
    cout<<"false"<<endl;
}
/* BFS-
TC- O(N + 2E) (q + bfs) + O(N) for
SC- O(N) x 2 (vis + q)

DFS-
TC- O(N + 2E) dfs + O(N) for
SC- O(N) x 2 (ASS + vis) */