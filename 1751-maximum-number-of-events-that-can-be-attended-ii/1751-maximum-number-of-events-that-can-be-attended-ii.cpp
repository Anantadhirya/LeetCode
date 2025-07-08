const auto init = []() { ios_base::sync_with_stdio(false); cin.tie(0); return nullptr; }();

class Solution {
public:
    int maxValue(vector<vector<int>>& events, int k) {
        int n = events.size();
        int ans = 0;
        vector<pair<int, pair<int, int>>> v;
        for(const auto &i: events) {
            v.push_back({i[1], {i[0], i[2]}});
        }
        sort(v.begin(), v.end());
        vector<vector<int>> dp(n+1, vector<int>(k+1, -1));
        dp[0][0] = 0;
        for(int i = 1, idx; i <= n; i++) {
            dp[i][0] = 0;
            idx = lower_bound(v.begin(), v.end(), make_pair(v[i-1].second.first, make_pair(-1, -1))) - v.begin();
            for(int j = 1; j <= k; j++) {
                dp[i][j] = dp[i-1][j];
                if(dp[idx][j-1] != -1) dp[i][j] = max(dp[i][j], v[i-1].second.second + dp[idx][j-1]);
            }
        }
        for(int j = 0; j <= k; j++) ans = max(ans, dp[n][j]);
        return ans;
    }
};