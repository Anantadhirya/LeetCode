class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<int> v(2*limit+1, 0), pref(2*limit+1, 0), suff(2*limit+1, 0);
        int ans = n, tmp = 0;
        for(int i = 0; i < n/2; i++) {
            v[nums[i] + nums[n-1-i]]++;
            pref[limit + max(nums[i], nums[n-1-i])]++;
            suff[1 + min(nums[i], nums[n-1-i])]++;
            tmp++;
        }
        for(int i = 0; i <= 2*limit; i++) {
            tmp -= suff[i];
            ans = min(ans, n/2 - v[i] + tmp);
            tmp += pref[i];
        }
        return ans;
    }
};