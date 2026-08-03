class Solution {
public:
    string stoneGameIII(vector<int>& s) {
        int n = s.size();
        vector<int> dp(n+1, 0);
        for(int i = n-1; i >= 0; i--) {
            dp[i] = s[i] - dp[i+1];
            if(i+1 < n) dp[i] = max(dp[i], s[i] + s[i+1] - dp[i+2]);
            if(i+2 < n) dp[i] = max(dp[i], s[i] + s[i+1] + s[i+2] - dp[i+3]);
        }
        return (dp[0] == 0 ? "Tie" : dp[0] > 0 ? "Alice" : "Bob");
    }
};