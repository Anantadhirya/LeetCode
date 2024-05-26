class Solution {
public:
    int checkRecord(int n) {
        ios_base::sync_with_stdio(false); cin.tie(0);
        const long long MOD = 1e9 + 7;
        vector<vector<vector<long long>>> dp(n+1, vector<vector<long long>>(2, vector<long long>(3, 0)));
        long long ans = 0;
        dp[0][0][0] = 1;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < 2; j++) {
                for(int k = 0; k < 3; k++) {
                    // Case P
                    (dp[i+1][j][0] += dp[i][j][k]) %= MOD;
                    
                    // Case A
                    if(j == 0) {
                        (dp[i+1][j+1][0] += dp[i][j][k]) %= MOD;
                    }
                    
                    // Case L
                    if(k != 2) {
                        (dp[i+1][j][k+1] += dp[i][j][k]) %= MOD;
                    }
                }
            }
        }
        for(int j = 0; j < 2; j++) {
            for(int k = 0; k < 3; k++) {
                (ans += dp[n][j][k]) %= MOD;
            }
        }
        return ans;
    }
};