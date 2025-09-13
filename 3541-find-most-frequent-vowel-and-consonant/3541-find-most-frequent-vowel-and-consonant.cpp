class Solution {
public:
    int maxFreqSum(string s) {
        vector<int> cnt(26, 0);
        int ans1 = 0, ans2 = 0;
        for(const char &c: s) {
            cnt[c-'a']++;
            if(c == 'a' || c == 'i' || c == 'u' || c == 'e' || c == 'o') ans1 = max(ans1, cnt[c-'a']);
            else ans2 = max(ans2, cnt[c-'a']);
        }
        return ans1 + ans2;
    }
};