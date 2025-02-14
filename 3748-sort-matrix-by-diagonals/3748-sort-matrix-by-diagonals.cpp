class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> ans(n, vector<int>(n, 0));
        
        // main diagonal and lower triangle
        for (int ii = 0; ii < n; ii++) {
            int i = ii, j = 0;
            vector<int> main;
            while (i < n && j < n) {
                main.push_back(grid[i][j]);
                i++;
                j++;
            }
            sort(main.begin(), main.end(), greater<int>());
            i = ii, j = 0;
            int k = 0;
            while (i < n && j < n) {
                ans[i][j] = main[k];
                i++;
                j++;
                k++;
            }
        }

        // upper triangle
        for (int ii = 1; ii < n; ii++) {
            int i = 0, j = ii;
            vector<int> main;
            while (i < n && j < n) {
                main.push_back(grid[i][j]);
                i++;
                j++;
            }
            sort(main.begin(), main.end());
            i = 0, j = ii;
            int k = 0;
            while (i < n && j < n) {
                ans[i][j] = main[k];
                i++;
                j++;
                k++;
            }
        }

        return ans;
    }
};