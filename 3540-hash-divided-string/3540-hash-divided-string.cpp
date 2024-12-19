class Solution {
public:
    string stringHash(string s, int k) {
        string ans = "";
        int n = s.length();
        int temp = 0;
        for(int i=0;i<n;i++){
            temp = temp + s[i] - 'a';
            if((i+1)%k == 0){
                ans = ans + (char)((temp%26) + 'a');
                temp = 0;                                
            }
        }
        return ans;
    }
};