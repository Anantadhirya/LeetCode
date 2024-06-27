class Solution {
public:
    bool divisorGame(int n) {
        ios_base::sync_with_stdio(false); cin.tie(0);
        vector<bool> dp(n+1, 0);
        for(int i = 1; i <= n; i++) {
            for(int x = 1; x < i; x++) {
                if(i % x == 0 && !dp[i-x]) {
                    dp[i] = 1;
                    break;
                }
            }
        }
        return dp[n];
    }
};