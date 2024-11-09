class Solution {
public:
    long long minEnd(int n, int x) {
        long long k = n - 1;
        long long ans = x;
        for(long long i = 0; k > 0; i++) {
            if(((long long)x>>i)&1) continue;
            ans += ((long long)(k&1)<<i);
            k >>= 1;
        }
        return ans;
    }
};