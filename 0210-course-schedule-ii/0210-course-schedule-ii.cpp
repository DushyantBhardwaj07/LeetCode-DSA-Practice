class Solution {
public:
    bool isCycle(int node, vector<int> adj[], vector<bool> &vis, vector<bool> &path, vector<int> &ans){
        vis[node] = true;
        path[node] = true;

        for(auto it : adj[node]){
            if(!vis[it]){
                if(isCycle(it, adj, vis, path, ans)) return true;
            }
            else{
                if(path[it]) return true;
            }
        }
        ans.push_back(node);
        path[node] = false;
        return false;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& pre) {
        vector<int>adj[numCourses];
        vector<int>ans;
        for(int i=0;i<pre.size();i++){
            int u = pre[i][0];
            int v = pre[i][1];
            adj[v].push_back(u);
        }

        vector<bool>vis(numCourses, false);

        for(int i=0;i<numCourses;i++){
            if(!vis[i]){
                vector<bool>path(numCourses, false);
                if(isCycle(i, adj, vis, path, ans)) return {};
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
