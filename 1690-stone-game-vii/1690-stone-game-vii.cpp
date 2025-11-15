class Solution {
public:
    int stoneGameVII(vector<int>& stones) {
        int n = stones.size();
        vector<vector<int>> dp(n, vector<int>(n, INT_MIN));
        vector<int> suff(n+1, 0);
        for(int i = n-1; i >= 0; i--) {
            suff[i] = suff[i+1] + stones[i];
        }
        for(int r = 0; r < n; r++) {
            dp[r][r] = 0;
            for(int l = r-1; l >= 0; l--) {
                dp[l][r] = max(suff[l+1] - suff[r+1] - dp[l+1][r], suff[l] - suff[r] - dp[l][r-1]);
            }
        }
        return dp[0][n-1];
    }
};