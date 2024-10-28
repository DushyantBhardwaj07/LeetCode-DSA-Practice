class Solution {
public:
    int possibleStringCount(string word) {
        int ans = 0;
        int c = 0;
        for(int i=1;i<word.length();i++){
            if(word[i] == word[i-1])c++;
            else{
                ans = ans + c;
                c= 0;
            }
        }
        ans = ans + c;
        return ans+1;
    }
};