#define LL long long
class Solution {
public:
    int pangkat(int a, int b, int mod) {
        if(b == 0) return 1;
        return (LL)(b&1 ? a : 1) * pangkat((LL)a*a%mod, b>>1, mod) % mod;
    }
    int numberOfSets(int n, int k) {
        const int MOD = 1e9 + 7;
        int ans = 1, ians = 1;
        // (A1 + A2 + ... + Ak) + (B1 + B2 + ... + B_k+1) = n-1-k
        // C1 + C2 + ... + C_2k+1 = n-k-1
        // C(n-k-1+2k, 2k)
        // C(n+k-1, 2k)
        n = n+k-1;
        k = 2*k;
        for(int i = 0; i < k; i++) {
            ans = (LL)ans * (n-i) % MOD;
            ians = (LL)ians * (i+1) % MOD;
        }
        return (LL)ans * pangkat(ians, MOD-2, MOD) % MOD;
    }
};