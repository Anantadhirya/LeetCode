class Solution {
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        const int MOD = 1e9 + 7;
        int ans = 0;
        vector<int> dp(high+1, 0);
        dp[0] = 1;
        for(int i = 1; i <= high; i++) {
            if(i-zero >= 0) dp[i] += dp[i-zero];
            if(i-one >= 0) dp[i] += dp[i-one];
            dp[i] %= MOD;
        }
        for(int i = low; i <= high; i++) {
            (ans += dp[i]) %= MOD;
        }
        return ans;
    }
};