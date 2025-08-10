#include<iostream>
#include<vector>
#include<set>
using namespace std;

//Number of Distinct Islands

void dfs(int i, int j, vector<vector<int>>& vis, vector<pair<int, int>>& vec, vector<vector<int>>& grid, int row0, int col0){
    int n = grid.size(), m = grid[0].size();
    vis[i][j] = 1;
    vec.push_back({i-row0, j-col0});

    int di[] = {-1,0,1,0};
    int dj[] = {0,-1,0,1};

    for(int k=0; k<4; k++){
        int r = i + di[k];
        int c = j + dj[k];

        if(r>=0 && r<n && c>=0 && c<m && !vis[r][c] && grid[r][c] == 1){
            dfs(r, c, vis, vec, grid, row0, col0);
        }
    }
}

int main(){
    vector<vector<int>> grid = {{1,1,1,1}, {1,0,0,0}, {0,0,1,1}, {1,0,1,0}};
    int n = grid.size(), m = grid[0].size();

    vector<vector<int>> vis(n , vector<int> (m, 0));
    set<vector<pair<int, int>>> s;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(!vis[i][j] && grid[i][j] == 1){
                vector<pair<int, int>> vec;
                dfs(i, j, vis, vec, grid, i, j);
                s.insert(vec);
            }
        }
    }
    cout<<s.size()<<endl;
}
//TC- O(n x m x log(n x m)) + O(n x m x 4) (2 for loops + set + dfs)
//SC- O(n x m) x 3 (set + vis + dfs)