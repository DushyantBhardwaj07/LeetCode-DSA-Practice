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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode *n = root;
        while(n != NULL){
            if((p->val<n->val) && (n->val<q->val) || (p->val > n->val) && (n->val > q->val)){
                return n;
            }
            else if(p->val == n->val || q->val == n->val){
                return n;
            }
            else if(p->val < n->val && q->val< n->val){
                n = n->left;
            }
            else if(p->val   > n->val && q->val > n->val){
                n = n->right;
            }
        }                
        return NULL;
    }
};