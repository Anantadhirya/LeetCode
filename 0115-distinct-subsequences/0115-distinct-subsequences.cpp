class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.size(), m = t.size();
        vector<unsigned long long> dp(m+1, 0);
        dp[0] = 1;
        for(int i = 0; i < n; i++) {
            for(int j = m; j >= 1; j--) {
                if(t[j-1] == s[i]) dp[j] += dp[j-1];
            }
        }
        return dp[m];
    }
};