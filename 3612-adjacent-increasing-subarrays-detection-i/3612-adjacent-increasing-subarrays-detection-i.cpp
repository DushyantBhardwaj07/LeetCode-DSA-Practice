class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        vector<int>dp(nums.size(), 1);
        for(int i=1;i<nums.size();i++){
            if(nums[i] > nums[i-1]){
                dp[i] = dp[i-1]+1;
            }            
        }
        int ans = 0;
        for(int i=dp.size()-1;i>=k;i--){
            if(dp[i] >=k && dp[i-k] >= k){
                return true;
            }            
        }
        // for(auto it : dp){
        //     cout<<it<<" ";
        // }
        return false;
    }
};