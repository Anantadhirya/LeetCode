#define LL long long

const LL inf = LLONG_MAX;

class Solution {
public:
    bool check(int mn, int &n, vector<vector<pair<int, LL>>> &adj, LL &k) {
        vector<LL> dist(n, inf);
        vector<bool> vis(n, 0);
        priority_queue<pair<LL, int>> pq;
        int cur;

        auto add = [&](int i, LL d) -> void {
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
            for(auto &[to, d]: adj[cur]) {
                if(d < mn) continue;
                add(to, dist[cur] + d);
            }
        }
        return dist[n-1] <= k;
    }
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, LL k) {
        int n = online.size();
        vector<vector<pair<int, LL>>> adj(n);
        int l = 0, r = 0, mid, ans = -1;
        for(auto &i: edges) {
            if(!online[i[0]] || !online[i[1]]) continue;
            adj[i[0]].push_back({i[1], i[2]});
            r = max(r, i[2]);
        }
        while(l <= r) {
            mid = (l+r)/2;
            if(check(mid, n, adj, k)) {
                ans = mid;
                l = mid + 1;
            } else r = mid - 1;
        }
        return ans;
    }
};