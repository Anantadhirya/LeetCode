class Solution {
public:
    int numberOfStableArrays(int zero, int one, int limit) {
        const int MOD = 1e9 + 7;
        vector<vector<vector<int>>> dp(zero+1, vector<vector<int>>(one+1, vector<int>(2, 0)));
        vector<vector<int>> prefz, prefo;
        prefz = prefo = vector<vector<int>>(zero+1, vector<int>(one+1, 0));
        dp[0][0][0] = dp[0][0][1] = 1;
        for(int z = 0; z <= zero; z++) {
            for(int o = 0; o <= one; o++) {
                // for(int i = 1; i <= limit; i++) {
                //     if(z-i >= 0) (dp[z][o][0] += dp[z-i][o][1]) %= MOD;
                //     if(o-i >= 0) (dp[z][o][1] += dp[z][o-i][0]) %= MOD;
                // }
                dp[z][o][0] += ((z-1 >= 0 ? prefz[z-1][o] : 0) - (z-limit-1 >= 0 ? prefz[z-limit-1][o] : 0) + MOD) % MOD;
                dp[z][o][1] += ((o-1 >= 0 ? prefo[z][o-1] : 0) - (o-limit-1 >= 0 ? prefo[z][o-limit-1] : 0) + MOD) % MOD;
                prefz[z][o] = (dp[z][o][1] + (z-1 >= 0 ? prefz[z-1][o] : 0)) % MOD;
                prefo[z][o] = (dp[z][o][0] + (o-1 >= 0 ? prefo[z][o-1] : 0)) % MOD;
            }
        }
        return (dp[zero][one][0] + dp[zero][one][1]) % MOD;
    }
};