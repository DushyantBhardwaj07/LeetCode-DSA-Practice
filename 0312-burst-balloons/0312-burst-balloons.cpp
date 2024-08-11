class Solution {
public:
    int helper(int i, int j, vector<int> &v, vector<vector<int>> &dp){
        if(i >= j){
            return 0;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        int ans = INT_MIN;

        for(int k=i;k<j;k++){
            int a = 1, b = 1, c = 1;
            if(i-1 >= 0) a = v[i-1];
            if(k < v.size()) b = v[k];
            if(j < v.size()) c = v[j];

            int temp =  (a * b * c) + helper(i, k, v, dp) + helper(k+1, j, v, dp);
            ans = max(ans,temp);
        }
        return dp[i][j] = ans;
    }

    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>dp(n + 1, vector<int>(n + 1, -1));
        return helper(0, n, nums, dp);
    }
};