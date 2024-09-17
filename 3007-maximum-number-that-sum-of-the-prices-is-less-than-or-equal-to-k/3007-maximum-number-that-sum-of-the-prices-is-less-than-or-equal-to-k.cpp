class Solution {
public:
    long long accumulated(long long num, int &x) {
        long long ans = 0;
        for(long long i = x-1, j; 1 <= (num>>i); i += x) {
            j = ((long long)1<<i);
            ans += (num / (j*2)) * j + max((long long)0, num % (j*2) - j + 1);
        }
        return ans;
    }
    long long findMaximumNumber(long long k, int x) {
        long long l = 1, r = 1e15, mid, ans = 0;
        while(l <= r) {
            mid = (l+r)/2;
            if(accumulated(mid, x) <= k) {
                ans = mid;
                l = mid + 1;
            } else r = mid - 1;
        }
        return ans;
    }
};