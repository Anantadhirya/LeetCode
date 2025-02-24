class Solution {
public:
    void dfs(int curr, int from, int aliceDist, vector<int> &bobDist, vector<int> &dp, vector<int> &amount, vector<vector<int>> &adj) {
        for(const int &to: adj[curr]) {
            if(to == from) continue;
            dfs(to, curr, aliceDist+1, bobDist, dp, amount, adj);
            if(bobDist[to] != INT_MAX) bobDist[curr] = bobDist[to] + 1;
            dp[curr] = max(dp[curr], dp[to]);
        }
        if(dp[curr] == INT_MIN) dp[curr] = 0;
        dp[curr] += (aliceDist <= bobDist[curr] ? aliceDist < bobDist[curr] ? amount[curr] : amount[curr]/2 : 0);
    }
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n = amount.size();
        vector<int> bobDist(n, INT_MAX), dp(n, INT_MIN);
        vector<vector<int>> adj(n);
        
        for(const auto &i: edges) {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        bobDist[bob] = 0;

        dfs(0, -1, 0, bobDist, dp, amount, adj);
        return dp[0];
    }
};