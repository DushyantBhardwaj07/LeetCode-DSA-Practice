class Solution {
public:
    int maxDifference(string s) {
        map<char,int>m;
        for(auto it : s){
            m[it]++;
        }
        int mini = INT_MAX, maxi = INT_MIN;
        for(auto it : m){
            if(it.second & 1){
                maxi = max(maxi, it.second);
            }
            else{
                mini = min(mini, it.second);
            }
        }
        return maxi-mini;
    }
};