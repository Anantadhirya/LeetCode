class Solution {
public:
    int numWays(vector<string>& words, string target) {
        ios_base::sync_with_stdio(false); cin.tie(0);
        const int MOD = 1e9 + 7;
        int n = target.size(), m = words[0].size();
        vector<vector<int>> cnt(m, vector<int>(26, 0));
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        for(const auto &s: words) {
            for(int i = 0; i < m; i++) {
                cnt[i][s[i]-'a']++;
            }
        }
        dp[n].assign(m+1, 1);
        for(int i = n-1, c; i >= 0; i--) {
            c = target[i]-'a';
            for(int j = m-1; j >= 0; j--) {
                dp[i][j] = ((long long)dp[i][j+1] + (long long)dp[i+1][j+1] * cnt[j][c]) % MOD;
            }
        }
        return dp[0][0];
    }
};