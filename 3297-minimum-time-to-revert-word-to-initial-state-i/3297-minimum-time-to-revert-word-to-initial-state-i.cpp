class Solution {
public:
    bool check(int mid, string word, int k){
        if(k *mid > word.length()) return true;
        string org = word;
        string subtr = org.substr(k*mid, org.length() - k*mid);
        for(int i=0;i<subtr.length();i++){
            if(subtr[i] != word[i]) return false;
        }
        return true;
    }

    int minimumTimeToInitialState(string word, int k) {
        int ans = 0;
        for(int i=k;i<word.length();i=i+k){
            string org = word;
            string subtr = org.substr(i, org.length() - i);
            cout<<org<<" "<<subtr<<endl;
            bool flag = true;
            ans++;
            for(int j=0;j<subtr.length();j++){
                if(subtr[j] != word[j]){
                    flag = false;
                    break;
                }
            }
            if(flag) return ans;
        }
        int ret = ceil((word.length()) / ((double)k));
        return ret;
    }
};