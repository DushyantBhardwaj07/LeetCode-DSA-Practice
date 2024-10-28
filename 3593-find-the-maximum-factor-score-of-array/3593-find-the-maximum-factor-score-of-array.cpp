#define ll long long
class Solution {
public:
    ll GCD(vector<int>arr){
        ll ans = 0;
        if(arr.size() >= 1){
            ans = arr[0];
            for(int i=1;i<arr.size();i++){
                ans = __gcd(ans, (ll)arr[i]);
            }
        }
        return ans;
    }
    ll LCM(vector<int>arr){
        ll ans = 0;
        if(arr.size() >= 1){
            ans = arr[0];
            for(int i=1;i<arr.size();i++){
                ans = (ans * arr[i])/__gcd(ans, (ll)arr[i]);
            }
        }
        return ans;
    }

    long long maxScore(vector<int>& nums) {
        ll ans = LCM(nums) * GCD(nums);
        for(int i=0;i<nums.size();i++){
            vector<int>arr = nums;
            arr.erase(arr.begin() + i);
            ans = max(ans, LCM(arr) * GCD(arr));
        }
        return ans;
    }
};