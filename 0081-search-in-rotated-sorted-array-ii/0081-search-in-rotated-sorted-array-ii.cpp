class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int low = 0, high = nums.size()-1;
        while(low <= high){
            int mid = low + (high-low)/2;
            if(nums[mid] == target){
                return true;
            }
            else if(nums[low] == nums[mid] && nums[mid] == nums[high]){
                low++;
                high--;
                continue;
            }
            else if(nums[mid] <= nums[high]){
                if(nums[mid] <= target && target <=nums[high]){
                    low = mid + 1;
                }
                else{
                    high = mid-1;
                }
            }        
            else if(nums[low] <= nums[mid]){
                if(nums[mid] >= target && nums[low] <= target){
                    high = mid-1;
                }
                else{
                    low = mid+1;
                }
            }
        }
        return false;
    }
};