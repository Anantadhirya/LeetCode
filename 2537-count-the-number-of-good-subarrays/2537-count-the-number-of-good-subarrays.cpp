class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        int n = nums.size();
        long long ans = 0, tmp = 0;
        unordered_map<int, long long> cnt;
        for(int l = 0, r = 0; r < n; r++) {
            tmp += cnt[nums[r]]++;
            while(tmp >= k) {
                tmp -= --cnt[nums[l]];
                l++;
            }
            ans += l;
        }
        return ans;
    }
};