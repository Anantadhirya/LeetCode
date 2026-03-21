class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        for(size_t c = y; c < y+k; c++) {
            for(size_t l = x, r = x+k-1; l < r; l++, r--) swap(grid[l][c], grid[r][c]);
        }
        return move(grid);
    }
};