class Solution {
public:
    void ms(int &a, int b) {
        a = max(a, b);
    }
    int maxDifference(string s, int k) {
        const int inf = INT_MAX;
        int n = s.size();
        for(auto &i: s) i -= '0';
        int ans = -inf;
        int cnta, cntb, cnt, idx;
        vector<vector<vector<int>>> pref(n+1, vector<vector<int>>(2, vector<int>(2)));
        for(int a = 0; a <= 4; a++) {
            for(int b = 0; b <= 4; b++) {
                if(b == a) continue;
                cnta = cntb = cnt = 0;
                pref[0][0][0] = 0;
                pref[0][0][1] = pref[0][1][0] = pref[0][1][1] = -inf;
                for(int r = 0, l = 0; r < n; r++) {
                    if(s[r] == a) cnta++;
                    else if(s[r] == b) cntb++, cnt++;
                    while(cnt >= 2) if(s[l++] == b) cnt--;

                    pref[r+1] = pref[r];
                    ms(pref[r+1][cnta&1][cntb&1], -(cnta-cntb));
                    // substring i..r have cnt >= 2 if i < l

                    idx = min(l-1, r-k+1);
                    if(idx >= 0 && pref[idx][~cnta&1][cntb&1] != -inf) {
                        ms(ans, cnta - cntb + pref[idx][~cnta&1][cntb&1]);
                    }
                }
            }
        }
        return ans;
    }
};