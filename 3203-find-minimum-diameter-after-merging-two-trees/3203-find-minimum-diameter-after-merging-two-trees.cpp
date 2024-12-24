class Solution {
public:
    void dfs(int curr, int from, vector<vector<int>> &adj, vector<vector<pair<int, int>>> &dp) {
        dp[curr].push_back({0, -1});
        for(auto to: adj[curr]) {
            if(to == from) continue;
            dfs(to, curr, adj, dp);
            pair<int, int> tmp = {dp[to][0].first + 1, to};
            if(tmp > dp[curr][0]) {
                dp[curr][1] = dp[curr][0];
                dp[curr][0] = tmp;
            } else if(tmp > dp[curr][1]) {
                dp[curr][1] = tmp;
            }
        }
    }
    void dfs2(int curr, int from, vector<vector<int>> &adj, vector<vector<pair<int, int>>> &dp) {
        for(auto to: adj[curr]) {
            if(to == from) continue;
            pair<int, int> tmp = {dp[curr][(dp[curr][0].second == to ? 1 : 0)].first + 1, curr};
            if(tmp > dp[to][0]) {
                dp[to][1] = dp[to][0];
                dp[to][0] = tmp;
            } else if(tmp > dp[to][1]) {
                dp[to][1] = tmp;
            }
            dfs2(to, curr, adj, dp);
        }
    }
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        ios_base::sync_with_stdio(false); cin.tie(0);
        int n = edges1.size() + 1, m = edges2.size() + 1;
        vector<vector<int>> adj1(n), adj2(m);
        vector<vector<pair<int, int>>> dp1(n, vector<pair<int, int>>(2, {0, -1})), dp2(m, vector<pair<int, int>>(2, {0, -1}));
        for(auto i: edges1) {
            adj1[i[0]].push_back(i[1]);
            adj1[i[1]].push_back(i[0]);
        }
        for(auto i: edges2) {
            adj2[i[0]].push_back(i[1]);
            adj2[i[1]].push_back(i[0]);
        }
        dfs(0, -1, adj1, dp1);
        dfs(0, -1, adj2, dp2);
        dfs2(0, -1, adj1, dp1);
        dfs2(0, -1, adj2, dp2);
        int ans = 0, ans1 = INT_MAX, ans2 = INT_MAX;
        for(int i = 0; i < n; i++) {
            // cout << i << ": ";
            // for(auto j: dp1[i]) {
            //     cout << "(" << j.first << ", " << j.second << ") ";
            // }
            // cout << "\n";
            ans = max(ans, dp1[i][0].first + (dp1[i].size() > 1 ? dp1[i][1].first : 0));
            ans1 = min(ans1, dp1[i][0].first);
        }
        for(int i = 0; i < m; i++) {
            // cout << i << ": ";
            // for(auto j: dp2[i]) {
            //     cout << "(" << j.first << ", " << j.second << ") ";
            // }
            // cout << "\n";
            ans = max(ans, dp2[i][0].first + (dp2[i].size() > 1 ? dp2[i][1].first : 0));
            ans2 = min(ans2, dp2[i][0].first);
        }
        return max(ans, ans1 + ans2 + 1);
    }
};