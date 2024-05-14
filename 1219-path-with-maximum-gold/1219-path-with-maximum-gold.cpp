const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};
class Solution {
public:
    void dfs(int i, int j, int &n, int &m, vector<vector<int>> &grid, vector<vector<bool>> &vis, int &tmp, int &ans) {
        if(i < 0 || i >= n || j < 0 || j >= m || grid[i][j] == 0 || vis[i][j]) return;
        vis[i][j] = 1;
        tmp += grid[i][j];
        ans = max(ans, tmp);
        for(int d = 0; d < 4; d++) {
            dfs(i+dx[d], j+dy[d], n, m, grid, vis, tmp, ans);
        }
        tmp -= grid[i][j];
        vis[i][j] = 0;
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        ios_base::sync_with_stdio(false); cin.tie(0);
        int n = grid.size(), m = grid[0].size();
        int ans = 0, tmp = 0;
        vector<vector<bool>> vis(n, vector<bool>(m, 0));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                dfs(i, j, n, m, grid, vis, tmp, ans);
            }
        }
        return ans;
    }
};