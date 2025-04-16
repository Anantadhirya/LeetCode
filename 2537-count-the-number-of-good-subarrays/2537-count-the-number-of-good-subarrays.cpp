class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        int n = nums.size();
        long long ans = 0, tmp = 0;
        unordered_map<int, long long> cnt;
        for(int l = 0, r = 0; r < n; r++) {
            tmp -= cnt[nums[r]] * (cnt[nums[r]] - 1) / 2;
            cnt[nums[r]]++;
            tmp += cnt[nums[r]] * (cnt[nums[r]] - 1) / 2;
            while(tmp >= k) {
                tmp -= cnt[nums[l]] * (cnt[nums[l]] - 1) / 2;
                cnt[nums[l]]--;
                tmp += cnt[nums[l]] * (cnt[nums[l]] - 1) / 2;
                l++;
            }
            ans += l;
        }
        return ans;
    }
};