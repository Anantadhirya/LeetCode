class Solution {
public:
    int minimumLength(string s) {
        ios_base::sync_with_stdio(false); cin.tie(0);
        vector<int> cnt(26, 0);
        int ans = 0;
        for(const auto &c: s) {
            cnt[c-'a']++;
        }
        for(const auto &i: cnt) {
            if(i == 0) continue;
            ans += (i % 2 == 0 ? 2 : 1);
        }
        return ans;
    }
};