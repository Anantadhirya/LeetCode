class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<long long> dp(n+1, 0);
        for(int i = n-1; i >= 0; i--) {
            dp[i] = max(dp[i+1], questions[i][0] + (i+1+questions[i][1] <= n ? dp[i+1+questions[i][1]] : 0));
        }
        return dp[0];
    }
};