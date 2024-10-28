#define ll long long
#define mod 1000000007
class Solution {
public:
    int lengthAfterTransformations(string s, ll t) {
        vector<ll>ans(26, 0);
        ll sum = 0;
        for(auto it : s) ans[it - 'a']++;
        for(ll i=0;i<t;i++){
            bool flag = false;
            ll ab= 0 ;
            for(ll j=25;j>=0;j--){
                if(ans[j] > 0){
                    ll x = ans[j];
                    ans[j] = 0;
                    if(j == 25){
                        flag = true;
                        ab = x;
                    }
                    else{
                        ans[j+1] = (ans[j+1] + x) % mod;
                    }                
                }
            }
            if(flag){
                ans[0] = (ans[0] + ab) % mod;
                ans[1] = (ans[1] + ab) % mod;
            }
        }
        for(auto it : ans) sum = (sum + it)%mod;
        return sum;
    }
};