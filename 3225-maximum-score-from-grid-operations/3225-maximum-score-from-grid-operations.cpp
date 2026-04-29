class Solution {
public:
    void chmax(long long &a, long long b) {
        a = max(a, b);
    }
    long long maximumScore(vector<vector<int>>& grid) {
        const long long inf = LLONG_MAX;
        int n = grid.size();
        vector<vector<vector<long long>>> dp(n+1, vector<vector<long long>>(n+1, vector<long long>(n+1, -inf)));
        vector<vector<long long>> pref(n+1, vector<long long>(n+1, 0)), prefm, suffm;
        prefm = suffm = vector<vector<long long>>(n+1, vector<long long>(n+1, 0));
        long long ans = -1;
        for(int j = 1; j <= n; j++) {
            for(int i = 1; i <= n; i++) {
                pref[j][i] = pref[j][i-1] + grid[i-1][j-1];
            }
        }
        dp[0][0][0] = 0;
        for(int i = 1; i <= n; i++) {
            for(int prev = 0; prev <= n; prev++) {
                for(int j = n; j >= 0; j--) {
                    suffm[prev][j] = max((j+1 <= n ? suffm[prev][j+1] : -inf), (dp[i-1][prev][j] == -inf ? -inf : dp[i-1][prev][j]));
                }
                for(int j = 0; j <= n; j++) {
                    prefm[prev][j] = max((j-1 >= 0 ? prefm[prev][j-1] : -inf), (dp[i-1][prev][j] == -inf ? -inf : dp[i-1][prev][j] - pref[i-1][max(j, prev)]));
                }
            }
            for(int cur = 0; cur <= n; cur++) {
                for(int prev = 0; prev <= n; prev++) {
                    // for(int k = 0; k <= n; k++) {
                    //     if(dp[i-1][prev][k] == -inf) continue;
                    //     if(cur <= prev) chmax(dp[i][cur][prev], dp[i-1][prev][k] + pref[i][prev] - pref[i][cur]);
                    //     else {
                    //         if(k <= cur) chmax(dp[i][cur][prev], dp[i-1][prev][k] + pref[i-1][cur] - pref[i-1][max(k, prev)]);
                    //         else chmax(dp[i][cur][prev], dp[i-1][prev][k]);
                    //     }
                    // }
                    if(cur <= prev) {
                        dp[i][cur][prev] = (suffm[prev][0] == -inf ? -inf : suffm[prev][0] + pref[i][prev] - pref[i][cur]);
                    } else {
                        // k <= cur
                        chmax(dp[i][cur][prev], prefm[prev][cur] + pref[i-1][cur]);
                        // k >= cur
                        chmax(dp[i][cur][prev], suffm[prev][cur]);
                    }
                }
            }
        }
        for(int cur = 0; cur <= n; cur++) {
            for(int prev = 0; prev <= n; prev++) {
                chmax(ans, dp[n][cur][prev]);
            }
        }
        return ans;
    }
};