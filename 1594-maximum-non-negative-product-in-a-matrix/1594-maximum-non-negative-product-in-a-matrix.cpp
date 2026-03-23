class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        const long long inf = LLONG_MAX;
        const long long MOD = 1e9 + 7;
        vector<vector<vector<long long>>> dp(n, vector<vector<long long>>(m, {inf, -inf}));
        dp[0][0] = {grid[0][0], grid[0][0]};
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(i-1 >= 0) {
                    dp[i][j][0] = min(dp[i][j][0], min(dp[i-1][j][0]*grid[i][j], dp[i-1][j][1]*grid[i][j]));
                    dp[i][j][1] = max(dp[i][j][1], max(dp[i-1][j][0]*grid[i][j], dp[i-1][j][1]*grid[i][j]));
                }
                if(j-1 >= 0) {
                    dp[i][j][0] = min(dp[i][j][0], min(dp[i][j-1][0]*grid[i][j], dp[i][j-1][1]*grid[i][j]));
                    dp[i][j][1] = max(dp[i][j][1], max(dp[i][j-1][0]*grid[i][j], dp[i][j-1][1]*grid[i][j]));
                }
            }
        }
        return dp[n-1][m-1][1] >= 0 ? dp[n-1][m-1][1] % MOD : -1;
    }
};