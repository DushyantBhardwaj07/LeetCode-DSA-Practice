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
    void inorder(TreeNode *root, int key, vector<int> &v){
        if(root == NULL){
            return;
        }
        inorder(root->left, key, v);
        if(root->val != key) v.push_back(root->val);
        inorder(root->right, key, v);
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL) return root;
        vector<int>v;
        inorder(root, key, v);
        if(v.size() == 0) return NULL;
        TreeNode *root1 = new TreeNode(v[0]);
        for(int i=1;i<v.size();i++){
            TreeNode *n = new TreeNode(v[i]);
            TreeNode *prev = root1;
            TreeNode *p = root1;
            while(p != NULL){
                prev = p;
                if(p->val > v[i]){
                    p = p->left;
                }
                else{
                    p = p->right;
                }
            }
            if(v[i] > prev->val){
                prev->right = n;
            }
            else{
                prev->left = n;
            }
        }
        return root1;
    }
};