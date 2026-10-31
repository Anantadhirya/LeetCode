class Solution {
public:
    int uniquePaths(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        const int MOD = 1e9 + 7;
        vector<vector<array<int, 2>>> ans(n, vector<array<int, 2>>(m, {0, 0}));
        ans[0][0][0] = 1;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(i-1 >= 0) {
                    (ans[i][j][0] += ans[i-1][j][1]) %= MOD;
                    if(grid[i-1][j] == 0) (ans[i][j][0] += ans[i-1][j][0]) %= MOD;
                }
                if(j-1 >= 0) {
                    (ans[i][j][1] += ans[i][j-1][0]) %= MOD;
                    if(grid[i][j-1] == 0) (ans[i][j][1] += ans[i][j-1][1]) %= MOD;
                }
            }
        }
        return (ans[n-1][m-1][0] + ans[n-1][m-1][1]) % MOD;
    }
};