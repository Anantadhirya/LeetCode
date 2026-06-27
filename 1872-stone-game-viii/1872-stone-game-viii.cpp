class Solution {
public:
    int stoneGameVIII(vector<int>& stones) {
        int n = stones.size();
        vector<int> dp(n+1, INT_MIN);
        dp[n] = 0;

        for(int i = 1; i < n; i++) {
            stones[i] += stones[i-1];
        }

        int mx = INT_MIN;
        for(int i = n-1; i >= 1; i--) {
            // for(int j = i; j < n; j++) {
            //     dp[i] = max(dp[i], stones[j] - dp[j+1]);
            // }
            mx = max(mx, stones[i] - dp[i+1]);
            dp[i] = mx;
        }
        
        return dp[1];
    }
};