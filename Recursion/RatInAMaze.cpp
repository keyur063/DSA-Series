#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isSafe(int x, int y, int n, vector<vector<bool>>& visited, vector<vector<int>>& mat){
    if((x>=0 && x<n) && (y>=0 && y<n) && !visited[x][y] && mat[x][y] == 1){
        return true;
    }
    return false;
}
    
void solve(vector<vector<int>>& mat, int n, int x, int y, string path, vector<vector<bool>>& visited, vector<string>& ans){
    if(x==n-1 && y==n-1){
        ans.push_back(path);
        return;
    }
        
    visited[x][y] = true;
        
    //down
    int newx = x+1;
    int newy = y;
    if(isSafe(newx, newy, n, visited, mat)){
        path.push_back('D');
        solve(mat, n, newx, newy, path, visited, ans);
        path.pop_back();
    }
        
    //left
    newx = x;
    newy = y-1;
    if(isSafe(newx, newy, n, visited, mat)){
        path.push_back('L');
        solve(mat, n, newx, newy, path, visited, ans);
        path.pop_back();
    }
        
    //right
    newx = x;
    newy = y+1;
    if(isSafe(newx, newy, n, visited, mat)){
        path.push_back('R');
        solve(mat, n, newx, newy, path, visited, ans);
        path.pop_back();
    }
        
    //down
    newx = x-1;
    newy = y;
    if(isSafe(newx, newy, n, visited, mat)){
        path.push_back('U');
        solve(mat, n, newx, newy, path, visited, ans);
        path.pop_back();
    }
        
    visited[x][y] = false;
}
    
int main(){
    vector<vector<int>> mat = {{1, 0, 0, 0},{1, 1, 0, 1}, {1, 1, 0, 0},{0, 1, 1, 1}};
    int n = mat.size();
        
    vector<string> ans;
        
    if(mat[0][0] == 0 || mat[n-1][n-1] == 0){
        for(int i=0; i<ans.size(); i++){
            cout << ans[i] << " ";
        }
        cout << endl;
    }
        
    int srcx=0, srcy=0; //source coordinates
        
    vector<vector<bool>> visited(n, vector<bool>(n, false));
        
    string path = "";
        
    solve(mat, n, srcx, srcy, path, visited, ans);
    sort(ans.begin(), ans.end());
        
    for(int i=0; i<ans.size(); i++){
        cout << ans[i] << " ";
    }
    cout << endl;
}
