class Solution {
public:
    int magicalSum(int m, int k, vector<int>& nums) {
        const int MOD = 1e9 + 7;
        const int LG = 6;
        int n = nums.size();
        vector<vector<int>> C(m+1, vector<int>(m+1, 0));
        vector<vector<vector<vector<int>>>> dp(n+1, vector<vector<vector<int>>>(m+1, vector<vector<int>>(k+1, vector<int>(1<<LG, 0))));
        int pang;
        for(int i = 0; i <= m; i++) {
            C[i][0] = 1;
            for(int j = 1; j <= i; j++) {
                C[i][j] = (C[i-1][j-1] + C[i-1][j]) % MOD;
            }
        }
        dp[0][0][0][0] = 1;
        for(int i = 0; i < n; i++) {
            for(int l = 0; l <= m; l++) {
                for(int b = 0; b <= k; b++) {
                    for(int mask = 0, new_mask; mask < (1<<LG); mask++) {
                        pang = 1;
                        for(int c = 0; l+c <= m; c++) {
                            new_mask = mask + c;
                            if(b+(new_mask&1) <= k) (dp[i+1][l+c][b+(new_mask&1)][new_mask>>1] += (long long)dp[i][l][b][mask] * pang % MOD * C[l+c][c] % MOD) %= MOD;
                            pang = (long long)pang * nums[i] % MOD;
                        }
                    }
                }
            }
        }
        int ans = 0;
        for(int b = 0; b <= k; b++) {
            for(int mask = 0; mask < (1<<LG); mask++) {
                if(b + __builtin_popcount(mask) == k) {
                    (ans += dp[n][m][b][mask]) %= MOD;
                }
            }
        }
        return ans;
    }
};