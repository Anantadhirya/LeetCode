class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        for(int c = y; c < y+k; c++) {
            for(int l = x, r = x+k-1; l < r; l++, r--) swap(grid[l][c], grid[r][c]);
        }
        return grid;
    }
};