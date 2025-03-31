class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> cnt(26, 0);
        for(const char &c: s) {
            cnt[c-'a']++;
        }
        for(const char &c: t) {
            cnt[c-'a']--;
        }
        int ans = 0;
        for(int i = 0; i < 26; i++) {
            ans += abs(cnt[i]);
        }
        return ans;
    }
};