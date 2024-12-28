class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> pref(n+1, 0);
        vector<vector<pair<int, int>>> dp(n+5, vector<pair<int, int>>(4, {0, 0}));
        vector<int> ans;
        for(int i = 1; i <= n; i++) {
            pref[i] = pref[i-1] + nums[i-1];
        }
        for(int i = n-k+1; i >= 1; i--) {
            for(int j = 1; j <= 3; j++) {
                dp[i][j] = max(dp[i+1][j], {dp[i+k][j-1].first + pref[i+k-1] - pref[i-1], -i});
            }
        }
        for(int i = 1, j = 3; j >= 1; j--) {
            ans.push_back(-dp[i][j].second - 1);
            i = -dp[i][j].second + k;
        }
        return ans;
    }
};