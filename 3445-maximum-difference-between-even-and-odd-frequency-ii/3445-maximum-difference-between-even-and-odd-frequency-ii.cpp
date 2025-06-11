const auto init = []() { ios_base::sync_with_stdio(false); cin.tie(0); return nullptr; }();
class Solution {
public:
    int f(int cnta, int cntb) {
        return ((cnta&1)<<1) + (cntb&1);
    }
    void ms(int &a, int b) {
        a = max(a, b);
    }
    int maxDifference(string s, int k) {
        const int inf = INT_MAX;
        int n = s.size();
        for(auto &i: s) i -= '0';
        int ans = -inf;
        int cnta, cntb, prefa, prefb;
        vector<int> mx(4);
        vector<vector<vector<int>>> pref(n+1, vector<vector<int>>(2, vector<int>(2)));
        for(int a = 0; a <= 4; a++) {
            for(int b = 0; b <= 4; b++) {
                if(b == a) continue;
                cnta = cntb = prefa = prefb = 0;
                mx = {-inf, -inf, -inf, -inf};
                for(int r = 0, l = 0; r < n; r++) {
                    cnta += (s[r] == a);
                    cntb += (s[r] == b);

                    while(r-l+1 >= k && cntb - prefb >= 2) {
                        ms(mx[f(prefa, prefb)], -(prefa - prefb));
                        prefa += (s[l] == a);
                        prefb += (s[l] == b);
                        l++;
                    }

                    if(l-1 >= 0 && mx[f(cnta+1, cntb)] != -inf) {
                        ms(ans, cnta - cntb + mx[f(cnta+1, cntb)]);
                    }
                }
            }
        }
        return ans;
    }
};