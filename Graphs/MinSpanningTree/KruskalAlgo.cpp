#include<iostream>
#include<vector>
#include<algorithm>
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

class disjointSet{
    vector<int> parent, rank, size;
public:
    disjointSet(int n){
        rank.resize(n+1, 0); //handle 0 & 1 indexing
        size.resize(n+1, 1);
        parent.resize(n+1);
        for(int i=0; i<=n; i++) parent[i] = i;
    }

    int findParent(int node){
        if(node == parent[node])
            return node;       

        return parent[node] = findParent(parent[node]); //path compression
    }

    void unionByRank(int u, int v){
        int ultimateParent_u = findParent(u);
        int ultimateParent_v = findParent(v);

        if(ultimateParent_u == ultimateParent_v) return;

        if(rank[ultimateParent_u] < rank[ultimateParent_v])
            parent[ultimateParent_u] = ultimateParent_v;
        else if(rank[ultimateParent_u] > rank[ultimateParent_v])
            parent[ultimateParent_v] = ultimateParent_u;
        else{
            parent[ultimateParent_v] = ultimateParent_u; //or vice versa
            rank[ultimateParent_u]++;
        }
    }

    void unionBySize(int u, int v){
        int ultimateParent_u = findParent(u);
        int ultimateParent_v = findParent(v);

        if(ultimateParent_u == ultimateParent_v) return;

        if(size[ultimateParent_u] < size[ultimateParent_v]){
            parent[ultimateParent_u] = ultimateParent_v;
            size[ultimateParent_v] += size[ultimateParent_u];
        } else{
            parent[ultimateParent_v] = ultimateParent_u;
            size[ultimateParent_u] += size[ultimateParent_v];
        }
    }
};

int MST(int V, vector<vector<pair<int, int>>> adj){
    vector<pair<int, pair<int, int>>> edges;
    //O(V + E)
    for(int i=0; i<V; i++){
        for(auto it: adj[i]){
            int u = i;
            int v = it.first;
            int w = it.second;

            edges.push_back({w, {u, v}});
        }
    }

    //O(ElogE)
    sort(edges.begin(), edges.end()); //sort by weights
    int mstWt = 0;
    disjointSet ds(V);

    //O(E x 4 x alpha x 2)
    for(auto it: edges){
        int w = it.first;
        int u = it.second.first;
        int v = it.second.second;

        if(ds.findParent(u) != ds.findParent(v)){
            mstWt += w;
            ds.unionBySize(u, v);
        }
    }
    return mstWt;
}

int main(){
    int n = 6;
    Graph g(n);

    g.addEdge(0,1,2);
    g.addEdge(0,3,1);
    g.addEdge(0,4,4);
    g.addEdge(1,2,3);
    g.addEdge(1,3,3);
    g.addEdge(2,3,5);
    g.addEdge(2,5,8);
    g.addEdge(3,4,9);
    g.addEdge(1,5,7);

    vector<vector<pair<int, int>>> adj = g.getAdjList();
    cout<<MST(n, adj)<<endl;
}