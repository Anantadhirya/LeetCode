class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        const int MX = 1e5 + 5;
        const int MOD = 1e9 + 7;
        vector<int> cnt(MX, 0), cntl(MX, 0);
        for(auto i: nums) {
            cnt[i]++;
        }
        int ans = 0;
        for(auto i: nums) {
            if(2*i < MX) (ans += (long long)cntl[2*i] * (cnt[2*i] - cntl[2*i] - (i==0)) % MOD) %= MOD;
            cntl[i]++;
        }
        return ans;
    }
};