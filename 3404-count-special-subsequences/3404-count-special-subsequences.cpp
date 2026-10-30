class Solution {
public:
    long long numberOfSubsequences(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;
        map<pair<int, int>, long long> m;
        for(int r = 0, q; r < n; r++) {
            q = r-2;
            for(int p = 0, g; p <= q-2; p++) {
                g = __gcd(nums[p], nums[q]);
                m[{nums[p]/g, nums[q]/g}]++;
            }
            for(int s = r+2, g; s < n; s++) {
                g = __gcd(nums[r], nums[s]);
                ans += m[{nums[s]/g, nums[r]/g}];
            }
        }
        return ans;
    }
};