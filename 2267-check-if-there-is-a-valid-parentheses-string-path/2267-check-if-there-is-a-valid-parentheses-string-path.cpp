class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<bitset<105>>> dp(n, vector<bitset<105>>(m, 0));
        if(grid[0][0] == ')') return 0;
        dp[0][0][1] = 1;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                for(int k = 0, kk; k <= 100; k++) {
                    if(!dp[i][j][k]) continue;
                    if(i+1 < n) {
                        kk = k + (grid[i+1][j] == '(' ? 1 : -1);
                        if(0 <= kk && kk <= 100) dp[i+1][j][kk] = 1;
                    }
                    if(j+1 < m) {
                        kk = k + (grid[i][j+1] == '(' ? 1 : -1);
                        if(0 <= kk && kk <= 100) dp[i][j+1][kk] = 1;
                    }
                }
            }
        }
        return dp[n-1][m-1][0];
    }
};