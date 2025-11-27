class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        long long ans = LLONG_MIN;
        vector<long long> dp(n+1, 0), pref(n+1, 0);
        for(int i = 1; i <= n; i++) {
            pref[i] = pref[i-1] + nums[i-1];
            if(i-k >= 0) {
                ans = max(ans, dp[i-k] + pref[i] - pref[i-k]);
                dp[i] = max(0ll, dp[i-k] + pref[i] - pref[i-k]);
            }
        }
        return ans;
    }
};