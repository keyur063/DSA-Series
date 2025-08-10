#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
using namespace std;

int min(int a, int b){
    if(a < b) return a;
    else return b;
}

void dfs(int node, int parent, int &timer, vector<int> &disc, vector<int> &low, unordered_map<int, bool> &vis, 
        vector<bool> &ap, unordered_map<int, list<int>> &adj){
    vis[node] = true;
    disc[node] = low[node] = timer++;
    int child = 0;

    for(auto nbr: adj[node]){
        if(nbr == parent) continue;

        if(!vis[nbr]){
            dfs(nbr, node, timer, disc, low, vis, ap, adj);
            low[node] = min(low[node], low[nbr]);

            //check if articulation point
            if(low[nbr] >= disc[node] && parent != -1)
                ap[node] = true;

            child++;
        } else{
            //back edge
            low[node] = min(low[node], disc[nbr]);
        }

        if(parent == -1 && child > 1) ap[node] = true; //src node has multiple child
    }
}

int main(){
    vector<pair<int, int>> edges;
    int v = 5;
    int e = 5;
    edges.push_back(make_pair(0, 3));
    edges.push_back(make_pair(0, 1));
    edges.push_back(make_pair(1, 2));
    edges.push_back(make_pair(3, 4));
    edges.push_back(make_pair(0, 4));

    //create adj list
    unordered_map<int, list<int>> adj;
    for(int i=0; i<edges.size(); i++){
        int u = edges[i].first;
        int v = edges[i].second;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int timer = 0;
    vector<int> disc(v, -1);
    vector<int> low(v, -1);
    unordered_map<int, bool> vis;
    vector<bool> ap(v, false);

    //dfs
    for(int i=0; i<v; i++){
        if(!vis[i])
            dfs(i, -1, timer, disc, low, vis, ap, adj);
    }

    //print ap
    cout << "Articulation Points are " << endl;
    for(int i=0; i<v; i++){
        if(ap[i] == 1) cout << i << " ";
    } cout << endl;

    //TC- O(v+e)
    //SC- O(v)
}