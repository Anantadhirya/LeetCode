class Solution {
public:
    const int dx[4] = {1, -1, 0, 0};
    const int dy[4] = {0, 0, 1, -1};
    void dfs(int i, int j, int &n, int &m, vector<vector<int>> &grid, int &ans, int &zeros) {
        if(grid[i][j] == 2) {
            ans += (zeros == 0);
            return;
        }
        grid[i][j] = -1;
        zeros--;
        for(int d = 0, ii, jj; d < 4; d++) {
            ii = i + dx[d];
            jj = j + dy[d];
            if(0 <= ii && ii < n && 0 <= jj && jj < m && grid[ii][jj] != -1) {
                dfs(ii, jj, n, m, grid, ans, zeros);
            }
        }
        grid[i][j] = 0;
        zeros++;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int ans = 0, si, sj, zeros = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1) si = i, sj = j, grid[i][j] = 0, zeros++;
                else if(grid[i][j] == 0) zeros++;
            }
        }
        dfs(si, sj, n, m, grid, ans, zeros);
        return ans;
    }
};