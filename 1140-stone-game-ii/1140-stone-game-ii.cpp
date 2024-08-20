class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        const int inf = INT_MIN;
        int n = piles.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, inf));
        int ans = inf;
        vector<int> suff(n+1, 0);
        for(int i = n-1; i >= 0; i--) {
            suff[i] = suff[i+1] + piles[i];
        }
        dp[n].assign(n+1, 0);
        for(int i = n-1; i >= 0; i--) {
            for(int m = 1; m <= n; m++) {
                for(int j = 1, tmp = 0; j <= 2*m && i+j <= n; j++) {
                    tmp += piles[i+j-1];
                    if(dp[i+j][max(j, m)] != inf) dp[i][m] = max(dp[i][m], tmp + suff[i+j] - dp[i+j][max(j, m)]);
                }
            }
        }
        return dp[0][1];
    }
};