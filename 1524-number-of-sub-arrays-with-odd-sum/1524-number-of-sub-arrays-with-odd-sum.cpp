class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        const int MOD = 1e9 + 7;
        int ans = 0, sm = 0;
        int pref[2];
        pref[0] = 1;
        pref[1] = 0;
        for(const auto &i: arr) {
            (sm += i) &= 1;
            (ans += pref[1-sm]) %= MOD;
            pref[sm]++;
        }
        return ans;
    }
};