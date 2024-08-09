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
    int helper(TreeNode *root, int &ans){
        if(root == NULL){
            return 0;
        }

        int left = helper(root->left, ans);
        int right = helper(root->right, ans);

        // right + root
        // left + root
        // root + left + right               
        ans = max({ans, right + left + root->val, right + root->val, left + root->val, root->val});
        return max({right + root->val, left + root->val, root->val});
    }
    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        helper(root, ans);
        return ans;
    }
};