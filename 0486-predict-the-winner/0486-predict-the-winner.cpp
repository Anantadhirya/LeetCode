class Solution {
public:
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for(int r = 0; r < n; r++) {
            dp[r][r] = nums[r];
            for(int l = r-1; l >= 0; l--) {
                dp[l][r] = max(nums[l] - dp[l+1][r], nums[r] - dp[l][r-1]);
            }
        }
        return dp[0][n-1] >= 0;
    }
};