class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        list<int>ls;
        vector<int>ans;
        int left = 0, right = 0;

        while(right<n){
            while(!ls.empty() && ls.back() < nums[right]){
                ls.pop_back();
            }
            ls.push_back(nums[right]);  

            if(right-left+1 < k){
                right++;
            }
            else{
                ans.push_back(ls.front());
                if(ls.front() == nums[left]){
                    ls.pop_front();
                }
                left++;
                right++;
            }
        }        
        return ans;
    }
};