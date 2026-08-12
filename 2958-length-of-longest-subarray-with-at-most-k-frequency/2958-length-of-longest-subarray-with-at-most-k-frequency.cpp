class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(false); cin.tie(0);
        unordered_map<int, int> cnt;
        int n = nums.size(), ans = 0;
        for(int l = 0, r = 0; r < n; r++) {
            cnt[nums[r]]++;
            while(l <= r && cnt[nums[r]] > k) {
                cnt[nums[l++]]--;
            }
            ans = max(ans, r-l+1);
        }
        return ans;
    }
};