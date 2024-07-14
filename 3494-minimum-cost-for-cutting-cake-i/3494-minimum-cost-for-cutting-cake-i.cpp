class Solution {
public:
    int minimumCost(int m, int n, vector<int>& hc, vector<int>& vc) {
        sort(hc.begin(), hc.end(), greater<int>());
        sort(vc.begin(), vc.end(), greater<int>());

        int h = 1, v = 1;
        int i = 0, j = 0;
        int ans = 0;

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