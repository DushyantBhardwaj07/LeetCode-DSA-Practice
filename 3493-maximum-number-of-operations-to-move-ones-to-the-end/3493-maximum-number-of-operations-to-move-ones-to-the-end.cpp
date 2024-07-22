class Solution {
public:
    int maxOperations(string s) {
        int ans = 0;
        int j = 0, n = s.length();
        int z = -1;
        for(int i=n-1;i>=0;i--){
            if(s[i] == '0'){
                z = i;
                break;                
            }
        }
        int temp = 0;
        if(z == -1) return 0;
        while(j<n){
            if(s[j] == '1' && j < z){
                while(s[j] == '1'){
                    temp++;
                    j++;
                }
                ans = ans + temp;
            }
            else{
                j++;
            }
        } 
        return ans;       
    }
};