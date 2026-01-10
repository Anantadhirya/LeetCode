const auto init = []() { ios_base::sync_with_stdio(false); cin.tie(NULL); return nullptr; }();

class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, INT_MAX));
        dp[0][0] = 0;
        for(int i = 0; i <= n; i++) {
            for(int j = 0; j <= m; j++) {
                if(i-1 >= 0) dp[i][j] = min(dp[i][j], dp[i-1][j] + s1[i-1]);
                if(j-1 >= 0) dp[i][j] = min(dp[i][j], dp[i][j-1] + s2[j-1]);
                if(i-1 >= 0 && j-1 >= 0 && s1[i-1] == s2[j-1]) dp[i][j] = min(dp[i][j], dp[i-1][j-1]);
            }
        }
        return dp[n][m];
    }
};