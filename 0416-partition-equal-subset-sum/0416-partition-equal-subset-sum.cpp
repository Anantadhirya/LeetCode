class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sm = 0;
        for(const int &i: nums) {
            sm += i;
        }
        if(sm&1) return 0;
        sm /= 2;
        bitset<10001> dp;
        dp[0] = 1;
        for(const int &i: nums) {
            dp |= dp << i;
            if(dp[sm]) return 1;
        }
        return 0;
    }
};