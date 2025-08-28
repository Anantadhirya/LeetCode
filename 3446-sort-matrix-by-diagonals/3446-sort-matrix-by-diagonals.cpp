class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                for(int ii = i-1, jj = j-1; ii >= 0 && jj >= 0; ii--, jj--) {
                    if(i >= j) {
                        if(grid[ii][jj] < grid[ii+1][jj+1]) swap(grid[ii][jj], grid[ii+1][jj+1]);
                        else break;
                    } else {
                        if(grid[ii][jj] > grid[ii+1][jj+1]) swap(grid[ii][jj], grid[ii+1][jj+1]);
                        else break;
                    }
                }
            }
        }
        return grid;
    }
};