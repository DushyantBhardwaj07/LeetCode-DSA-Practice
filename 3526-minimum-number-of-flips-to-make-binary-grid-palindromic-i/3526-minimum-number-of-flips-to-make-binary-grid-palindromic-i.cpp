class Solution {
public:
    int minFlips(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int row = 0, col = 0;
        // checking rows        
        for(int i=0;i<n;i++){
            int l = 0, r = m-1;
            while(l <= r){
                if(grid[i][l] != grid[i][r]){
                    row++;
                }
                l++;
                r--;
            }            
        }

        // checking column        
        for(int j=0;j<m;j++){
            int l = 0, r = n-1;           
            while(l <= r){
                if(grid[l][j] != grid[r][j]){
                    col++;
                }
                l++;
                r--;
            }
        }

        return min(row, col);
    }
};