class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        vector<int>ans;
        stack<int>s;
        vector<int>nge(m, -1);
        for(int i=m-1;i>=0;i--){
            while(!s.empty() && nums2[i] > s.top()){
                s.pop();
            }
            if(!s.empty()){
                nge[i] = s.top();
            }
            s.push(nums2[i]);
        }

        for(int i=0;i<nums1.size();i++){
            for(int j=0;j<nums2.size();j++){
                if(nums1[i] == nums2[j]){
                    ans.push_back(nge[j]);
                }
            }
        }

        return ans;
    }
};