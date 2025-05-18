class Solution {
public:
    int colorTheGrid(int m, int n) {
        const int MOD = 1e9 + 7;
        int p4 = pow(3, m-1);
        int p5 = pow(3, m);
        vector<vector<int>> dp(m*n+1, vector<int>(p5+1, 0));
        int ans = 0;
        dp[0][0] = 1;
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                for(int mask = 0, t, l; mask < p5; mask++) {
                    t = (j == 1 ? -1 : mask % 3);
                    l = (i == 1 ? -1 : (mask/p4) % 3);
                    for(int k = 0; k < 3; k++) {
                        if(k == t || k == l) continue;
                        (dp[(i-1)*m + j][(mask*3)%p5 + k] += dp[(i-1)*m + j - 1][mask]) %= MOD;
                    }
                }
            }
        }
        for(int mask = 0; mask < p5; mask++) {
            (ans += dp[n*m][mask]) %= MOD;
        }
        return ans;
    }
};