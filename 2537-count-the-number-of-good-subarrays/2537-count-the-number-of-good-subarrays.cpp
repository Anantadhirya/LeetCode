const auto init = []() { ios_base::sync_with_stdio(false); cin.tie(0); return nullptr; }();

class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        int n = nums.size(), tmp = 0;
        long long ans = 0;
        unordered_map<int, int> cnt;
        for(int l = 0, r = 0; r < n; r++) {
            tmp += cnt[nums[r]]++;
            while(tmp >= k) tmp -= --cnt[nums[l++]];
            ans += l;
        }
        return ans;
    }
};