class Solution {
public:
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    void dfs(int i, int j, int &n, int &m, vector<vector<int>> &grid, int &cnt) {
        grid[i][j] = 0;
        cnt--;
        for(int d = 0, ii, jj; d < 4; d++) {
            ii = i + dx[d];
            jj = j + dy[d];
            if(0 <= ii && ii < n && 0 <= jj && jj < m && grid[ii][jj]) {
                dfs(ii, jj, n, m, grid, cnt);
            }
        }
    }
    bool connected(int &n, int &m, vector<vector<int>> grid) {
        int cnt = 0;
        pair<int, int> s;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                cnt += grid[i][j];
                if(grid[i][j]) s = {i, j};
            }
        }
        if(cnt == 0) return 0;
        dfs(s.first, s.second, n, m, grid, cnt);
        return cnt == 0;
    }
    int minDays(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        if(!connected(n, m, grid)) return 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j]) {
                    grid[i][j] = 0;
                    if(!connected(n, m, grid)) return 1;
                    grid[i][j] = 1;
                }
            }
        }
        return 2;
    }
};