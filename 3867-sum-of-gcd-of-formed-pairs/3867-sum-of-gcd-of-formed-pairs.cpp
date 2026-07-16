class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int mx = 0;
        int n = nums.size();
        for(auto &i: nums) {
            mx = max(mx, i);
            i = __gcd(i, mx);
        }
        sort(nums.begin(), nums.end());
        long long ans = 0;
        for(int l = 0, r = n-1; l < r; l++, r--) {
            ans += (long long)__gcd(nums[l], nums[r]);
        }
        return ans;
    }
};