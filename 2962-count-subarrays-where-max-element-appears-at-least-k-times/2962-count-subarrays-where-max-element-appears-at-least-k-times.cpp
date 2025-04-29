class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(false); cin.tie(0);
        int mx = *max_element(nums.begin(), nums.end());
        int cnt = 0, n = nums.size();
        long long ans = 0;
        for(int l = 0, r = 0; r < n; r++) {
            cnt += (nums[r] == mx);
            while(cnt >= k) cnt -= (nums[l++] == mx);
            ans += l;
        }
        return ans;
    }
};