class Solution {
public:
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    void dfs(int i, int j, int &n, int &m, vector<vector<int>> &grid1, vector<vector<int>> &grid2, vector<vector<bool>> &vis, bool &valid) {
        if(vis[i][j]) return;
        if(!grid1[i][j]) valid = 0;
        vis[i][j] = 1;
        for(int d = 0, ii, jj; d < 4; d++) {
            ii = i + dx[d];
            jj = j + dy[d];
            if(0 <= ii && ii < n && 0 <= jj && jj < m && grid2[ii][jj] && !vis[ii][jj]) {
                dfs(ii, jj, n, m, grid1, grid2, vis, valid);
            }
        }
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        ios_base::sync_with_stdio(false); cin.tie(0);
        int n = grid2.size(), m = grid2[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, 0));
        bool valid;
        int ans = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid2[i][j] && !vis[i][j]) {
                    valid = 1;
                    dfs(i, j, n, m, grid1, grid2, vis, valid);
                    ans += valid;
                }
            }
        }
        return ans;
    }
};