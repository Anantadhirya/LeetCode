class Solution {
public:
    int smallestBalancedIndex(vector<int>& nums) {
        int n = nums.size();
        int ans = -1;
        long long l, r = 1;
        vector<long long> pref(n, 0);
        for(int i = 0; i < n; i++) pref[i] = nums[i] + (i-1 >= 0 ? pref[i-1] : 0);
        for(int i = n-1; i >= 0; i--) {
            l = (i-1 >= 0 ? pref[i-1] : 0);
            if(i+1 < n) {
                if(r > l/nums[i+1]) break;
                r *= (long long)nums[i+1];
            }
            if(l == r) ans = i;
        }
        return ans;
    }
};