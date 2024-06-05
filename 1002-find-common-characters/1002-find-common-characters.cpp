class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        ios_base::sync_with_stdio(false); cin.tie(0);
        vector<int> cnt(26, INT_MAX), tmp;
        vector<string> ans;
        for(const string &word: words) {
            tmp.assign(26, 0);
            for(const char &c: word) {
                tmp[c-'a']++;
            }
            for(int i = 0; i < 26; i++) {
                cnt[i] = min(cnt[i], tmp[i]);
            }
        }
        for(int i = 0; i < 26; i++) {
            for(int j = 0; j < cnt[i]; j++) {
                ans.push_back(string(1, 'a'+i));
            }
        }
        return ans;
    }
};