const auto init = []() { ios_base::sync_with_stdio(false); cin.tie(0); return nullptr; }();

class Solution {
public:
    const int MOD = 1e9 + 7;
    int pangkat(int a, int b) {
        if(b == 0) return 1;
        return (long long)(b&1 ? a : 1) * pangkat((long long)a*a%MOD, b>>1) % MOD;
    }
    int countBalancedPermutations(string num) {
        int n = num.size(), sm = 0, ans;
        vector<int> cnt(10, 0);
        vector<int> f(n+1), fi(n+1);
        f[0] = fi[0] = 1;
        for(int i = 1; i <= n; i++) {
            f[i] = (long long)i * f[i-1] % MOD;
            fi[i] = pangkat(f[i], MOD-2);
        }
        for(const char &c: num) {
            sm += (c-'0');
            cnt[c-'0']++;
        }
        if(sm&1) return 0;
        vector<vector<vector<int>>> dp(10+1, vector<vector<int>>(n/2+1, vector<int>(sm/2 + 1, 0)));
        dp[0][0][0] = 1;
        for(int c = 0; c < 10; c++) {
            for(int k = 0; k <= cnt[c]; k++) {
                for(int i = n/2; i >= k; i--) {
                    for(int j = sm/2; j >= k*c; j--) {
                        (dp[c+1][i][j] += (long long)dp[c][i-k][j-k*c] * fi[k] % MOD * fi[cnt[c]-k] % MOD) %= MOD;
                    }
                }
            }
        }
        ans = (long long)dp[10][n/2][sm/2] * f[n/2] % MOD * f[(n+1)/2] % MOD;
        return ans;
    }
};