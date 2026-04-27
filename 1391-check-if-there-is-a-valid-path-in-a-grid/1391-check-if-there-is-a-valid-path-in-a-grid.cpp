class Solution {
public:
    vector<pair<int, int>> adj[7] = {
        {},
        {{0, 1}, {0, -1}},
        {{1, 0}, {-1, 0}},
        {{0, -1}, {1, 0}},
        {{0, 1}, {1, 0}},
        {{-1, 0}, {0, -1}},
        {{-1, 0}, {0, 1}},
    };
    int ii, jj;
    void dfs(int i, int j, int &n, int &m, vector<vector<int>> &grid, vector<vector<bool>> &vis) {
        if(vis[i][j]) return;
        vis[i][j] = 1;
        for(auto [dx, dy]: adj[grid[i][j]]) {
            ii = i+dx;
            jj = j+dy;
            if(0 <= ii && ii < n && 0 <= jj && jj < m) {
                if(adj[grid[ii][jj]][0] != make_pair(-dx, -dy) && adj[grid[ii][jj]][1] != make_pair(-dx, -dy)) continue;
                dfs(ii, jj, n, m, grid, vis);
            }
        }
    }
    bool hasValidPath(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, 0));
        dfs(0, 0, n, m, grid, vis);
        return vis[n-1][m-1];
    }
};