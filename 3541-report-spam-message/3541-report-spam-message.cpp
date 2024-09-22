class Solution {
public:
    bool reportSpam(vector<string>& m, vector<string>& b) {
        sort(m.begin(), m.end());
        set<string>s;
        for(auto it : b){
            s.insert(it);
        }
        int c = 0;
        for(auto it : m){
            if(s.find(it) != s.end()) c++;
            if(c > 1) return true;
        }
        return false;
    }
};