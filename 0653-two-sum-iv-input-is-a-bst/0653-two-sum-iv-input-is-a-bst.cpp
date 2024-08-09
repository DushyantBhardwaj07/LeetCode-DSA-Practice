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
    void helper(TreeNode *root, set<int> &s, int k, bool &flag){
        if(root == NULL) return;
        if(s.find(k-root->val) != s.end()) flag = true;
        s.insert(root->val);
        helper(root->left, s, k, flag);
        helper(root->right, s, k, flag);
    }
    bool findTarget(TreeNode* root, int k) {
        set<int>s;
        bool flag = false;
        helper(root, s, k, flag);
        return flag;
    }
};