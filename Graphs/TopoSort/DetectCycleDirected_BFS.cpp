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
    
    vector<int> indegree(n+1, 0);
    for(int i=1; i<=n; i++){
        for(auto it: adj[i]){
            indegree[it]++;
        }
    }

    queue<int> q;
    for(int i=1; i<=n; i++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }

    int cnt = 0;
    //O(N+E)
    while(!q.empty()){
        int node = q.front();
        q.pop();
        cnt++;

        for(auto it: adj[node]){
            indegree[it]--;
            if(indegree[it] == 0) q.push(it);
        }
    }

    if(cnt == n){
        cout<<"False"<<endl;
        return 0;
    }
    cout<<"True"<<endl;
}