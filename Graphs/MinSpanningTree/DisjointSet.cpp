#include<iostream>
#include<vector>
using namespace std;

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
//O(4a) ~ O(1)

void isSameComponent(disjointSet& ds, int u, int v){
    if(ds.findParent(u) == ds.findParent(v))
        cout<<u<<" & "<<v<<" have same component"<<endl;
    else
        cout<<u<<" & "<<v<<" do not have same component"<<endl;
}

int main(){
    int n = 7;

    disjointSet ds(n);

    ds.unionBySize(1,2);
    ds.unionBySize(2,3);
    ds.unionBySize(4,5);
    ds.unionBySize(6,7);
    ds.unionBySize(5,6);

    isSameComponent(ds, 3, 7);
    ds.unionBySize(3,7);
    isSameComponent(ds, 3, 7);
}


/*
class disjointSet{
public:
    vector<int> parent, size;
    disjointSet(int n){
        size.resize(n+1, 1);
        parent.resize(n+1);
        for(int i=0; i<=n; i++) parent[i] = i;
    }

    int findParent(int node){
        if(node == parent[node])
            return node;       

        return parent[node] = findParent(parent[node]);
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
*/