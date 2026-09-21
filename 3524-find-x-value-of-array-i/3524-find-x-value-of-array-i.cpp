class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> ans(k, 0);
        vector<vector<long long>> dp(n+1, vector<long long>(k, 0));
        for(int i = 1, x; i <= n; i++) {
            x = nums[i-1]%k;
            dp[i][x] = 1;
            for(int j = 0; j < k; j++) {
                dp[i][(j*x)%k] += dp[i-1][j];
            }
            for(int j = 0; j < k; j++) {
                ans[j] += dp[i][j];
            }
        }
        return ans;
    }
};