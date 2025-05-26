class Solution {
public:
    vector<vector<int>> adj;
    vector<bool> vis, vis2;
    vector<vector<int>> dp;
    bool valid;
    void dfs(int curr, string &colors) {
        if(vis[curr]) {
            if(!vis2[curr]) valid = 0;
            return;
        }
        vis[curr] = 1;
        for(const int &to: adj[curr]) {
            dfs(to, colors);
            for(int i = 0; i < 26; i++) {
                dp[curr][i] = max(dp[curr][i], dp[to][i]);
            }
        }
        dp[curr][colors[curr]-'a']++;
        vis2[curr] = 1;
    }
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size();
        valid = 1;
        adj.resize(n);
        dp.assign(n, vector<int>(26, 0));
        vis = vis2 = vector<bool>(n, 0);
        int ans = 0;
        for(const auto &i: edges) {
            adj[i[0]].push_back(i[1]);
        }
        for(int i = 0; i < n; i++) {
            if(vis[i]) continue;
            dfs(i, colors);
            for(int j = 0; j < 26; j++) {
                ans = max(ans, dp[i][j]);
            }
        }
        if(!valid) return -1;
        return ans;
    }
};