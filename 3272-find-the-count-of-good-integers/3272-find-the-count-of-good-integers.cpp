class Solution {
public:
    void solve(int curr, vector<int> &v, int &n, int &k, unordered_set<long long> &s) {
        if(curr == (n+1)/2) {
            long long x = 0, cnt_val = 0;
            vector<int> cnt(10, 0);
            for(int i = 0; i < curr; i++) {
                x = x*10 + v[i];
                cnt[v[i]]++;
            }
            for(int i = curr-1-(n&1); i >= 0; i--) {
                x = x*10 + v[i];
                cnt[v[i]]++;
            }
            for(int i = 0; i <= 9; i++) {
                cnt_val = cnt_val * 11 + cnt[i];
            }
            if(x % k == 0) s.insert(cnt_val);
            return;
        }
        for(int i = (curr == 0); i <= 9; i++) {
            v[curr] = i;
            solve(curr+1, v, n, k, s);
        }
    }
    long long countGoodIntegers(int n, int k) {
        vector<int> v((n+1)/2);
        unordered_set<long long> s;
        solve(0, v, n, k, s);
        long long ans = 0, tmp, fac[n+1], cnt0;
        fac[0] = 1;
        for(int i = 1; i <= n; i++) {
            fac[i] = fac[i-1] * i;
        }
        for(const long long &cnt: s) {
            tmp = fac[n];
            for(long long i = 0, j = cnt; i <= 9; i++, j /= 11) {
                tmp /= fac[j%11];
                cnt0 = j%11;
            }
            if(cnt0) tmp -= tmp * cnt0 / n;
            ans += tmp;
        }
        return ans;
    }
};