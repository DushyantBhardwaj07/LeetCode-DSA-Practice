class Solution {
public:
    int give(vector<int> &bits){
        int num = 0;
        for(int i=0;i<32;i++){
            if(bits[i] > 0) num = num + (1<<i);
        }
        return num;
    }

    int longestNiceSubarray(vector<int>& nums) {
        int left =0, right = 0, ans = 1;
        int n = nums.size();
        vector<int>bits(32, 0);
        int t = 4;
        while(right<n-1){
            for(int i=0;i<32;i++){
                int bit = (nums[right] >> i) & 1;
                if(bit) bits[i]++;
            }
            // cout<<left<<" "<<right << " " << give(bits) <<" " << nums[right+1] << " " <<(give(bits)&nums[right+1])<<endl;
            if((right <n-1) && ((give(bits)&nums[right+1]) == 0)){
                right++;
                ans = max(ans, right-left+1);
            }
            else if((right <n-1) && ((give(bits)&nums[right+1]) != 0)){
                while((left<= right) && ((give(bits)&nums[right+1]) != 0)){
                    for(int i=0;i<32;i++){
                        int bit = (nums[left] >> i) & 1;
                        if(bit) bits[i]--;
                    }
                    left++;
                }
                if(give(bits)&nums[right+1] == 0) ans = max(ans, right-left+1);
                right++;
            }
        }
        return ans;
    }
};