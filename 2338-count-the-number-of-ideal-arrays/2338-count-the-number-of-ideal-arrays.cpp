const auto init = []() { ios_base::sync_with_stdio(false); cin.tie(0); return nullptr; }();

class Solution {
public:
    int idealArrays(int n, int maxValue) {
        const int MOD = 1e9 + 7;
        int k = ceil(1.0*log(maxValue)/log(2))+1;
        vector<int> fac(maxValue+1), dp(k+1, 0);
        int ans = 0, tmp;
        dp[0] = 1;
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= k; j++) {
                (dp[j] += dp[j-1]) %= MOD; 
            }
        }
        for(int i = 1; i <= maxValue; i++) fac[i] = i;
        for(int i = 2; i*i <= maxValue; i++) {
            if(fac[i] != i) continue;
            for(int j = i*i; j <= maxValue; j += i) if(fac[j] == j) fac[j] = i;
        }
        for(int i = 1, x, p, pref; i <= maxValue; i++) {
            tmp = 1;
            pref = -1, p = 0;
            for(x = i; x != 1; x /= fac[x]) {
                if(fac[x] == pref) p++;
                else tmp = ((long long)tmp * dp[p])%MOD, pref = fac[x], p = 1;
            }
            tmp = ((long long)tmp * dp[p]) % MOD;
            (ans += tmp) %= MOD;
        }
        return ans;
    }
};