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

int main(){
    int n = 6;

    Graph g(n);
    g.addEdge(2,3);
    g.addEdge(3,1);
    g.addEdge(4,0);
    g.addEdge(4,1);
    g.addEdge(5,0);
    g.addEdge(5,2);

    vector<vector<int>> adj = g.getAdjList();
    
    vector<int> indegree(n, 0);
    for(int i=0; i<n; i++){
        for(auto it: adj[i]){
            indegree[it]++;
        }
    }

    queue<int> q;
    for(int i=0; i<n; i++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }

    vector<int> ans;
    //O(N+E)
    while(!q.empty()){
        int node = q.front();
        q.pop();
        ans.push_back(node);

        for(auto it: adj[node]){
            indegree[it]--;
            if(indegree[it] == 0) q.push(it);
        }
    }

    for(int val: ans){
        cout<<val<<" ";
    }
}