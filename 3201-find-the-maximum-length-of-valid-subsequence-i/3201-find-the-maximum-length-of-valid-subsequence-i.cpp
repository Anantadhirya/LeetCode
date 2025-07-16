class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(2, vector<int>(n+1, 0));
        int lst[2];
        lst[0] = lst[1] = -1;
        int ans = 0;
        for(int i = 1, p; i <= n; i++) {
            p = nums[i-1]&1;
            if(lst[0] != -1) {
                dp[p][i] = max(dp[p][i], dp[p][lst[0]] + 1);
                ans = max(ans, dp[p][i]);
            }
            if(lst[1] != -1) {
                dp[p^1][i] = max(dp[p^1][i], dp[p^1][lst[1]] + 1);
                ans = max(ans, dp[p^1][i]);
            }
            lst[p] = i;
        }
        return ans + 1;
    }
};