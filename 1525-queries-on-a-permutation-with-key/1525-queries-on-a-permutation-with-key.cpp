class Solution {
public:
    vector<int> processQueries(vector<int>& queries, int m) {
        list<int>ls;
        vector<int>ans;
        for(int i=1;i<=m;i++) ls.push_back(i);        
        for(int i=0;i<queries.size();i++){
            int ptr =0;
            for(auto it : ls){
                if(queries[i] == it){
                    ans.push_back(ptr);
                    auto itr = ls.begin();
                    advance(itr, ptr);
                    ls.erase(itr);
                    ls.push_front(queries[i]);
                    break;
                }
                ptr++;
            }
        }
        return ans;
    }
};