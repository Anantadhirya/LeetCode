class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        int n = words2.size();
        vector<int> cnt1, cnt2, mx(26, 0);
        vector<string> ans;
        for(const auto &s: words2) {
            cnt2.assign(26, 0);
            for(const auto &c: s) {
                cnt2[c-'a']++;
            }
            for(int i = 0; i < 26; i++) {
                mx[i] = max(mx[i], cnt2[i]);
            }
        }
        for(const auto &s: words1) {
            cnt1.assign(26, 0);
            for(const auto &c: s) {
                cnt1[c-'a']++;
            }
            ans.push_back(s);
            for(int i = 0; i < 26; i++) {
                if(cnt1[i] < mx[i]) {
                    ans.pop_back();
                    break;
                }
            }
        }
        return ans;
    }
};