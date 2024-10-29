class Solution {
public:
    int maxMoves(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int ans = 0;
        vector<vector<int>> v(n, vector<int>(m, -1));
        for(int i = 0; i < n; i++) {
            v[i][0] = 0;
        }
        for(int j = 1; j < m; j++) {
            for(int i = 0; i < n; i++) {
                if(i-1 >= 0 && grid[i-1][j-1] < grid[i][j] && v[i-1][j-1] != -1) v[i][j] = max(v[i][j], v[i-1][j-1] + 1);
                if(grid[i][j-1] < grid[i][j] && v[i][j-1] != -1) v[i][j] = max(v[i][j], v[i][j-1] + 1);
                if(i+1 < n && grid[i+1][j-1] < grid[i][j] && v[i+1][j-1] != -1) v[i][j] = max(v[i][j], v[i+1][j-1] + 1);
                ans = max(ans, v[i][j]);
            }
        }
        return ans;
    }
};