class Solution {
public:
    int minSteps(int n) {
        ios_base::sync_with_stdio(false); cin.tie(0);
        vector<int> dp(n+1, INT_MAX);
        dp[1] = 0;
        for(int i = 2; i <= n; i++) {
            for(int j = 1; j < i; j++) {
                if(i % j == 0) {
                    dp[i] = min(dp[i], dp[j] + i/j);
                }
            }
        }
        return dp[n];
    }
};