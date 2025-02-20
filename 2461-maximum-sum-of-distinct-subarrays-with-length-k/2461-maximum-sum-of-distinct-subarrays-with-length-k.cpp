class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(false); cin.tie(0);
        long long ans = 0, sm = 0;
        vector<int> cnt(1e5+1, 0);
        int n = nums.size(), unique = 0;
        for(int i = 0; i < k; i++) {
            if(cnt[nums[i]]++ == 0) unique++;
            sm += nums[i];
        }
        if(unique == k) ans = max(ans, sm);
        for(int i = k; i < n; i++) {
            if(++cnt[nums[i]] == 1) unique++;
            sm += nums[i];
            sm -= nums[i-k];
            if(--cnt[nums[i-k]] == 0) unique--;
            if(unique == k) ans = max(ans, sm);
        }
        return ans;
    }
};