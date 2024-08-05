class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size()+5, INT_MAX);
        for(int i = 0; i < cost.size(); i++) {
            if(i <= 1) dp[i] = 0;
            dp[i+1] = min(dp[i+1], dp[i] + cost[i]);
            dp[i+2] = min(dp[i+2], dp[i] + cost[i]);
        }
        return dp[cost.size()];
    }
};