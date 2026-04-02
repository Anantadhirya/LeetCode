class Solution {
public:
    int maximumAmount(vector<vector<int>>& coins) {
        int n = coins.size(), m = coins[0].size();
        const int inf = INT_MAX;
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(3, -inf)));
        int tmp;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                for(int p = 0; p <= 2; p++) {
                    tmp = -inf;
                    if(i-1 >= 0) tmp = max(tmp, dp[i-1][j][p]);
                    if(j-1 >= 0) tmp = max(tmp, dp[i][j-1][p]);
                    if(tmp == -inf) tmp = 0;
                    dp[i][j][p] = tmp + coins[i][j];
                    if(p-1 >= 0) {
                        tmp = -inf;
                        if(i-1 >= 0) tmp = max(tmp, dp[i-1][j][p-1]);
                        if(j-1 >= 0) tmp = max(tmp, dp[i][j-1][p-1]);
                        if(tmp == -inf) tmp = 0;
                        dp[i][j][p] = max(dp[i][j][p], tmp);
                    }
                }
            }
        }
        return max(dp[n-1][m-1][0], max(dp[n-1][m-1][1], dp[n-1][m-1][2]));
    }
};