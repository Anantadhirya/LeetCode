const auto init = []() { ios_base::sync_with_stdio(false); cin.tie(0); return nullptr; }();

class Solution {
public:
    double soupServings(int n) {
        if(n >= 5000) return 1.0;
        int k = (n+24)/25;
        vector<vector<double>> dp(k+1, vector<double>(k+1, 0));
        dp[0][0] = 0.5;
        for(int b = 1; b <= k; b++) {
            dp[0][b] = 1;
            for(int a = 1; a <= k; a++) {
                dp[a][b] = (dp[max(0,a-4)][b] + dp[max(0,a-3)][max(0,b-1)] + dp[max(0,a-2)][max(0,b-2)] + dp[max(0,a-1)][max(0,b-3)])/4;
            }
        }
        return dp[k][k];
    }
};