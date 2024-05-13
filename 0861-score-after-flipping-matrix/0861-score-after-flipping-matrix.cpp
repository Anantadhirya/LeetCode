class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int> cnt(m, 0);
        int ans = 0;
        for(int i = 0; i < n; i++) {
            if(!grid[i][0]) {
                for(int j = 0; j < m; j++) {
                    grid[i][j] ^= 1;
                }
            }
            for(int j = 0; j < m; j++) {
                cnt[j] += grid[i][j];
            }
        }
        for(int j = 0; j < m; j++) {
            cnt[j] = max(cnt[j], n - cnt[j]);
            ans = 2*ans + cnt[j];
        }
        return ans;
    }
};