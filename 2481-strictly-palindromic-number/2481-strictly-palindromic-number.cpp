class Solution {
public:
    bool isPalindrome(string s){
        int i=0,j=s.length()-1;
        while(i<=j){
            if(s[i] != s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }

    string create(int n, int num){
        stringstream sso;
        while(n>0){
            int rem = n%num;
            sso<<rem;
            n = n/num;
        }
        string ans;
        sso>>ans;
        return ans;
    }
    bool isStrictlyPalindromic(int n) {
        vector<bool>v(1e5+2, 1);
        for(int i=2;i<v.size();i++){
            if(v[i]){
                for(int j=i;j<v.size();j=j+i){
                    if(j!=i) v[j] = 0;
                }
            }
        }
            
        for(int i=2;i<=n-2;i++){
            if(v[i]){
                string temp = create(n, i);
                if(!isPalindrome(temp)) return false;
            }
        }
        return true;
    }
};