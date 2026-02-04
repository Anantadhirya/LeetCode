class Solution {
public:
    void ms(long long &a, long long b) {
        a = max(a, b);
    }
    long long maxSumTrionic(vector<int>& nums) {
        const long long inf = LLONG_MAX;
        int n = nums.size();
        vector<vector<long long>> dp(3, vector<long long>(n, -inf));
        long long ans = -inf;
        for(int i = 1; i < n; i++) {
            if(nums[i-1] < nums[i]) {
                ms(dp[0][i], nums[i-1] + nums[i]);
                if(dp[0][i-1] != -inf) ms(dp[0][i], dp[0][i-1] + nums[i]);
                if(dp[1][i-1] != -inf) ms(dp[2][i], dp[1][i-1] + nums[i]);
                if(dp[2][i-1] != -inf) ms(dp[2][i], dp[2][i-1] + nums[i]);
            } else if(nums[i-1] > nums[i]) {
                if(dp[0][i-1] != -inf) ms(dp[1][i], dp[0][i-1] + nums[i]);
                if(dp[1][i-1] != -inf) ms(dp[1][i], dp[1][i-1] + nums[i]);
            }
            ms(ans, dp[2][i]);
        }
        return ans;
    }
};