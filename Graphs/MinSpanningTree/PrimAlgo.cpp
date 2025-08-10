#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Graph{
public:
    vector<vector<pair<int, int>>> adj;

    Graph(int n){
        adj.resize(n);
    }

    void addEdge(int u, int v, int w){
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

    vector<vector<pair<int, int>>> getAdjList(){
        return adj; 
    }
};

int MST(int v, vector<vector<pair<int, int>>>& adj){
    //E
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> vis(v, 0);

    pq.push({0, 0}); //{dist, node}
    int sum = 0;

    //ElogE + ElogE
    //E
    while(!pq.empty()){
        //logE
        int dist = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if(vis[node]) continue;
        vis[node] = 1;
        sum += dist;

        //ElogE
        for(auto it: adj[node]){
            int adjNode = it.first;
            int wt = it.second;

            if(!vis[adjNode])
                pq.push({wt, adjNode});
        }
    }
    return sum;
}

int main(){
    int n = 5;

    Graph g(n);

    g.addEdge(0,1,2);
    g.addEdge(0,3,6);
    g.addEdge(1,2,3);
    g.addEdge(1,3,8);
    g.addEdge(1,4,5);
    g.addEdge(2,4,7);

    vector<vector<pair<int, int>>> adj = g.getAdjList();
    cout<<MST(n, adj)<<endl;
}
