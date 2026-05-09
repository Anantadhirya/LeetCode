class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();
        vector<int> v(2*(n+m) - 4);
        for(int li = 0, ri = n-1, lj = 0, rj = m-1, x, sz; li <= ri && lj <= rj; li++, lj++, ri--, rj--) {
            sz = 0;
            for(int j = lj; j < rj; j++) v[sz++] = grid[li][j];
            for(int i = li; i < ri; i++) v[sz++] = grid[i][rj];
            for(int j = rj; j > lj; j--) v[sz++] = grid[ri][j];
            for(int i = ri; i > li; i--) v[sz++] = grid[i][lj];
            x = 0;
            for(int j = lj; j < rj; j++) grid[li][j] = v[((x++) + k) % sz];
            for(int i = li; i < ri; i++) grid[i][rj] = v[((x++) + k) % sz];
            for(int j = rj; j > lj; j--) grid[ri][j] = v[((x++) + k) % sz];
            for(int i = ri; i > li; i--) grid[i][lj] = v[((x++) + k) % sz];
        }
        return grid;
    }
};