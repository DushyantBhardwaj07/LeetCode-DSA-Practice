class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>>adj[n];
        for(auto it : flights){
            adj[it[0]].push_back({it[1], it[2]});
        }

        set<pair<int,pair<int,int>>>s; // { stops, dist, node }
        vector<int>dist(n, 1e9);
        dist[src] = 0;
        s.insert({0, {0, src}});
        while(!s.empty()){
            auto it = s.begin();
            int stops = it->first;
            int dis = it->second.first;
            int node = it->second.second;
            s.erase(it);
            for(auto it : adj[node]){
                int n = it.first;
                int d = it.second;
                if(stops+1<= k || (n == dst && stops<=k)){
                    if(d + dis < dist[n]){
                        dist[n] = d + dis;
                        s.insert({stops+1, {d + dis, n}});
                    }
                }
            }
        }
        if(dist[dst] == 1e9) return -1;
        return dist[dst];
    }
};