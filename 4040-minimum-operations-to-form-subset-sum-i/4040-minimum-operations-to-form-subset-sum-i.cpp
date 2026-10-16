class Solution {
public:
    int minOperations(vector<int>& nums, int sum) {
        const int inf = INT_MAX;
        vector<int> dp(sum+1, inf), tmp(sum+1);
        dp[0] = 0;
        auto add = [&](int x, int c) -> void {
            for(int i = 0; i+x <= sum; i++) {
                if(dp[i] == inf) continue;
                tmp[i+x] = min(tmp[i+x], dp[i] + c);
            }
        };
        for(auto &i: nums) {
            tmp = dp;
            for(int x = i, c = 0; x <= sum; x *= 2, c++) add(x, c);
            for(int x = i/2, c = 1; x > 0; x /= 2, c++) add(x, c);
            dp = tmp;
        }
        return dp[sum] == inf ? -1 : dp[sum];
    }
};