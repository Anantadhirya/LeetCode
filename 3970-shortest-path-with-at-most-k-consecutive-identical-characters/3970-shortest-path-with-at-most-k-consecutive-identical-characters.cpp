class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        const int inf = INT_MAX;
        vector<vector<pair<int, int>>> adj(n);

        int d, cur, cnt;
        vector<vector<int>> dist(n, vector<int>(k+1, inf));
        vector<vector<bool>> vis(n, vector<bool>(k+1, 0));
        priority_queue<array<int, 3>> pq;
        int ans = inf;

        for(auto &i: edges) {
            adj[i[0]].push_back({i[1], i[2]});
        }
        auto add = [&](int idx, int cnt, int d) -> void {
            if(cnt > k) return;
            if(d < dist[idx][cnt]) {
                dist[idx][cnt] = d;
                pq.push({-d, idx, cnt});
            }
        };

        add(0, 1, 0);
        while(!pq.empty()) {
            d = -pq.top()[0];
            cur = pq.top()[1];
            cnt = pq.top()[2];
            pq.pop();
            if(vis[cur][cnt]) continue;
            vis[cur][cnt] = 1;
            if(cur == n-1) ans = min(ans, d);
            for(auto &[to, w]: adj[cur]) {
                add(to, (labels[to] == labels[cur] ? cnt+1 : 1), d + w);
            }
        }
        return ans == inf ? -1 : ans;
    }
};