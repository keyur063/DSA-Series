#include<iostream>
#include<vector>
#include<queue>
#include<set>
using namespace std;

//Print Shortest Path in WUG

class Graph{
public:
    vector<vector<pair<int, int>>> adj;

    Graph(int n){
        adj.resize(n+1);
    }

    void addEdge(int u, int v, int w){
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

    vector<vector<pair<int, int>>> getAdjList(){
        return adj; 
    }
};

vector<int> dijkstra(int v, vector<vector<pair<int, int>>>& adj, int src, int dest){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist(v+1, 1e9), parent(v+1);

    for(int i=1; i<=v; i++) parent[i] = i;

    dist[src] = 0;
    pq.push({0, src});

    while(!pq.empty()){
        int dis = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        for(auto it: adj[node]){
            int adjNode = it.first;
            int wt = it.second;

            if(dis + wt < dist[adjNode]){
                dist[adjNode] = dis + wt;
                pq.push({dist[adjNode], adjNode});
                parent[adjNode] = node;
            }
        }
    }

    if(dist[dest] == 1e9) return {-1};

    vector<int> path;
    int node = dest;
    while(parent[node] != node){
        path.push_back(node);
        node = parent[node];
    }
    path.push_back(src);
    return path;
}

int main(){
    int n = 5;

    Graph g(n);

    g.addEdge(1,2,2);
    g.addEdge(1,4,1);
    g.addEdge(2,3,4);
    g.addEdge(2,5,5);
    g.addEdge(3,4,3);
    g.addEdge(3,5,1);

    vector<vector<pair<int, int>>> adj = g.getAdjList();
    vector<int> ans = dijkstra(n, adj, 1, 5);
    
    for(int i=ans.size()-1; i>=0; i--){
        cout<<ans[i]<<" ";
    }
}