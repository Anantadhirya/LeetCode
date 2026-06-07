class Solution {
public:
    int h(int cur, int from, vector<vector<int>> &adj) {
        int ret = 0;
        for(auto to: adj[cur]) {
            if(to == from) continue;
            ret = max(ret, h(to, cur, adj) + 1);
        }
        return ret;
    }
    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        const int MOD = 1e9 + 7;
        vector<vector<int>> adj(n);
        for(auto &i: edges) {
            adj[i[0]-1].push_back(i[1]-1);
            adj[i[1]-1].push_back(i[0]-1);
        }
        int k = h(0, -1, adj);
        vector<vector<int>> dp(k+1, vector<int>(2, 0));
        dp[0][0] = 1;
        for(int i = 0; i < k; i++) {
            for(int p = 0; p < 2; p++) {
                (dp[i+1][(p+1)%2] += dp[i][p]) %= MOD;
                (dp[i+1][(p+2)%2] += dp[i][p]) %= MOD;
            }
        }
        return dp[k][1];
    }
};