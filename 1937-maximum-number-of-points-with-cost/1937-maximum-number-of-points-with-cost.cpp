class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int n = points.size(), m = points[0].size();
        vector<vector<long long>> dp(n, vector<long long>(m, 0));
        vector<vector<long long>> pref = dp, suff = dp;
        long long ans = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                dp[i][j] = points[i][j] + (i ? max(pref[i-1][j] - j, (j+1 < m ? suff[i-1][j+1] + j : 0)) : 0);
            }
            pref[i][0] = dp[i][0] + 0;
            for(int j = 1; j < m; j++) {
                pref[i][j] = max(pref[i][j-1], dp[i][j] + j);
            }
            suff[i][m-1] = dp[i][m-1] - (m-1);
            for(int j = m-2; j >= 0; j--) {
                suff[i][j] = max(suff[i][j+1], dp[i][j] - j);
            }
        }
        for(int j = 0; j < m; j++) {
            ans = max(ans, dp.back()[j]);
        }
        return ans;
    }
};