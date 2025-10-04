const int MOD = 1e9 + 7;

class Solution {
public:
    int numberWays(vector<vector<int>>& hats) {
        int n = hats.size();
        vector<vector<int>> dp(41, vector<int>(1<<n, 0));
        bitset<41> b[n];
        for(int i = 0; i < n; i++) {
            for(auto j: hats[i]) {
                b[i][j] = 1;
            }
        }
        dp[0][0] = 1;
        for(int i = 1; i <= 40; i++) {
            for(int mask = 0; mask < (1<<n); mask++) {
                (dp[i][mask] += dp[i-1][mask]) %= MOD;
                for(int j = 0; j < n; j++) {
                    if(((mask>>j)&1) == 0) continue;
                    if(!b[j][i]) continue;
                    (dp[i][mask] += dp[i-1][mask-(1<<j)]) %= MOD;
                }
            }
        }
        return dp[40][(1<<n)-1];
    }
};