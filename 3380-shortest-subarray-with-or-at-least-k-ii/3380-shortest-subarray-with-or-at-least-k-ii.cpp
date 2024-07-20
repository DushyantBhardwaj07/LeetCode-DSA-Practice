class Solution {
public:
    int giveNum(vector<int> &bits){
        int num = 0;
        for(int i=0;i<32;i++){
            if(bits[i] > 0) num = num + (1 << i);
        }
        return num;
    }

    int minimumSubarrayLength(vector<int>& nums, int k) {
        int left= 0, right = 0, ans = INT_MAX, n = nums.size();
        vector<int>bits(32, 0);
        while(right < n){
            // right
            for(int i=0;i<32;i++){
                int bit = ((nums[right] >> i) & 1);
                if(bit) bits[i]++;
            }

            if(giveNum(bits) < k){
                right++;
            }
            else{
                while(left <= right && giveNum(bits) >= k){
                    ans = min(ans, right - left + 1);
                    for(int i=0;i<32;i++){
                        int bit = (nums[left] >> i) & 1;
                        if(bit) bits[i]--; 
                    }
                    left++;
                }
                right++;
            }
        }
        if(ans == INT_MAX) return -1;
        return ans;
    }
};