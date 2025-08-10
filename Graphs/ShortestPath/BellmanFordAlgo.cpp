#include<iostream>
#include<vector>
using namespace std;

//FOR NEGATIVE WEIGHT CYCLES (PATH WEIGHT < 0)
//ONLY FOR DIRECTED GRAPH

class Graph{
public:
    vector<vector<int>> edges;

    void addEdge(int u, int v, int w){
        edges.push_back({u, v, w});
    }

    vector<vector<int>> getEdges(){
        return edges; 
    }
};

vector<int> bellmanFord(int V, vector<vector<int>> edges, int src){
    vector<int> dist(V, 1e9);
    dist[src] = 0;

    //n-1 relaxations
    //O(V x E)
    for(int i=0; i<V-1; i++){
        for(auto it: edges){
            int u = it[0];
            int v = it[1];
            int w = it[2];

            if(dist[u] != 1e9 && dist[u] + w < dist[v]){
                dist[v] = dist[u] + w;
            }
        }
    }

    //nth relaxation to check negative cycle
    for(auto it: edges){
        int u = it[0];
        int v = it[1];
        int w = it[2];

        if(dist[u] != 1e9 && dist[u] + w < dist[v]){
            return {-1};
        }
    }

    return dist;
}

int main(){
    int n = 6;

    Graph g;

    g.addEdge(0,1,5);
    g.addEdge(1,2,-2);
    g.addEdge(1,5,-3);
    g.addEdge(2,4,3);
    g.addEdge(3,2,6);
    g.addEdge(3,4,-2);
    g.addEdge(5,3,1);

    vector<vector<int>> edges = g.getEdges();

    vector<int> ans = bellmanFord(n, edges, 0);
    for(int val: ans){
        cout<<val<<" ";
    }
}