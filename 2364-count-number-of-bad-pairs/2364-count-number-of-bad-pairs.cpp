const auto init = []() { ios_base::sync_with_stdio(false); cin.tie(0); return NULL; }();

class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        int n = nums.size();
        long long ans = (long long)n*(n-1)/2;
        unordered_map<int, int> cnt;
        for(int i = 0; i < n; i++) {
            ans -= cnt[nums[i] - i]++;
        }
        return ans;
    }
};