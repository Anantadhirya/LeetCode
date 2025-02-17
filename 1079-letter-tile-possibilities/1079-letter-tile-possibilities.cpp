class Solution {
public:
    int numTilePossibilities(string tiles) {
        int n = tiles.size();
        vector<int> dp(n+1, 0), cnt(26, 0);
        dp[0] = 1;
        vector<vector<int>> comb(n+1, vector<int>(n+1, 0));
        for(int i = 0; i <= n; i++) {
            comb[i][0] = 1;
            for(int j = 1; j <= i; j++) {
                comb[i][j] = comb[i-1][j] + comb[i-1][j-1];
            }
        }
        for(const auto &i: tiles) {
            cnt[i-'A']++;
        }
        for(int i = 0; i < 26; i++) {
            for(int j = n; j >= 1; j--) {
                for(int c = min(j, cnt[i]); c >= 1; c--) {
                    dp[j] += dp[j-c] * comb[j][c];
                }
            }
        }
        for(int i = 2; i <= n; i++) {
            dp[i] += dp[i-1];
        }
        return dp[n];
    }
};