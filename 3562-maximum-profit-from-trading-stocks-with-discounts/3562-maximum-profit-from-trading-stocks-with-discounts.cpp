class Solution {
public:
    void dfs(int cur, int &n, int &budget, vector<vector<int>> &adj, vector<vector<int>> &dp, vector<vector<int>> &dp1, vector<int> &present, vector<int> &future) {
        for(auto to: adj[cur]) {
            dfs(to, n, budget, adj, dp, dp1, present, future);
        }
        vector<int> sub(budget+1, 0);
        vector<int> sub1(budget+1, 0);
        for(auto to: adj[cur]) {
            for(int b = budget; b >= 0; b--) {
                for(int i = 0; i <= b; i++) {
                    sub[b] = max(sub[b], sub[b-i] + dp[to][i]);
                    sub1[b] = max(sub1[b], sub1[b-i] + dp1[to][i]);
                }
            }
        }
        for(int b = 0; b <= budget; b++) {
            dp[cur][b] = dp1[cur][b] = sub[b];
            if(b >= present[cur]) dp[cur][b] = max(dp[cur][b], sub1[b - present[cur]] + future[cur] - present[cur]);
            if(b >= present[cur]/2) dp1[cur][b] = max(dp1[cur][b], sub1[b - present[cur]/2] + future[cur] - present[cur]/2);
        }
    }
    int maxProfit(int n, vector<int>& present, vector<int>& future, vector<vector<int>>& hierarchy, int budget) {
        vector<vector<int>> dp(n, vector<int>(budget+1, 0)), dp1(n, vector<int>(budget+1, 0));
        vector<vector<int>> adj(n);
        int ans = 0;
        for(auto i: hierarchy) {
            adj[i[0]-1].push_back(i[1]-1);
        }
        dfs(0, n, budget, adj, dp, dp1, present, future);
        return dp[0][budget];
    }
};