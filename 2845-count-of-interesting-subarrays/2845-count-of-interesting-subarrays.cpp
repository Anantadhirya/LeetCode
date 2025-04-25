class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        // pref - l == k mod modulo
        // pref - k == l mod modulo
        long long ans = 0;
        int pref = 0, l, n = min(modulo, (int)nums.size()+1);
        vector<int> m(n, 0);
        m[0] = 1;
        for(const int &i: nums) {
            (pref += (i % modulo == k)) %= modulo;
            l = (pref-k+modulo) % modulo;
            if(l < n) ans += m[l];
            m[pref]++;
        }
        return ans;
    }
};