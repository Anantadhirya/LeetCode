class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, long long> cnt, sm;
        vector<long long> ans(n, 0);
        for(int i = 0; i < n; i++) {
            ans[i] += cnt[nums[i]] * i - sm[nums[i]];
            cnt[nums[i]]++;
            sm[nums[i]] += i;
        }
        cnt.clear();
        sm.clear();
        for(int i = n-1; i >= 0; i--) {
            ans[i] += sm[nums[i]] - cnt[nums[i]]*i;
            cnt[nums[i]]++;
            sm[nums[i]] += i;
        }
        return ans;
    }
};