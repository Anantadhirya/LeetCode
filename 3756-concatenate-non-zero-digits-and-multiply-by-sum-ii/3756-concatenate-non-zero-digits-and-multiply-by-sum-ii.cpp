class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        const long long MOD = 1e9 + 7;
        int n = s.size(), q = queries.size();
        long long x, sm;
        vector<long long> pref(n+1, 0), pref_cnt(n+1, 0), pref_digit(n+1, 0), p(n+1, 1);
        vector<int> ans(q);
        for(int i = 1; i <= n; i++) {
            p[i] = (p[i-1] * 10) % MOD;
        }
        for(int i = 1, c; i <= n; i++) {
            c = s[i-1] - '0';
            pref[i] = (c == 0 ? pref[i-1] : (pref[i-1] * 10 % MOD + c) % MOD);
            pref_cnt[i] = pref_cnt[i-1] + (c != 0);
            pref_digit[i] = (pref_digit[i-1] + c) % MOD;
        }
        for(int l, r, i = 0; i < q; i++) {
            l = queries[i][0]+1;
            r = queries[i][1]+1;
            x = (pref[r] - pref[l-1] * p[pref_cnt[r] - pref_cnt[l-1]] % MOD + MOD) % MOD;
            sm = (pref_digit[r] - pref_digit[l-1] + MOD) % MOD;
            ans[i] = x*sm%MOD;
        }
        return ans;
    }
};