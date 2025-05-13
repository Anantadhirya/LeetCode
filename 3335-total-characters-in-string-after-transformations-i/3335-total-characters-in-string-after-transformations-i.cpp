const auto init = []() { ios_base::sync_with_stdio(false); cin.tie(0); return nullptr; }();

class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        const int MOD = 1e9 + 7;
        vector<vector<int>> cnt(2, vector<int>(26, 0));
        int ans = 0;
        for(const int &i: s) {
            cnt[0][i-'a']++;
        }
        for(int i = 1; i <= t; i++) {
            for(int j = 0; j < 25; j++) {
                cnt[i&1][j+1] = cnt[~i&1][j];
            }
            cnt[i&1][0] = cnt[~i&1][25];
            (cnt[i&1][1] += cnt[~i&1][25]) %= MOD;
        }
        for(int i = 0; i < 26; i++) {
            (ans += cnt[t&1][i]) %= MOD;
        }
        return ans;
    }
};