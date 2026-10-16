class Solution {
public:
    void counter(string &s, vector<int> &cnt) {
        for(int i = 0; i < 26; i++) cnt[i] = 0;
        for(char &c: s) {
            cnt[c-'a']++;
        }
    }
    int wordCount(vector<string>& startWords, vector<string>& targetWords) {
        set<vector<int>> st;
        vector<int> cnt(26, 0);
        int ans = 0;
        for(auto &s: startWords) {
            counter(s, cnt);
            st.insert(cnt);
        }
        auto check = [&](string &s) -> bool {
            counter(s, cnt);
            for(int i = 0; i < 26; i++) {
                if(cnt[i] == 1) {
                    cnt[i]--;
                    if(st.count(cnt)) return 1;
                    cnt[i]++;
                }
            }
            return 0;
        };
        for(auto &s: targetWords) {
            ans += check(s);
        }
        return ans;
    }
};