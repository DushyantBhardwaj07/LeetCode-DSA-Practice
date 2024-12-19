class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int>ans;
        vector<int>temp;
        for(int i=0;i<boxes.length();i++){
            if(boxes[i] == '1') temp.push_back(i);
        }        
        for(int i=0;i<boxes.length();i++){
            int t = 0;
            for(auto it : temp){
                t = t + abs(i-it);
            }
            ans.push_back(t);
        }
        return ans;
    }
};