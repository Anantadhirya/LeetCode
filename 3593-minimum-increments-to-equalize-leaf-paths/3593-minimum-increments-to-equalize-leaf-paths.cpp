#define LL long long

class Solution {
public:
    void dfs(int cur, int from, vector<vector<int>> &adj, vector<int> &cost, vector<int> &dp, vector<LL> &val) {
        for(int &to: adj[cur]) {
            if(to == from) continue;
            dfs(to, cur, adj, cost, dp, val);
            val[cur] = max(val[cur], val[to]);
            dp[cur] += dp[to];
        }
        for(int &to: adj[cur]) {
            if(to == from) continue;
            if(val[to] != val[cur]) dp[cur]++;
        }
        val[cur] += (LL)cost[cur];
    }
    int minIncrease(int n, vector<vector<int>>& edges, vector<int>& cost) {
        vector<int> dp(n);
        vector<LL> val(n, 0);
        vector<vector<int>> adj(n);
        for(auto &i: edges) {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        dfs(0, -1, adj, cost, dp, val);
        return dp[0];
    }
};