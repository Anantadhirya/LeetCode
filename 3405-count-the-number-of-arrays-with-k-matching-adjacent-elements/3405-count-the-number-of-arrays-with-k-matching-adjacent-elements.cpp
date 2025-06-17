class Solution {
public:
    const int MOD = 1e9 + 7;
    int pangkat(int a, int b) {
        if(b == 0) return 1;
        return (long long)(b&1 ? a : 1) * pangkat((long long)a*a%MOD, b>>1) % MOD;
    }
    int countGoodArrays(int n, int m, int k) {
        // C(n-1, k) * m * (m-1)^(n-1-k)
        int ans = (long long)m * pangkat(m-1, n-1-k) % MOD, div = 1;
        for(int i = 0; i < k; i++) {
            ans = (long long)ans * (n-1 - i) % MOD;
            div = (long long)div * (k - i) % MOD;
        }
        ans = (long long)ans * pangkat(div, MOD-2) % MOD;
        return ans;
    }
};