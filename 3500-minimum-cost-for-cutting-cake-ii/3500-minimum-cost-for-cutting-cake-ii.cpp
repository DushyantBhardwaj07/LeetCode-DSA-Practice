#define ll long long
class Solution {
public:
    ll minimumCost(ll m, ll n, vector<int>& hc, vector<int>& vc) {
        sort(hc.begin(), hc.end(), greater<ll>());
        sort(vc.begin(), vc.end(), greater<ll>());

        ll h = 1, v = 1;
        ll i = 0, j = 0;
        ll ans = 0;

        while((i < hc.size()) && (j < vc.size())){
            if(hc[i] >= vc[j]){
                ans = ans + h * hc[i];
                i++;
                v++;
            }
            else{
                ans = ans + v * vc[j];
                j++;
                h++;
            }
        }

        while(i < hc.size()){
            ans = ans + h * hc[i];
            v++;
            i++;
        }

        while(j < vc.size()){
            ans = ans + v * vc[j];
            h++;
            j++;
        }
        return ans;
    }
};