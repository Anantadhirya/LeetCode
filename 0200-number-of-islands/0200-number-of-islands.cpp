int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

class Solution {
public:
    void dfs(int i, int j, int n, int m, vector<vector<char>> &grid) {
        grid[i][j] = '0';
        for(int d = 0, ii, jj; d < 4; d++) {
            ii = i + dx[d];
            jj = j + dy[d];
            if(0 <= ii && ii < n && 0 <= jj && jj < m && grid[ii][jj] == '1') {
                dfs(ii, jj, n, m, grid);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        ios_base::sync_with_stdio(false); cin.tie(0);
        int n = grid.size(), m = grid[0].size(), ans = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == '1') {
                    ans++;
                    dfs(i, j, n, m, grid);
                }
            }
        }
        return ans;
    }
};