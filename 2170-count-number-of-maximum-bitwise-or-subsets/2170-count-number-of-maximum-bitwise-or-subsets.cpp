class Solution {
public:
    void helper(int i, vector<int>&v, vector<vector<int>> &ans, vector<int>&nums, int n){
        if(i>=n){
            ans.push_back(v);
            return;
        }

        v.push_back(nums[i]);
        helper(i+1, v, ans, nums, n);
        v.pop_back();
        helper(i+1, v, ans, nums, n);

    }
    int countMaxOrSubsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>v;
        int temp = 0;
        int finalans = 0;
        for(auto it : nums) temp = temp | it;

        int n = nums.size();
        helper(0, v, ans, nums, n);
        for(auto it : ans){
            int t=0;
            for(auto itr : it){
                t=t|itr;
            }
            if(t == temp) finalans++;
        }
        return finalans;
    }
};