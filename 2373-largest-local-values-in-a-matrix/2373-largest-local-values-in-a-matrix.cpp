class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> ans(n-2, vector<int>(n-2, 0));
        for(int i = 0; i < n-2; i++) {
            for(int j = 0; j < n-2; j++) {
                for(int ii = 0; ii < 3; ii++) {
                    for(int jj = 0; jj < 3; jj++) {
                        ans[i][j] = max(ans[i][j], grid[i+ii][j+jj]);
                    }
                }
            }
        }
        return ans;
    }
};