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
    void helper(TreeNode *root, vector<int> adj[]){
        if(root == NULL) return;
        int u = root->val;
        if(root->left != NULL){
            int v = root->left->val;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        if(root->right != NULL){
            int v = root->right->val;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        helper(root->left, adj);
        helper(root->right, adj);
    }
    int amountOfTime(TreeNode* root, int start) {
        vector<int>adj[100001];
        helper(root, adj);
        int ans = 0;
        list<int>ls;
        ls.push_back(start);
        vector<bool>vis(1e5+1, false);
        vis[start] = true;
        while(!ls.empty()){
            int len = ls.size();
            for(int i=0;i<len;i++){
                int node = ls.front();
                for(auto it : adj[node]){
                    if(!vis[it]){
                        vis[it] = true;
                        ls.push_back(it);
                    }
                }
                ls.pop_front();
            }
            ans++;
        }
        return ans-1;        
    }
};