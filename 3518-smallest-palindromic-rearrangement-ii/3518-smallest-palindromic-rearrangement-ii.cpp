#define LL long long

class Solution {
public:
    LL comb(LL n, LL k, LL limit) {
        if(k < 0 || k > n) return 0;
        k = min(k, n-k);
        LL ret = 1;
        for(LL i = 1; i <= k; i++) {
            ret = ret * (n-i+1) / i;
            if(ret > limit) return limit + 1;
        }
        return ret;
    }
    LL f(vector<int> &cnt, LL limit) {
        int tot = 0;
        for(int i = 0; i < 26; i++) tot += cnt[i];

        LL ret = 1;
        for(int i = 0; i < 26; i++) {
            if(cnt[i] == 0) continue;
            ret *= comb(tot, cnt[i], limit);
            tot -= cnt[i];
            if(ret > limit) return limit + 1;
        }
        return ret;
    }
    string smallestPalindrome(string s, int k) {
        int n = s.size();
        int m = n/2;
        LL tmp;
        vector<int> cnt(26, 0);
        for(int i = 0; i < m; i++) {
            cnt[s[i]-'a']++;
        }
        if(k > f(cnt, k)) return "";
        string ans;
        for(int i = 0; i < m; i++) {
            for(int c = 0; c < 26; c++) {
                if(cnt[c] == 0) continue;
                cnt[c]--;
                tmp = f(cnt, k);
                // cout << i << " " << char('a'+c) << " -> " << tmp << "\n";
                if(tmp >= k) {
                    ans.push_back('a'+c);
                    break;
                }
                k -= tmp;
                cnt[c]++;
            }
        }
        if(n&1) ans.push_back(s[n/2]);
        for(int i = m-1; i >= 0; i--) {
            ans.push_back(ans[i]);
        }
        return ans;
        // mrkmn
        // kmmnr
    }
};