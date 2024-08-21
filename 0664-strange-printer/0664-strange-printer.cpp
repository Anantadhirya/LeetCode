class Solution {
public:
    int strangePrinter(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for(int r = 0, fi, lst; r < n; r++) {
            dp[r][r] = 1;
            for(int l = r-1; l >= 0; l--) {
                dp[l][r] = 1 + dp[l+1][r];
                for(int i = l+1; i <= r; i++) {
                    if(s[l] == s[i]) {
                        dp[l][r] = min(dp[l][r], dp[l][i-1] + (i+1<=r ? dp[i+1][r] : 0));
                    }
                }
            }
        }
        return dp[0][n-1];
    }
};