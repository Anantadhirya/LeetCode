class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int mni = n, mnj = m, mxi = -1, mxj = -1;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j]) {
                    mni = min(mni, i);
                    mxi = max(mxi, i);
                    mnj = min(mnj, j);
                    mxj = max(mxj, j);
                }
            }
        }
        return (mxi - mni + 1) * (mxj - mnj + 1);
    }
};