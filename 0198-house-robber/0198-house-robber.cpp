class Solution {
public:
    int rob(vector<int> a) {
        int n = a.size();
        vector<int> dp(n + 1);
        dp[0] = 0;
        dp[1] = a[0];
        for (int i = 2; i <= n; i++) {
            dp[i] = max(dp[i - 1], a[i - 1] + dp[i - 2]);
        }
        return dp[n];
        
            
            
            



















    };
};