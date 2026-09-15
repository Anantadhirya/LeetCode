class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n = s.size();
        vector<int> dp(n, 0);
        vector<vector<bool>> valid(n, vector<bool>(n, 0));
        for(int r = 0; r < n; r++) {
            if(r-1 >= 0) dp[r] = max(dp[r], dp[r-1]);
            for(int l = r; l >= 0; l--) {
                valid[l][r] = (s[l] == s[r]) && (l+1 <= r-1 ? valid[l+1][r-1] : 1);
                if(valid[l][r] && r-l+1 >= k) {
                    dp[r] = max(dp[r], 1 + (l-1 >= 0 ? dp[l-1] : 0));
                }
            }
        }
        return dp[n-1];
    }
};