class Solution {
public:
    const int dx[4] = {1, -1, 0, 0};
    const int dy[4] = {0, 0, 1, -1};
    int dp(int i, int mask, int &n, int &m, vector<vector<int>> &memo, vector<vector<int>> &grid) {
        int r = i/m, c = i%m;
        if(grid[r][c] == 2 && mask == 0) return 1;
        if(memo[i][mask] != -1) return memo[i][mask];
        int &ret = memo[i][mask];
        ret = 0;
        for(int d = 0, ii, jj; d < 4; d++) {
            ii = r + dx[d];
            jj = c + dy[d];
            if(0 <= ii && ii < n && 0 <= jj && jj < m && grid[ii][jj] != -1 && ((mask>>(ii*m+jj))&1)) {
                ret += dp(ii*m+jj, mask-(1<<(ii*m+jj)), n, m, memo, grid);
            }
        }
        return ret;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int sz = n*m;
        int mask = (1<<sz) - 1;
        int start;
        vector<vector<int>> memo(sz, vector<int>(mask+1, -1));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1) {
                    start = m*i + j;
                } else if(grid[i][j] == -1) {
                    mask -= (1<<(m*i+j));
                }
            }
        }
        return dp(start, mask - (1<<start), n, m, memo, grid);
    }
};