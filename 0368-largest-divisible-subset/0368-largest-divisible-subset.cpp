class Solution {
public:

    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int>dp(n, 1);
        vector<int>ans;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i] % nums[j] == 0){
                    dp[i] = max(dp[i], dp[j]+1);
                }
            }
        }

        int maxi = *max_element(dp.begin(), dp.end()); 
        int last = -1;       

        for(int i=n-1;i>=0;i--){
            if((last == -1 && dp[i] == maxi) || (dp[i] == maxi && last%nums[i] == 0)){
                ans.push_back(nums[i]);
                last = nums[i];
                maxi--;
            }
        }

        return ans;
    }
};
