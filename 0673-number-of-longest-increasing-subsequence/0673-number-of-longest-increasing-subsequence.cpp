class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n, 1);
        vector<int>ways(n, 1);
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i] > nums[j]){
                    dp[i] = max(dp[i], dp[j]+1);
                }
            }
        }

        for(int i=1;i<n;i++){
            int cnt = 0;
            for(int j=0;j<i;j++){
                if((nums[j] < nums[i]) && (dp[j] + 1 == dp[i])){
                    cnt = cnt + ways[j];
                }
            }
            ways[i] = max(ways[i], cnt);
        }

        int maxi = *max_element(dp.begin(), dp.end());
        int ans = 0;
        for(int i=0;i<dp.size();i++){
            if(dp[i] == maxi){
                ans = ans + ways[i];
            }
        }

        return ans;
    }
};