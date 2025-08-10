#include<iostream>
#include<vector>
using namespace std;

//MULTISOURCE SHORTEST PATH
//DETECT NEGATIVE CYCLES

class Graph {
public:
    vector<vector<int>> edges;

    Graph(int n) {
        edges.resize(n, vector<int>(n, -1)); 
    }

    void addEdge(int u, int v, int w){
        edges[u][v] = w;
    }

    vector<vector<int>> getAdjMatrix(){
        return edges;
    }
};

void floydWarshall(vector<vector<int>>& edges){
    int n = edges.size();

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(edges[i][j] == -1)
                edges[i][j] = 1e9;
            
            if(i==j) edges[i][j] = 0;
        }
    }

    for(int k=0; k<n; k++){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                edges[i][j] = min(edges[i][j], edges[i][k] + edges[k][j]);
            }
        }
    }

    bool hasNegativeCycle = false;
    for(int i = 0; i < n; i++) {
        if(edges[i][i] < 0) {
            hasNegativeCycle = true;
            break;
        }
    }

    if(hasNegativeCycle) {
        cout << "Negative Cycle Present" << endl;
    } else {
        cout << "No Negative Cycle Present" << endl;
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(edges[i][j] == 1e9)
                edges[i][j] = -1;
        }
    }
}

//DIJKSTRA CAN BE USED FOR POSITIVE WEIGHTS WITH TC- O(N x ElogV)

void printList(vector<vector<int>>& edges){
    for(auto row: edges){
        for(int val: row){
            cout<<val<<" ";
        }
        cout<<endl;
    }
}

int main(){
    int n = 5;

    Graph g(n);

    g.addEdge(0,1,6);
    g.addEdge(0,2,2);
    g.addEdge(0,3,4);
    g.addEdge(2,1,3);
    g.addEdge(2,4,1);
    g.addEdge(3,1,1);
    g.addEdge(4,1,1);
    
    vector<vector<int>> edges = g.getAdjMatrix();

    printList(edges);
    floydWarshall(edges);
    printList(edges);
}