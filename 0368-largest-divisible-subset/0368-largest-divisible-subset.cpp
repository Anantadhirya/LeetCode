class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        int dp[n], pref[n];
        vector<int> ans;
        int idx = 0;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n; i++) {
            dp[i] = 1;
            pref[i] = -1;
            for(int j = 0; j < i; j++) {
                if(nums[i] % nums[j] == 0 && dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                    pref[i] = j;
                }
            }
            if(dp[i] > dp[idx]) {
                idx = i;
            }
        }
        while(idx != -1) {
            ans.push_back(nums[idx]);
            idx = pref[idx];
        }
        return ans;
    }
};