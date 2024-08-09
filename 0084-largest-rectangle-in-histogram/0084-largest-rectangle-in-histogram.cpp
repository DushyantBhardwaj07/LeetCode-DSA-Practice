class Solution {
public:
    int largestRectangleArea(vector<int>& v) {
        int n = v.size();        
        vector<int>right(n, n);
        vector<int>left(n, 0);
        stack<int>s;
        //right

        for(int i=n-1;i>=0;i--){
            while(!s.empty() && v[s.top()] >= v[i]){
                s.pop();
            }
            if(!s.empty()){
                right[i] = s.top();
            }
            s.push(i);
        }

        s = stack<int>();
        //left;

        for(int i=0;i<n;i++){
            while(!s.empty() && v[s.top()] >= v[i]){
                s.pop();
            }
            if(!s.empty()){
                left[i] = s.top()  +1;
            }
            s.push(i);
        }
        // for(auto it : right){
        //     cout<<it<<" ";
        // }
        // cout<<endl;
        // for(auto it : left){
        //     cout<<it<<" ";
        // }
        int ans = 0;
        for(int i=0;i<n;i++){
            ans = max(ans, abs(left[i] - right[i]) * v[i]);
        }
        return ans;

    }
};