class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        const int inf = INT_MAX;
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> ans(n-k+1, vector<int>(m-k+1, inf));
        vector<int> v(k*k);
        for(int i = 0; i < n-k+1; i++) {
            for(int j = 0; j < m-k+1; j++) {
                for(int ii = 0; ii < k; ii++) {
                    for(int jj = 0; jj < k; jj++) {
                        v[ii*k+jj] = grid[i+ii][j+jj];
                    }
                }
                sort(v.begin(), v.end());
                for(int l = 1; l < k*k; l++) {
                    if(v[l] == v[l-1]) continue;
                    ans[i][j] = min(ans[i][j], v[l] - v[l-1]);
                }
                if(ans[i][j] == inf) ans[i][j] = 0;
            }
        }
        return ans;
    }
};