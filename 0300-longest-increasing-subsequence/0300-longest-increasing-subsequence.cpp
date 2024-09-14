class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();

        // O(n^2) approach
        // vector<int>dp(n, 1);
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<i;j++){
        //         if(nums[i] > nums[j]){
        //             dp[i] = max(dp[i], dp[j] + 1);
        //         }
        //     }
        // }
        // return *max_element(dp.begin(), dp.end());

        // O(nlogn) approach
        vector<int>ans;
        for(int i=0;i<n;i++){
            int ind = lower_bound(ans.begin(), ans.end(), nums[i]) - ans.begin();
            if(ind == ans.size()){
                ans.push_back(nums[i]);
            }
            else{
                ans[ind] = nums[i];
            }
        }
        return ans.size();
    }
};