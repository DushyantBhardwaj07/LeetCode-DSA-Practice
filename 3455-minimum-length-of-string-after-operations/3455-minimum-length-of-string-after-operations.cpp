class Solution {
public:
    int minimumLength(string s) {
        map<char,int>m;
        for(auto it : s){
            m[it]++;
        }
        int ans = 0;
        for(auto it : m){
            if(it.second & 1) ans++;
            else ans=ans+2;
        }
        return ans;
    }
};