class Solution {
public:
    int concatenatedBinary(int n) {
        const int MOD = 1e9 + 7;
        long long ans = 0;
        for(int i = 1; i <= n; i++) {
            ans = (ans << (32 - __builtin_clz(i))) | i;
            if(ans >= MOD) ans %= MOD;
        }
        return ans;
    }
};