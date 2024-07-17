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
    void helper(TreeNode *&root, vector<TreeNode *> &ans, set<int> &del){
        if(root == NULL) return;
        helper(root->left, ans, del);
        helper(root->right, ans, del);
        if(del.find(root->val) != del.end()){
            if(root->left != NULL) ans.push_back(root->left);
            if(root->right != NULL) ans.push_back(root->right);
            root = NULL;
        }
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        set<int>del;
        for(auto it : to_delete) del.insert(it);
        vector<TreeNode *>ans;
        helper(root, ans, del);
        if(root!=NULL && (del.find(root->val) == del.end())) ans.push_back(root);
        return ans;
    }
};