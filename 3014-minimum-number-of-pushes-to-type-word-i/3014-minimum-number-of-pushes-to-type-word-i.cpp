class Solution {
public:
    int minimumPushes(string word) {
        vector<int> cnt(26, 0);
        for(char &c: word) {
            cnt[c-'a']++;
        }
        int ans = 0;
        sort(cnt.rbegin(), cnt.rend());
        for(int i = 0; i < 26; i++) {
            ans += cnt[i] * (i/8 + 1);
        }
        return ans;
    }
};