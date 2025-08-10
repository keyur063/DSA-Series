#include<iostream>
#include<vector>
using namespace std;

class Graph{
public:
    int vertices;
    vector<vector<int>> adjMatrix;
    Graph(int v) {
        vertices = v;
        adjMatrix = vector<vector<int>> (v, vector<int> (v, 0));
    }

    void addEdge(int u, int v, bool direction){
        adjMatrix[u][v] = 1;

        if(direction) adjMatrix[v][u] = 1;
    }

    void removeEdge(int u, int v, bool direction){
        adjMatrix[u][v] = 0;

        if(direction) adjMatrix[v][u] = 0;
    }

    void displayGraph(){ //TC- O(v**2)
        for(const auto& row: adjMatrix){ //for(vector<int> row: adjMatrix) creates a copy
            for(int val: row){
                cout << val << " ";
            } cout << endl;
        }
        cout << endl;
    }
};

int main(){
    Graph g(4);

    g.addEdge(0, 1, 1);
    g.addEdge(1, 2, 0);
    g.addEdge(2, 3, 0);
    g.addEdge(3, 0, 1);
    g.addEdge(1, 3, 1);
    g.displayGraph();

    g.removeEdge(1, 3, 1);
    g.displayGraph();
}