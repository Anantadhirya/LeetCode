const auto init = []() { ios_base::sync_with_stdio(false); cin.tie(0); return nullptr; }();

class Solution {
public:
    int maxCollectedFruits(vector<vector<int>>& fruits) {
        int n = fruits.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        int ans = 0, tmp;
        dp[0][n-1] = fruits[0][n-1];
        dp[n-1][0] = fruits[n-1][0];
        for(int i = 0; i < n; i++) {
            ans += fruits[i][i];
        }
        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                tmp = -1;
                if(i-1 >= 0 && j-1 >= 0) tmp = max(tmp, dp[i-1][j-1]);
                if(i-1 >= 0) tmp = max(tmp, dp[i-1][j]);
                if(i-1 >= 0 && j+1 < n) tmp = max(tmp, dp[i-1][j+1]);
                if(tmp != -1) dp[i][j] = tmp + fruits[i][j];
            }
        }
        for(int j = 0; j < n; j++) {
            for(int i = j+1; i < n; i++) {
                tmp = -1;
                if(j-1 >= 0 && i-1 >= 0) tmp = max(tmp, dp[i-1][j-1]);
                if(j-1 >= 0) tmp = max(tmp, dp[i][j-1]);
                if(j-1 >= 0 && i+1 < n) tmp = max(tmp, dp[i+1][j-1]);
                if(tmp != -1) dp[i][j] = tmp + fruits[i][j];
            }
        }
        return ans + dp[n-1][n-2] + dp[n-2][n-1];
    }
};