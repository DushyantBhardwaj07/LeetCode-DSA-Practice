/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode * helper(vector<int> nums){
        if(nums.size() == 0) return NULL;
        int maxi = *max_element(nums.begin(), nums.end());
        vector<int>left, right;
        bool flag = true;
        for(int i=0;i<nums.size();i++){
            if(maxi == nums[i]){
                flag = false;
            }
            else{
                if(flag) left.push_back(nums[i]);                
                else right.push_back(nums[i]);         
            }
        }
        TreeNode *root = new TreeNode(maxi);
        root->left = helper(left);
        root->right = helper(right);

        return root;
    }

    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return helper(nums);
    }
};