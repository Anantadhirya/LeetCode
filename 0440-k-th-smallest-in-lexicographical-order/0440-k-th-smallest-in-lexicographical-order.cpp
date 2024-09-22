class Solution {
public:
    long long less(long long x, long long &n) {
        long long ret = 0;
        long long mn = x, mx = x;
        while(mn <= n) {
            ret += min(n,mx) - mn + 1;
            mn = 10*mn;
            mx = 10*mx + 9;
        }
        return ret;
    }
    int findKthNumber(long long n, long long k) {
        long long curr = 0;
        long long cnt = 0;
        while(cnt < k) {
            for(int i = (cnt == 0), tmp; i <= 9; i++) {
                tmp = less(10*curr + i, n);
                if(cnt + tmp >= k) {
                    cnt++;
                    curr = 10*curr + i;
                    break;
                } else cnt += tmp;
            }
        }
        return curr;
    }
};