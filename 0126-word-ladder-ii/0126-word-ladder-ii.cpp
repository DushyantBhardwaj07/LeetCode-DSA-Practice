class Solution {
public:
    int bfs(string b,string e, map<string, vector<string>> &adj, set<string>s){
        list<pair<string, int>>ls;
        ls.push_back({b,1});
        map<string, int>m; // string - level
        m[b] = 1;
        int ans = INT_MAX;
        while(!ls.empty()){
            string str = ls.front().first;
            int level = ls.front().second;
            ls.pop_front();

            for(int i=0;i<str.length();i++){
                string temp = str;
                for(char a='a';a<='z';a++){
                    temp[i] = a;
                    if(s.find(temp) != s.end()){
                        if(level < m[temp]){
                            adj[temp].push_back(str);
                            m[str] = level;
                        }
                        else{
                            if(m[temp] == 0){
                                if(temp == e) ans = min(ans, level+1);
                                ls.push_back({temp, level+1});
                                adj[temp].push_back(str);
                                m[temp] = level+1;
                            }
                        }
                    }
                }
            }                
        }
        return ans;
    }

    void dfs(string b, string e, map<string, vector<string>> &adj, vector<vector<string>> &ans, vector<string> &temp, int len, set<string> &s){
        if(b == e){
            if(len == temp.size()) ans.push_back(temp);
            return;
        }                
        for(auto it : adj[b]){
            temp.push_back(it);
            dfs(it, e, adj, ans, temp, len, s);
            temp.pop_back();
        }
    }
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>>ans;
        vector<string>temp;
        set<string>s;
        for(auto it : wordList) s.insert(it);
        if(s.find(endWord) == s.end())  return ans;
        map<string,vector<string>>adj;
        int len = bfs(beginWord,endWord, adj, s);
        temp.push_back(endWord);
        dfs(endWord, beginWord, adj, ans, temp, len, s);
        for(auto &it : ans){
            reverse(it.begin(), it.end());
        }
        return ans;
    }
};