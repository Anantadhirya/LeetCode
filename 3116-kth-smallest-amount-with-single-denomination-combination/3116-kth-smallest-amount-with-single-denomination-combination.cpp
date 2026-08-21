class Solution {
public:
    long long gcd(long long a, long long b) {
        if(a == 0) return b;
        return gcd(b%a, a);
    }
    long long f(long long x, int n, vector<long long> &v) {
        long long ret = 0;
        for(int mask = 1; mask < (1<<n); mask++) {
            ret += x / v[mask] * (__builtin_popcount(mask) & 1 ? 1 : -1);
        }
        return ret;
    }
    long long findKthSmallest(vector<int>& coins, int k) {
        vector<int> tmp;
        bool add;
        for(auto i: coins) {
            add = 1;
            for(auto j: tmp) {
                if(i % j == 0) add = 0;
            }
            if(add) tmp.push_back(i);
        }
        coins = tmp;
        int n = coins.size();
        vector<long long> v(1<<n, 1);
        for(int mask = 0; mask < (1<<n); mask++) {
            for(int i = 0; i < n; i++) {
                if((mask>>i)&1) {
                    v[mask] = (v[mask] * coins[i]) / gcd(v[mask], coins[i]);
                }
            }
        }
        long long l = 1, r = (long long)25*k, mid, ans;
        while(l <= r) {
            mid = l + r >> 1;
            if(f(mid, n, v) >= k) {
                ans = mid;
                r = mid-1;
            } else l = mid+1;
        }
        return ans;
    }
};