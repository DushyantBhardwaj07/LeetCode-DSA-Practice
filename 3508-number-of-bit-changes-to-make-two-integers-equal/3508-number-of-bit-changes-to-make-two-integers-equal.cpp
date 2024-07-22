class Solution {
public:
    int minChanges(int n, int k) {
        string sn,sk;
        stringstream sso1, sso2;
        for(int i=0;i<32;i++){
            sso1<<((n>>i) & 1);
            sso2<<((k>>i) & 1);
        }
        sso1>>sn; sso2>>sk;
        cout<<sn<<endl;
        cout<<sk<<endl;
        int ans = 0;
        for(int i=0;i<sn.length();i++){
            if(sn[i] == '0' && sk[i] == '1') return -1;
            else if(sn[i] == '1' && sk[i] == '0') ans++;
        }
        return ans;
    }
};