class Solution {
public:
    void dfs(int node, vector<int> &v, vector<vector<int>> &ans, vector<int> adj[], int n){
        v.push_back(node);
        if(node == n-1){
            ans.push_back(v);
        }
        for(auto it : adj[node]){
            dfs(it, v, ans, adj, n);
        }
        v.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>>ans;
        vector<int>v;
        vector<int>adj[n];
        for(int i=0;i<n;i++){
            for(int j=0;j<graph[i].size();j++){
                adj[i].push_back(graph[i][j]);
            }
        }     
        dfs(0, v, ans, adj, n);
        return ans;        
    }
};