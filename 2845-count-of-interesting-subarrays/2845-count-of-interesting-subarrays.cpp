class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        // pref - l == k mod modulo
        // pref - k == l mod modulo
        unordered_map<int, int> m;
        long long ans = 0, pref = 0;
        m[0] = 1;
        for(const int &i: nums) {
            (pref += (i % modulo == k)) %= modulo;
            ans += m[(pref-k+modulo) % modulo];
            m[pref]++;
        }
        return ans;
    }
};