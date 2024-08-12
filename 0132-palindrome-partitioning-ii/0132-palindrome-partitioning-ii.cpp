class Solution {
public:
    bool isPalindrome(string &s, int i, int j){
        while(i <= j){
            if(s[i] != s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }

    int helper(int i, int j, string &s, vector<vector<int>> &dp){
        if(isPalindrome(s, i, j)){
            return 0;        
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int ans = INT_MAX;
        for(int k=i;k<j;k++){
            if(isPalindrome(s, i, k)){
                int temp = 1 + helper(k+1, j, s, dp);
                ans = min(ans, temp);
            }
        }
        return dp[i][j] = ans;
    }
    int minCut(string s) {
        int n = s.length();
        vector<vector<int>>dp(n,vector<int>(n, -1));
        return helper(0, n-1, s, dp);
    }
};