class Solution {
public:
    int numberOfWays(int n, int x) {
        const int MOD = 1e9 + 7;
        int k = ceil(pow(n, 1.0/x)) + 1;
        vector<vector<int>> dp(n+1, vector<int>(k+1, 0));
        dp[0].assign(k+1, 1);
        for(int i = 1; i <= n; i++) {
            for(int j = 1, p; j <= k; j++) {
                dp[i][j] = dp[i][j-1];
                p = pow(j, x);
                if(p <= i) (dp[i][j] += dp[i-p][j-1]) %= MOD;
            }
        }
        return dp[n][k];
    }
};