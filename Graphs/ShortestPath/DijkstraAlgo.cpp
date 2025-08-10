#include<iostream>
#include<vector>
#include<queue>
#include<set>
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

vector<int> pqAlgo(int v, vector<vector<pair<int, int>>>& adj, int src){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist(v, 1e9);

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
            }
        }
    }
    return dist;
}
//TC- O(ElogV)

vector<int> setAlgo(int v, vector<vector<pair<int, int>>>& adj, int src){
    set<pair<int, int>> s;
    vector<int> dist(v, 1e9);

    dist[src] = 0;
    s.insert({0, src});

    while(!s.empty()){
        auto it = *(s.begin());
        int dis = it.first;
        int node = it.second;
        s.erase(s.begin());

        for(auto it: adj[node]){
            int adjNode = it.first;
            int wt = it.second;

            if(dis + wt < dist[adjNode]){
                if(dist[adjNode] != 1e9)
                    s.erase({dist[adjNode], adjNode});

                dist[adjNode] = dis + wt;
                s.insert({dist[adjNode], adjNode});
            }
        }
    }
    return dist;
}
//TC- O(logV)
//SET can erase unwanted dist and update new ones so better TC than PQ
//QUEUE cannot sort dist so worse TC than PQ
//QUEUE good for unit weights

int main(){
    int n = 6;

    Graph g(n);

    g.addEdge(0,1,4);
    g.addEdge(0,2,4);
    g.addEdge(1,2,2);
    g.addEdge(2,3,3);
    g.addEdge(2,4,1);
    g.addEdge(2,5,6);
    g.addEdge(3,5,2);
    g.addEdge(4,5,3);

    vector<vector<pair<int, int>>> adj = g.getAdjList();
    vector<int> ans1 = pqAlgo(n, adj, 0);
    vector<int> ans2 = setAlgo(n, adj, 0);

    for(int val: ans1){
        cout<<val<<" ";
    }
    cout<<endl;

    for(int val: ans2){
        cout<<val<<" ";
    }
}