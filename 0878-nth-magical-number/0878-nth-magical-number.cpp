#define LL long long
class Solution {
public:
    int nthMagicalNumber(int n, int a, int b) {
        LL MOD = 1e9 + 7;
        LL L = 1, R = (LL)n*(max(a,b)+1), mid, ans = -1, cnt, lcm;
        lcm = (LL)a*b/__gcd(a,b);
        while(L <= R) {
            mid = (L+R)/2;
            cnt = mid/a + mid/b - mid/lcm;
            if(cnt >= n) {
                ans = mid;
                R = mid-1;
            } else L = mid+1;
        }
        return ans % MOD;
    }
};