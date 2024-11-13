class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        ios_base::sync_with_stdio(false); cin.tie(0);
        int n = nums.size();
        long long ans = 0;
        sort(nums.begin(), nums.end());
        for(int i = n-1, l = 0, r = 0; i >= 0; i--) {
            while(r < n && nums[i] + nums[r] <= upper) r++;
            while(l < n && nums[i] + nums[l] < lower) l++;
            ans += (long long)r-l - (l <= i && i < r);
        }
        return ans/2;
    }
};