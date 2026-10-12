class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        ios_base::sync_with_stdio(false); cin.tie(0);
        int ans = 0, n = grid.size(), m = grid[0].size();
        for(int i = 0; i < n; i++) {
            ans += grid[i][0] + grid[i][m-1];
            for(int j = 0; j+1 < m; j++) {
                ans += grid[i][j] != grid[i][j+1];
            }
        }
        for(int j = 0; j < m; j++) {
            ans += grid[0][j] + grid[n-1][j];
            for(int i = 0; i+1 < n; i++) {
                ans += grid[i][j] != grid[i+1][j];
            }
        }
        return ans;
    }
};