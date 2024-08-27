class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        ios_base::sync_with_stdio(false); cin.tie(0);
        const double inf = 1/0.0;
        vector<double> dp(n, -inf);
        vector<bool> vis(n, 0);
        priority_queue<pair<double, int>> pq;
        vector<vector<pair<int, double>>> adj(n);
        int m = edges.size(), u, v, curr;
        double w;
        for(int i = 0; i < m; i++) {
            u = edges[i][0];
            v = edges[i][1];
            w = log10(succProb[i]);
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        dp[start_node] = log10(1);
        pq.push({dp[start_node], start_node});
        while(!pq.empty()) {
            curr = pq.top().second;
            pq.pop();
            if(vis[curr]) continue;
            vis[curr] = 1;
            for(const auto &[to, w]: adj[curr]) {
                if(dp[curr] + w > dp[to]) {
                    dp[to] = dp[curr] + w;
                    pq.push({dp[to], to});
                }
            }
        }
        return dp[end_node] == -inf ? 0 : pow(10, dp[end_node]);
    }
};