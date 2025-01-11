class Solution {
public:
    bool canConstruct(string s, int k) {
        ios_base::sync_with_stdio(false); cin.tie(0);
        vector<int> cnt(26, 0);
        int c = 0;
        if(s.size() < k) return 0;
        for(const auto &i: s) {
            cnt[i-'a']++;
        }
        for(int i = 0; i < 26; i++) {
            c += (cnt[i]&1);
        }
        return c <= k;
    }
};