class Solution {
public:
    long long maximumProfit(vector<int>& prices, int k) {
        const long long inf = LLONG_MAX;
        int n = prices.size();
        vector<vector<long long>> dp(k+1, vector<long long>(3, -inf));
        long long ans = 0;
        dp[0][0] = 0;
        for(int i = 0; i < n; i++) {
            for(int j = k; j >= 0; j--) {
                if(dp[j][0] != -inf) {
                    dp[j][1] = max(dp[j][1], dp[j][0] - prices[i]);
                    dp[j][2] = max(dp[j][2], dp[j][0] + prices[i]);
                }
                if(j-1 >= 0) {
                    if(dp[j-1][1] != -inf) dp[j][0] = max(dp[j][0], dp[j-1][1] + prices[i]);
                    if(dp[j-1][2] != -inf) dp[j][0] = max(dp[j][0], dp[j-1][2] - prices[i]);
                }
            }
        }
        for(int j = 0; j <= k; j++) ans = max(ans, dp[j][0]);
        return ans;
    }
};