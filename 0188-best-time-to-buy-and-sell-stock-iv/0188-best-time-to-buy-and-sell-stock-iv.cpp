class Solution {
public:
    int helper(int i, int k, int buy, vector<int> &prices, vector<vector<vector<int>>> &dp){
        if(k == 0 || i>=prices.size()) return 0;

        if(dp[i][k][buy] != -1){
            return dp[i][k][buy];
        }

        int profit = 0;

        if(buy){
            profit = max(-prices[i] + helper(i+1, k, 0, prices, dp), helper(i+1, k, 1, prices, dp));
        }
        else{
            profit = max(prices[i] + helper(i+1, k-1, 1, prices, dp), helper(i+1, k, 0, prices, dp));
        }

        return dp[i][k][buy] = profit;        
    }
    int maxProfit(int k, vector<int>& prices) {
        int n =  prices.size();
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(k+1, vector<int>(2, -1)));
        return helper(0, k, 1, prices, dp);
    }
};