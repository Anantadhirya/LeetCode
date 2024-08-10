class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(false); cin.tie(0);
        map<int, int> cnt;
        int n = nums.size();
        for(int r = 0, l = 0; r < n; r++) {
            if(r-l > k) cnt[nums[l++]]--;
            cnt[nums[r]]++;
            if(cnt[nums[r]] > 1) return 1;
        }
        return 0;
    }
};