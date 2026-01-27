const auto init = []() { ios_base::sync_with_stdio(false); cin.tie(0); return nullptr; }();

class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        const int inf = INT_MAX;
        int cur;
        vector<vector<pair<int, int>>> adj(n);
        vector<int> dist(n, inf);
        vector<bool> vis(n, 0);
        priority_queue<pair<int, int>> pq;
        for(auto i: edges) {
            adj[i[0]].push_back({i[1], i[2]});
            adj[i[1]].push_back({i[0], 2*i[2]});
        }
        auto add = [&](int i, int d) {
            if(d < dist[i]) {
                dist[i] = d;
                pq.push({-d, i});
            }
        };
        add(0, 0);
        while(!pq.empty()) {
            cur = pq.top().second;
            pq.pop();
            if(vis[cur]) continue;
            vis[cur] = 1;
            for(auto [to, w]: adj[cur]) {
                add(to, dist[cur] + w);
            }
        }
        return dist[n-1] == inf ? -1 : dist[n-1];
    }
};