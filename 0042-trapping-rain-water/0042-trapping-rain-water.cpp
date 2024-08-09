class Solution {
public:
    int trap(vector<int>& v) {
        int n = v.size();
        vector<int>left(n, -1);
        vector<int>right(n, -1);
        stack<int>s;
        for(int i=0;i<n;i++){
            while(!s.empty() && v[i] > s.top()){
                s.pop();
            }
            if(!s.empty()){
                left[i] = s.top();
            }
            else{
                s.push(v[i]);
            }
        }
        s = stack<int>();

        for(int i=n-1;i>=0;i--){
            while(!s.empty() && v[i] > s.top()){
                s.pop();
            }
            if(!s.empty()){
                right[i] = s.top();
            }
            else{
                s.push(v[i]);
            } 
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            if(left[i] != -1  && right[i] != -1){ 
                ans = ans + min(left[i], right[i]) - v[i];
            }
        }
        for(auto it : left){
            cout<<it<<" ";
        }
        return ans;
    }
};