class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int n = grid[0].size();
        if(n == 1) return 0;
        vector<vector<long long>> pref(2, vector<long long>(n+2, 0));
        for(int i = 0; i < 2; i++) {
            for(int j = 1; j <= n; j++) {
                pref[i][j] = pref[i][j-1] + grid[i][j-1];
            }
        }
        long long ans = LLONG_MAX;
        for(int i = 1; i <= n; i++) {
            ans = min(ans, max(pref[0][n] - pref[0][i], pref[1][i-1]));
        }
        return ans;
    }
};