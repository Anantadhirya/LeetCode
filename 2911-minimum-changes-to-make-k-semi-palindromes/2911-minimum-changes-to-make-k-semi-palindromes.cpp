class Solution {
public:
    int minimumChanges(string s, int k) {
        int n = s.size();
        const int inf = INT_MAX;
        vector<vector<vector<int>>> dp, pref;
        dp = pref = vector<vector<vector<int>>>(n, vector<vector<int>>(n, vector<int>(n, 0)));
        vector<vector<int>> cost(n, vector<int>(n, 0));
        vector<vector<int>> dp2(n+1, vector<int>(k+1, inf));
        for(int d = 1; d < n; d++) {
            for(int l = n-1; l >= 0; l--) {
                dp[d][l][0] = 0;
                for(int c = 1; l+d*c < n; c++) {
                    dp[d][l][c] = (s[l] != s[l+d*c]) + (c >= 2 ? dp[d][l+d][c-2] : 0);
                }
            }
            for(int c = 1; c < n; c++) {
                for(int l = 0; l < n; l++) {
                    pref[d][l][c] = (l-1 >= 0 ? pref[d][l-1][c] : 0) + dp[d][l][c];
                }
            }
        }
        for(int r = 0; r < n; r++) {
            cost[r][r] = 0;
            for(int l = r-1; l >= 0; l--) {
                cost[l][r] = inf;
                for(int d = 1, c; d < r-l+1; d++) {
                    if((r-l+1)%d != 0) continue;
                    c = (r-l+1)/d-1;
                    // cout << d << " " << l << ".." << l+d-1 << " " << c << "\n";
                    cost[l][r] = min(cost[l][r], pref[d][l+d-1][c] - (l-1 >= 0 ? pref[d][l-1][c] : 0));
                }
                // cout << l << " " << r << " -> " << s.substr(l, r-l+1) << " " << cost[l][r] << "\n";
            }
        }
        dp2[0][0] = 0;
        for(int r = 1; r <= n; r++) {
            for(int j = 1; j <= k; j++) {
                for(int l = r-1; l >= 1; l--) {
                    if(dp2[l-1][j-1] != inf) dp2[r][j] = min(dp2[r][j], dp2[l-1][j-1] + cost[l-1][r-1]);
                }
            }
        }
        return dp2[n][k];
    }
};