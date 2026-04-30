class Solution {
public:
    void chmax(int &a, int b) {
        a = max(a, b);
    }
    int maxPathScore(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(k+2, -1)));
        int ans = -1;
        dp[0][0][0] = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                for(int c = 0; c <= k; c++) {
                    if(dp[i][j][c] == -1) continue;
                    if(i+1 < n) chmax(dp[i+1][j][c+(grid[i+1][j] > 0)], dp[i][j][c] + grid[i+1][j]);
                    if(j+1 < m) chmax(dp[i][j+1][c+(grid[i][j+1] > 0)], dp[i][j][c] + grid[i][j+1]);
                }
            }
        }
        for(int c = 0; c <= k; c++) {
            chmax(ans, dp[n-1][m-1][c]);
        }
        return ans;
    }
};