class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int,int>>adj[n+1];
        for(int i=0;i<times.size();i++){
            int u = times[i][0];
            int v = times[i][1];
            int d = times[i][2];
            adj[u].push_back({v, d});
        }
        vector<int>dist(n+1, 1e9);
        set<pair<int,int>>s;
        s.insert({0, k});
        dist[k] = 0;
        while(!s.empty()){
            auto it = s.begin();
            int d = it->first;
            int node = it->second;
            s.erase(it);
            for(auto it : adj[node]){
                int n = it.first;
                int dis = it.second;
                if(dis + d < dist[n]){
                    s.insert({d+dis, n});
                    dist[n] = d+dis;
                }
            }
        }

        int maxi = 0;
        for(int i=1;i<dist.size();i++){
            maxi = max(maxi, dist[i]);
        }

        return maxi == 1e9? -1: maxi;

    }
};