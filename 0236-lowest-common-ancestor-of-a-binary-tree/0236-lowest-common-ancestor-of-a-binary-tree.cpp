/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode *helper(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root == NULL) return NULL;
        TreeNode *l = helper(root->left, p, q);
        TreeNode *r = helper(root->right, p, q);

        if(root == p || root == q){
            return root;
        }
        else if(l != NULL && r != NULL){
            return root;
        }
        else if(l == NULL && r != NULL){
            return r;
        }
        else if(l != NULL && r == NULL){
            return l;
        }
        return NULL;

    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return helper(root,p,q);        
    }
};