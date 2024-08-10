class Solution {
public:
    vector<int>x = {0,0,-1,1};
    vector<int>y = {1,-1,0,0};
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        list<pair<int,int>>ls;
        vector<vector<bool>>vis(n, vector<bool>(m ,false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 2){
                    ls.push_back({i, j});
                    vis[i][j] = true;
                }
            }
        }

        while(!ls.empty()){
            int len = ls.size();
            for(int k=0;k<len;k++){
                int i = ls.front().first;
                int j = ls.front().second;
                ls.pop_front();
                for(int ii=0;ii<4;ii++){
                    int xx = i + x[ii];
                    int yy = j + y[ii];
                    if(xx >= 0 && xx < n && yy >= 0 && yy < m && !vis[xx][yy] && grid[xx][yy] == 1){
                        vis[xx][yy] = true;
                        ls.push_back({xx, yy});
                    }
                }                
            }
            ans++;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 1 && !vis[i][j]){
                    return -1;
                }
            }
        }
        if(ans == 0) return ans;
        return ans-1;
    }
};