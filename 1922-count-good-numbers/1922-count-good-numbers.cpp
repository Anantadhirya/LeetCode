class Solution {
public:
    const long long MOD = 1e9 + 7;
    long long pangkat(long long a, long long b) {
        if(b == 0) return 1;
        return (b&1 ? a : 1) * pangkat(a*a%MOD, b>>1) % MOD;
    }
    int countGoodNumbers(long long n) {
        long long odd = n/2, even = n - odd;
        return pangkat(5, even) * pangkat(4, odd) % MOD;
    }
};