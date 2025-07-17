class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<int>> dp(k, vector<int>(n+1, 0));
        vector<int> lst(k, -1);
        int ans = 0;
        for(int i = 1, p; i <= n; i++) {
            p = nums[i-1] % k;
            for(int j = 0, p2; j < k; j++) {
                if(lst[j] == -1) continue;
                p2 = (p + j) % k;
                dp[p2][i] = max(dp[p2][i], dp[p2][lst[j]] + 1);
                ans = max(ans, dp[p2][i]);
            }
            lst[p] = i;
        }
        return ans + 1;
    }
};