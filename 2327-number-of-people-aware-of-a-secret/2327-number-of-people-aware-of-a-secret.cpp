class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        const int MOD = 1e9 + 7;
        vector<int> dp(n+1, 0);
        for(int i = n-1; i >= 0; i--) {
            (dp[i] = (i+1+forget > n) + dp[i+1]) %= MOD;
            (dp[i] += (((i+delay < n ? dp[i+delay] : 0) - (i+forget < n ? dp[i+forget] : 0)) + MOD) % MOD) %= MOD;
        }
        return (dp[0] - dp[1] + MOD) % MOD;
    }
};