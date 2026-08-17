class Solution {
public:
    int stoneGameV(vector<int>& s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for(int r = 0, sm; r < n; r++) {
            dp[r][r] = 0;
            sm = s[r];
            for(int l = r-1; l >= 0; l--) {
                sm += s[l];
                for(int k = l, sml = 0, smr; k+1 <= r; k++) {
                    sml += s[k];
                    smr = sm - sml;
                    if(sml >= smr) {
                        dp[l][r] = max(dp[l][r], smr + dp[k+1][r]);
                    }
                    if(sml <= smr) {
                        dp[l][r] = max(dp[l][r], sml + dp[l][k]);
                    }
                }
            }
        }
        return dp[0][n-1];
    }
};