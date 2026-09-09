class Solution {
public:
    long long countCommas(long long n) {
        long long ans = 0;
        for(long long i = 1000; n/i > 0; i *= 1000) {
            ans += (n/i-1)*i + n % i + 1;
        }
        return ans;
    }
};