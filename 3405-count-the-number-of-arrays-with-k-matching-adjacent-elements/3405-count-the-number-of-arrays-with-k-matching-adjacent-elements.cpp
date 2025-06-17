const auto init = []() { ios_base::sync_with_stdio(false); cin.tie(0); return nullptr; }();

class Solution {
public:
    const int MOD = 1e9 + 7;
    int pangkat(int a, int b) {
        if(b == 0) return 1;
        return (long long)(b&1 ? a : 1) * pangkat((long long)a*a%MOD, b>>1) % MOD;
    }
    int countGoodArrays(int n, int m, int k) {
        // C(n-1, k) * m * (m-1)^(n-1-k)
        long long ans = (long long)m * pangkat(m-1, n-1-k) % MOD, div = 1;
        for(int i = 0; i < k; i++) {
            ans = ans * (n-1 - i) % MOD;
            div = div * (k - i) % MOD;
        }
        ans = ans * pangkat(div, MOD-2) % MOD;
        return ans;
    }
};