class Solution {
public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        ios_base::sync_with_stdio(false); cin.tie(0);
        const long long inf = LLONG_MAX;
        int n = robot.size(), m = factory.size();
        vector<vector<long long>> dp(n+1, vector<long long>(m+1, inf));
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());
        for(int j = 0; j <= m; j++) {
            dp[0][j] = 0;
        }
        long long tmp;
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                dp[i][j] = dp[i][j-1];
                tmp = 0;
                for(int k = 1; k <= factory[j-1][1] && i-k >= 0; k++) {
                    tmp += abs(factory[j-1][0] - robot[i-k+1-1]);
                    if(dp[i-k][j-1] != inf) dp[i][j] = min(dp[i][j], dp[i-k][j-1] + tmp);
                }
            }
        }
        return dp[n][m];
    }
};