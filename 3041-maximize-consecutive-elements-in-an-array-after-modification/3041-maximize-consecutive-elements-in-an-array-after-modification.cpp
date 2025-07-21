class Solution {
public:
    int maxSelectedElements(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        sort(nums.begin(), nums.end());
        vector<vector<int>> dp(n, vector<int>(2, 1));
        for(int i = 0, j = -1, k = -1, dup; i < n; i++) {
            while(nums[j+1] <= nums[i]-1) j++;
            while(nums[k+1] <= nums[i]-2) k++;

            if(i-1 >= 0 && nums[i-1] == nums[i]) {
                dp[i][1] = max(dp[i][1], dp[i-1][0] + 1);
            }
            if(j >= 0 && nums[j]+1 == nums[i]) {
                dp[i][0] = max(dp[i][0], dp[j][0] + 1);
                dp[i][1] = max(dp[i][1], dp[j][1] + 1);
            }
            if(k >= 0 && nums[k]+2 == nums[i]) {
                dp[i][0] = max(dp[i][0], dp[k][1] + 1);
            }
            ans = max(ans, max(dp[i][0], dp[i][1]));
        }
        return ans;
    }
};