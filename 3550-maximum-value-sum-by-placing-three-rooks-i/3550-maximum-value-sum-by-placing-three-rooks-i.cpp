#define ll long long
class Solution {
public:
    long long maximumValueSum(vector<vector<int>>& board) {
        vector<pair<ll,pair<ll,ll>>>m; // val, row, col
        int n = board.size();
        int mn = board[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<mn;j++){
                m.push_back({board[i][j], {i, j}});
            }
        }
        sort(m.begin(), m.end(), greater<pair<ll,pair<ll,ll>>>());

        ll ans = LLONG_MIN;
        for(int i=0;i<min(100,(int) m.size());i++){
            for(int j=0;j<min(100, (int) m.size());j++){
                for(int k=0;k<min(100, (int) m.size());k++){
                    if(i!=j && j!=k && i!= k && m[i].second.first != m[j].second.first && m[j].second.first != m[k].second.first &&  m[i].second.first != m[k].second.first && m[i].second.second != m[j].second.second && m[j].second.second != m[k].second.second && m[i].second.second != m[k].second.second){
                        ans = max(ans,(ll) (m[i].first + m[j].first + m[k].first));
                    }
                }
            }
        }
        return ans;
    }
};