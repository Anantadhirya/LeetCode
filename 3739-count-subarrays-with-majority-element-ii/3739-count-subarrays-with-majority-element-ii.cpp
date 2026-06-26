class Solution {
public:
    void update(int idx, int x, int &n, vector<int> &ft) {
        for(int i = idx+n+2; i <= n+n+2; i += i&-i) {
            ft[i] += x;
        }
    }
    int query(int idx, int &n, vector<int> &ft) {
        int ret = 0;
        for(int i = idx+n+2; i > 0; i -= i&-i) {
            ret += ft[i];
        }
        return ret;
    }
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        // pref[r] - pref[l-1] > 0
        int n = nums.size();
        vector<int> ft(2*n+5, 0);
        int pref = 0;
        long long ans = 0;
        update(pref, 1, n, ft);
        for(int i = 0; i < n; i++) {
            if(nums[i] == target) pref++;
            else pref--;
            ans += (long long)query(pref-1, n, ft);
            update(pref, 1, n, ft);
        }
        return ans;
    }
};