class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int> cnt(26, 0);
        for(const char &c: word) {
            if('A' <= c && c <= 'Z') cnt[c-'A'] |= 2;
            else cnt[c-'a'] |= 1;
        }
        int ans = 0;
        for(int i = 0; i < 26; i++) {
            ans += cnt[i] == 3;
        }
        return ans;
    }
};