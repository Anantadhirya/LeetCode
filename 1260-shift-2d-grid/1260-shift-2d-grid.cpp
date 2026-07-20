class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();
        vector<int> v(n*m);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                v[i*m+j] = grid[i][j];
            }
        }
        k %= n*m;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                grid[i][j] = v[(i*m+j-k+n*m)%(n*m)];
            }
        }
        return grid;
    }
};