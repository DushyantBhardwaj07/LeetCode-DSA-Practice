class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        set<string>s;
        for(auto it : wordList) s.insert(it);
        if(s.find(endWord) == s.end()) return 0;
        list<pair<string,int>>ls;
        ls.push_back({beginWord, 1});
        if(s.find(beginWord) != s.end()) s.erase(beginWord);
        while(!ls.empty()){
            string str = ls.front().first;
            int level = ls.front().second;
            ls.pop_front();
            for(int i=0;i<str.length();i++){
                string temp = str;
                for(char a = 'a'; a<='z'; a++){
                    temp[i] = a;
                    if(s.find(temp) != s.end()){
                        s.erase(temp);
                        ls.push_back({temp, level+1});
                        if(temp == endWord) return level+1;
                    }
                }
            }
        }
        return 0;
    }
};