class Solution {
public:
    int helper(int i, int n, vector<int> &nums, vector<int> &dp){
        if(i >= n){
            return 0;
        }
        if(dp[i] != -1){
            return dp[i];
        }
        int p = 0, np = 0;
        p = nums[i] + helper(i+2, n, nums, dp);
        np = helper(i+1, n, nums, dp);
        return dp[i] = max(p, np);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n, -1);
        return helper(0, n, nums, dp);
    }
};