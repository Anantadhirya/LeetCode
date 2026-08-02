class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for(int r = 0; r < n; r++) {
            dp[r][r] = piles[r];
            for(int l = r-1; l >= 0; l--) {
                dp[l][r] = max(piles[l] - dp[l+1][r], piles[r] - dp[l][r-1]);
            }
        }
        return dp[0][n-1] >= 0;
    }
};