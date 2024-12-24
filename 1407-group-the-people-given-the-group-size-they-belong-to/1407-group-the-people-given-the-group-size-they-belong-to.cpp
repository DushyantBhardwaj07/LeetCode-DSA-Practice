class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        vector<vector<int>>ans;
        map<int,vector<int>>m;
        int n = groupSizes.size();
        for(int i=0;i<n;i++){
            m[groupSizes[i]].push_back(i);
        }

        for(auto it : m){
            for(int i=0;i<it.second.size();i = i + it.first){
                vector<int>temp;
                for(int j=i;j<i+it.first;j++){
                    temp.push_back(it.second[j]);
                }
                ans.push_back(temp);
            }
        }

        return ans;
    }
};