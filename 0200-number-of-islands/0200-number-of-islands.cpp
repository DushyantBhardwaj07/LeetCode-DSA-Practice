class Solution {
public:
    vector<int>x = {-1,1,0,0};
    vector<int>y = {0,0,1,-1};
    void dfs(int i, int j, vector<vector<char>>& grid, vector<vector<bool>> &vis, int n, int m){
        vis[i][j] = true;
        for(int k=0;k<4;k++){
            int xx = i + x[k];
            int yy = j + y[k];

            if(xx >= 0 && xx<n && yy>=0 && yy<m && !vis[xx][yy] && grid[xx][yy] == '1'){
                dfs(xx,yy,grid, vis, n, m);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        vector<vector<bool>>vis(n, vector<bool>(m, false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == '1' && !vis[i][j]){
                    ans++;
                    dfs(i, j, grid, vis, n, m);                    
                }
            }
        }
        return ans;
    }
};