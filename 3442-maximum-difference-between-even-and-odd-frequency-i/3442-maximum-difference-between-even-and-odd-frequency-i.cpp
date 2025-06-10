class Solution {
public:
    int maxDifference(string s) {
        vector<int> cnt(26, 0);
        int mx = 0, mn = s.size();
        for(const auto &i: s) {
            cnt[i-'a']++;
        }
        for(int i = 0; i < 26; i++) {
            if(cnt[i] == 0) continue;
            if(cnt[i]&1) mx = max(mx, cnt[i]);
            else mn = min(mn, cnt[i]);
        }
        return mx - mn;
    }
};