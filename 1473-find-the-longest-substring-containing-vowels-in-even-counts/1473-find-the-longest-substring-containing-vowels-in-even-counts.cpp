class Solution {
public:
    bool isVowel(char a){
        if(a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u'){
            return true;            
        }
        return false;
    }
    int findTheLongestSubstring(string s) {
        vector<int>prefix;
        int temp = 0;
        map<int,int>m;
        m[0] = -1;
        for(int i=0;i<s.length();i++){
            if(isVowel(s[i])){
                temp = temp ^ s[i];
            }
            prefix.push_back(temp);
        }
        int maxi = 0;
        for(int i=0;i<prefix.size();i++){
            if(m.find(prefix[i]) != m.end()){
                maxi = max(maxi, i- m[prefix[i]]);
            }

            if(m.find(prefix[i]) == m.end()){
                m[prefix[i]] = i;
            }

            // if(prefix[i] == 0){
            //     maxi = max(maxi, i+1);
            // }
        }

        // for(auto it : prefix){
        //     cout<<it<<" ";
        // }
        // cout<<endl;
        // for(auto it : m){
        //     cout<<it.first<<" "<<it.second<<endl;
        // }

        return maxi;
    }
};