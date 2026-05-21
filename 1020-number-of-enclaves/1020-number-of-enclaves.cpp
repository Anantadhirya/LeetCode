int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
class Solution {
public:
    void dfs(int i, int j, int &n, int &m, vector<vector<int>> &grid) {
        if(grid[i][j] == 0) return;
        grid[i][j] = 0;
        for(int d = 0, ii, jj; d < 4; d++) {
            ii = i + dx[d];
            jj = j + dy[d];
            if(0 <= ii && ii < n && 0 <= jj && jj < m) dfs(ii, jj, n, m, grid);
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int ans = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(i == 0 || i == n-1 || j == 0 || j == m-1) dfs(i, j, n, m, grid);
            }
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                ans += grid[i][j];
            }
        }
        return ans;
    }
};