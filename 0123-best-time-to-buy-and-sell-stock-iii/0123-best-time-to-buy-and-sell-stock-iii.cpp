class Solution {
public:
    int helper(int i, int buy, vector<int> &prices, int cap, vector<vector<vector<int>>> &dp){
        if(i >= prices.size() || cap == 0) return 0;
        if(dp[i][buy][cap] != -1){
            return dp[i][buy][cap];
        }
        int profit = 0;
        if(buy){
            profit = max(-prices[i] + helper(i+1, 0, prices, cap, dp), helper(i+1, 1, prices, cap, dp));
        }
        else{
            profit= max(prices[i] + helper(i+1, 1, prices, cap-1, dp), helper(i+1, 0, prices, cap, dp));
        }
        return dp[i][buy][cap] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>>dp(n+1, vector<vector<int>>(2, vector<int>(3, -1)));
        return helper(0, 1, prices, 2, dp);
    }
};