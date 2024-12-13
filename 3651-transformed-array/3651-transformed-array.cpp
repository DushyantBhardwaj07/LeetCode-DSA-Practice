class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans(n,0);
        for(int i=0;i<n;i++){
            int temp = (i+nums[i]);
            while(temp < 0) temp = temp + n;
            ans[i] = nums[temp%n];
        }
        return ans;
    }
};