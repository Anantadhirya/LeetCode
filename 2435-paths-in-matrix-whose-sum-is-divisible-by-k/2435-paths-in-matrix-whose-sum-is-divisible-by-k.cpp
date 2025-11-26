class Solution {
public:
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        const int MOD = 1e9 + 7;
        int n = grid.size(), m = grid[0].size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(k, 0)));
        dp[0][0][grid[0][0] % k] = 1;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                for(int p = 0; p < k; p++) {
                    if(i+1 < n) (dp[i+1][j][(p + grid[i+1][j]) % k] += dp[i][j][p]) %= MOD;
                    if(j+1 < m) (dp[i][j+1][(p + grid[i][j+1]) % k] += dp[i][j][p]) %= MOD;
                }
            }
        }
        return dp[n-1][m-1][0];
    }
};