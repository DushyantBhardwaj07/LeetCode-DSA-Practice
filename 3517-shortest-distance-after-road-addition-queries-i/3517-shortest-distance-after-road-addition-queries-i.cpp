class Solution {
public:
    int bfs(vector<int> adj[], int n){
        vector<int>dist(n, 1e9);
        dist[0] = 0;
        list<pair<int,int>>ls; // dist, node
        ls.push_back({0, 0});
        while(!ls.empty()){
            int d = ls.front().first;
            int node = ls.front().second;
            ls.pop_front();
            for(auto it : adj[node]){
                if(d + 1 < dist[it]){
                    dist[it] = d+1;
                    ls.push_back({d+1, it});
                }                
            }
        }
        return dist[n-1];
    }
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<int>ans;
        vector<int>adj[n]; 
        for(int i=0;i<n-1;i++){
            adj[i].push_back(i+1);
        }

        for(int i=0;i<queries.size();i++){
            int u = queries[i][0];
            int v = queries[i][1];
            adj[u].push_back(v);
            ans.push_back(bfs(adj, n));
        }
        return ans;        
    }
};