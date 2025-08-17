class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        double dp[n+1], pref[n+1], ans = 0;
        dp[0] = 1;
        pref[0] = 1;
        for(int i = 1; i <= n; i++) {
            dp[i] = ((min(k-1, i-1) >= 0 ? pref[min(k-1, i-1)] : 0) - (min(k-1,i-maxPts-1) >= 0 ? pref[min(k-1, i-maxPts-1)] : 0)) / maxPts;
            pref[i] = dp[i] + pref[i-1];
        }
        for(int i = k; i <= n; i++) {
            ans += dp[i];
        }
        return ans;
    }
};