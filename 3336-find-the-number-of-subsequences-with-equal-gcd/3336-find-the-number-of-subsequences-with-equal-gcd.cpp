class Solution {
public:
    int subsequencePairCount(vector<int>& nums) {
        const int MOD = 1e9 + 7;
        int n = nums.size(), mx = *max_element(nums.begin(), nums.end());
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(mx+1, vector<int>(mx+1, 0)));
        int ans = 0;
        dp[0][0][0] = 1;
        for(int i = 0; i < n; i++) {
            for(int a = 0; a <= mx; a++) {
                for(int b = 0; b <= mx; b++) {
                    if(dp[i][a][b] == 0) continue;
                    (dp[i+1][a][b] += dp[i][a][b]) %= MOD;
                    (dp[i+1][__gcd(a,nums[i])][b] += dp[i][a][b]) %= MOD;
                    (dp[i+1][a][__gcd(b,nums[i])] += dp[i][a][b]) %= MOD;
                }
            }
        }
        for(int g = 1; g <= mx; g++) {
            (ans += dp[n][g][g]) %= MOD;
        }
        return ans;
    }
};