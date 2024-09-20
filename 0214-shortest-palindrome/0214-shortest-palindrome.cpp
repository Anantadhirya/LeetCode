class Solution {
public:
    string shortestPalindrome(string s) {
        ios_base::sync_with_stdio(false); cin.tie(0);
        const long long key = 461;
        const long long MOD = 1e9 + 7;
        int n = s.size();
        vector<long long> p(n+1), pref(n+5), suff(n+5);
        string ans;
        p[0] = 1;
        for(int i = 1; i <= n; i++) {
            p[i] = (p[i-1] * key) % MOD;
        }
        for(int i = 1; i <= n; i++) {
            pref[i] = (pref[i-1] * key % MOD + s[i-1]) % MOD;
        }
        for(int i = n; i >= 1; i--) {
            suff[i] = (suff[i+1] * key % MOD + s[i-1]) % MOD;
        }
        for(int i = n; i >= 1; i--) {
            if(pref[i] != (suff[1] - suff[i+1] * p[i] % MOD + MOD) % MOD) continue;
            ans = s.substr(i);
            reverse(ans.begin(), ans.end());
            return ans + s;
        }
        ans = s;
        reverse(ans.begin(), ans.end());
        return ans + s;
    }
};