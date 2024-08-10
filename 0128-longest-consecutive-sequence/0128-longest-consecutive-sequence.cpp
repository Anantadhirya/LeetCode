class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        ios_base::sync_with_stdio(false); cin.tie(0);
        map<int, int> dp;
        int ans = 0;
        for(auto &i: nums) {
            dp[i] = 1;
        }
        for(auto &[i, _]: dp) {
            dp[i] = dp[i-1] + 1;
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};