class Solution {
public:
    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();
        vector<vector<int>> dp(n, vector<int>(n));
        for(int r = 0; r < n; r++) {
            for(int l = r-2; l >= 0; l--) {
                dp[l][r] = INT_MAX;
                for(int k = l+1; k <= r-1; k++) {
                    dp[l][r] = min(dp[l][r], values[l] * values[r] * values[k] + dp[l][k] + dp[k][r]);
                }
            }
        }
        return dp[0][n-1];
    }
};