class Solution {
public:
    const int inf = INT_MAX;
    int dp(vector<int> &cnt, vector<vector<int>> &sc, map<vector<int>, int> &memo) {
        if(memo.count(cnt)) return memo[cnt];
        int &ret = memo[cnt];
        vector<int> v = cnt;
        int tmp;
        bool valid = 1;
        for(const int &i: cnt) {
            valid &= (i <= 0);
        }
        if(valid) return ret = 0;
        ret = inf;
        for(const auto &c: sc) {
            valid = 0;
            for(int i = 0; i < 26; i++) {
                if(cnt[i] > 0 && c[i] > 0) valid = 1;
                v[i] = max(0, cnt[i] - c[i]);
            }
            if(valid) {
                tmp = dp(v, sc, memo);
                if(tmp != inf) ret = min(ret, 1 + tmp);
            }
        }
        return ret;
    }
    int minStickers(vector<string>& stickers, string target) {
        int n = stickers.size();
        vector<int> cnt(26, 0);
        vector<vector<int>> sc(n, vector<int>(26, 0));
        map<vector<int>, int> memo;
        for(const char &c: target) {
            cnt[c-'a']++;
        }
        for(int i = 0; i < n; i++) {
            for(const char &c: stickers[i]) {
                sc[i][c-'a']++;
            }
        }
        int ans = dp(cnt, sc, memo);
        return ans == inf ? -1 : ans;
    }
};