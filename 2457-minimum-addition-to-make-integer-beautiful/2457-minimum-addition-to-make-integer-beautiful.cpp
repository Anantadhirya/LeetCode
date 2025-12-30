class Solution {
public:
    long long makeIntegerBeautiful(long long n, int target) {
        int sm = 0;
        long long x;
        for(long long i = 1; i <= 10*n; i *= 10) {
            x = (i == 1 ? 0 : i - (n%i));
            sm = 0;
            for(long long j = n+x; j > 0; j /= 10) sm += j%10;
            if(sm <= target) return x;
        }
        return -1;
    }
};