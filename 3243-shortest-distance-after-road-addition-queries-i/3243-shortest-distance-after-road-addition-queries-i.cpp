class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        ios_base::sync_with_stdio(false); cin.tie(0);
        vector<vector<int>> adj(n);
        vector<int> ans;
        vector<int> dp(n);
        for(auto &i: queries) {
            adj[i[1]].push_back(i[0]);
            dp[0] = 0;
            for(int i = 1; i < n; i++) {
                dp[i] = dp[i-1] + 1;
                for(auto &j: adj[i]) {
                    dp[i] = min(dp[i], dp[j] + 1);
                }
            }
            ans.push_back(dp[n-1]);
        }
        return ans;
    }
};