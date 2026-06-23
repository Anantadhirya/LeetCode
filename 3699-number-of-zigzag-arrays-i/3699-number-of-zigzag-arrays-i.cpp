class Solution {
public:
    int zigZagArrays(int n, int l, int r) {
        const int MOD = 1e9 + 7;
        vector<vector<int>> dp(r+1, vector<int>(2, 0)), pref(r+1, vector<int>(2, 0));
        int ans = 0;
        for(int j = l; j <= r; j++) dp[j][0] = dp[j][1] = 1;

        for(int i = 2; i <= n; i++) {
            for(int j = 1; j <= r; j++) {
                for(int p = 0; p <= 1; p++) {
                    pref[j][p] = (pref[j-1][p] + dp[j][p]) % MOD;
                }
            }
            for(int j = l; j <= r; j++) {
                dp[j][0] = ((long long)pref[j-1][1] - pref[l-1][1] + MOD) % MOD;
                dp[j][1] = ((long long)pref[r][0] - pref[j][0] + MOD) % MOD;
            }
        }
        for(int j = l; j <= r; j++) {
            (ans += dp[j][0]) %= MOD;
            (ans += dp[j][1]) %= MOD;
        }
        return ans;
    }
};