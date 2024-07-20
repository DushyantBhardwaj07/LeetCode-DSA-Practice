class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& q) {
        vector<int>ans;
        vector<int>pre;
        pre.push_back(arr[0]);        
        for(int i=1;i<arr.size();i++){
            pre.push_back(pre.back() ^ arr[i]);
        }
        int temp = 0;
        for(auto &it : q){
            int f = it[0];
            int s = it[1];
            temp = pre[s];
            if(f > 0){
                temp = temp ^ pre[f-1];
            }
            ans.push_back(temp);
        }
        return ans;
    }
};