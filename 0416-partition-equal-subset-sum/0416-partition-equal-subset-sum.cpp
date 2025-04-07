class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sm = 0;
        for(const int &i: nums) {
            sm += i;
        }
        if(sm&1) return 0;
        sm /= 2;
        vector<bool> dp(sm+1, 0);
        dp[0] = 1;
        for(const int &i: nums) {
            for(int j = sm; j >= i; j--) {
                if(dp[j-i]) dp[j] = 1;
            }
        }
        return dp[sm];
    }
};