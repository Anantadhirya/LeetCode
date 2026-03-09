class Solution {
public:
    int numberOfStableArrays(int zero, int one, int limit) {
        const int MOD = 1e9 + 7;
        vector<vector<vector<int>>> dp(zero+1, vector<vector<int>>(one+1, vector<int>(2, 0)));
        dp[0][0][0] = dp[0][0][1] = 1;
        for(int z = 0; z <= zero; z++) {
            for(int o = 0; o <= one; o++) {
                for(int c = 1; c <= limit; c++) {
                    if(z-c >= 0) (dp[z][o][0] += dp[z-c][o][1]) %= MOD;
                    if(o-c >= 0) (dp[z][o][1] += dp[z][o-c][0]) %= MOD;
                }
            }
        }
        return (dp[zero][one][0] + dp[zero][one][1]) % MOD;
    }
};