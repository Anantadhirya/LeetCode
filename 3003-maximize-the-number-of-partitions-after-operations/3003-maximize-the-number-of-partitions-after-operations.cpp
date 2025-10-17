class Solution {
public:
    int maxPartitionsAfterOperations(string s, int k) {
        int n = s.size();
        vector<int> suff(n, 1), start(n), pref(n, 0);
        vector<vector<int>> prefc(26, vector<int>(n, 0));
        vector<int> cnt(26, 0);
        for(int i = n-1, j = n-1, d = 0; i >= 0; i--) {
            if(cnt[s[i]-'a']++ == 0) d++;
            while(d > k) {
                if(--cnt[s[j--]-'a'] == 0) d--;
            }
            suff[i] = 1 + (j+1 < n ? suff[j+1] : 0);
        }
        cnt.assign(26, 0);
        for(int i = 0, j = 0, d = 0, p = 0; i < n; ) {
            while(d <= k && j < n) {
                if(cnt[s[j]-'a']++ == 0) d++;
                j += (d <= k);
            }
            for(int l = i; l < j; l++) {
                start[l] = i;
            }
            pref[i] = p++;
            i = j;
            d = 0;
            cnt.assign(26, 0);
        }
        for(int i = 0; i < n; i++) {
            for(int c = 0; c < 26; c++) {
                prefc[c][i] = (s[i]-'a' == c) + (i-1 >= 0 ? prefc[c][i-1] : 0);
            }
        }
        int ans = suff[0];
        auto get_distinct = [&](int l, int r, int idx, int to) {
            int ret = 0;
            for(int c = 0; c < 26; c++) {
                ret += (prefc[c][r] - (l-1 >= 0 ? prefc[c][l-1] : 0) + (l <= idx && idx <= r ? (c == to) - (c == s[idx]-'a') : 0) > 0);
            }
            return ret;
        };
        for(int i = 0; i < n; i++) {
            for(int c = 0, idx, idx2; c < 26; c++) {
                if(c == s[i]-'a') continue;
                for(int l = start[i], r = n-1, mid; l <= r; ) {
                    mid = (l+r)/2;
                    if(get_distinct(start[i], mid, i, c) <= k) {
                        idx = mid;
                        l = mid + 1;
                    } else r = mid - 1;
                }
                if(i <= idx) {
                    ans = max(ans, pref[start[i]] + 1 + (idx+1 < n ? suff[idx+1] : 0));
                } else {
                    for(int l = idx+1, r = n-1, mid; l <= r; ) {
                        mid = (l+r)/2;
                        if(get_distinct(idx+1, mid, i, c) <= k) {
                            idx2 = mid;
                            l = mid+1;
                        } else r = mid - 1;
                    }
                    ans = max(ans, pref[start[i]] + 2 + (idx2+1 < n ? suff[idx2+1] : 0));
                }
            }
        }
        return ans;
    }
};