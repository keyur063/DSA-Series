#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

//NUMBER OF ISLANDS II

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

bool isValid(int r, int c, int n, int m){
    return (r>=0 && r<n && c>=0 && c<m);
}

vector<int> numIslands(int n, int m, vector<vector<int>>& mat){
    disjointSet ds(n*m);
    vector<vector<int>> vis(n, vector<int> (m, 0));
    int cnt = 0;
    vector<int> ans;

    int dr[] = {-1,0,1,0};
    int dc[] = {0,-1,0,1};

    for(auto it: mat){
        int r = it[0];
        int c = it[1];

        if(vis[r][c] == 1){
            ans.push_back(cnt);
            continue;
        }

        vis[r][c] = 1;
        int nodeNum = r*m + c;
        
        for(int k=0; k<4; k++){
            int row = r + dr[k];
            int col = c + dc[k];

            if(isValid(row, col, n, m) && vis[row][col] == 1){
                int adjNodeNum = row*m + col;
                
                //connected component
                if(ds.findParent(nodeNum) != ds.findParent(adjNodeNum)){
                    cnt--;
                    ds.unionBySize(nodeNum, adjNodeNum);
                }
            }
        }
        cnt++;
        ans.push_back(cnt);
    }
    return ans;
}

int main(){
    int n = 4, m = 5;
    vector<vector<int>> positions = {{1,2}, {0,1}, {1,1}, {3,4}};

    vector<int> ans = numIslands(n, m, positions);
    for(int val: ans){
        cout<<val<<" ";
    }
}