class Solution {
public:
    vector<int> x = {1,-1,0,0};
    vector<int> y = {0,0,1,-1};

    void dfs(int i,int j, int k,vector<vector<char>>& board, string word, bool &flag, vector<vector<bool>>&vis){
        vis[i][j] = true;
        if(k == word.length()){
            flag = true;
            return;
        }

        for(int ii =0;ii<4;ii++){
            int xx = i + x[ii];
            int yy = j + y[ii];

            if(xx >=0 && xx<board.size() && yy>=0 && yy<board[0].size() && board[xx][yy] == word[k] && !vis[xx][yy]){
                dfs(xx,yy,k+1,board, word, flag, vis);
            }
        }
        vis[i][j] = false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j] == word[0]){
                    vector<vector<bool>>vis(n, vector<bool>(m, false));
                    bool flag = false;
                    dfs(i, j, 1, board, word, flag, vis);
                    if(flag) return flag;
                }
            }
        }
        return false;
    }
};