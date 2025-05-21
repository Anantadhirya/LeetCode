class Solution {
public:
    int countPathsWithXorValue(vector<vector<int>>& grid, int k) {
        const int MX = 16;
        const int MOD = 1e9 + 7;
        int n = grid.size(), m = grid[0].size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(MX, 0)));
        dp[0][0][grid[0][0]] = 1;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                for(int x = 0; x < MX; x++) {
                    if(i+1 < n) (dp[i+1][j][x^grid[i+1][j]] += dp[i][j][x]) %= MOD;
                    if(j+1 < m) (dp[i][j+1][x^grid[i][j+1]] += dp[i][j][x]) %= MOD;
                }
            }
        }
        return dp[n-1][m-1][k];
    }
};