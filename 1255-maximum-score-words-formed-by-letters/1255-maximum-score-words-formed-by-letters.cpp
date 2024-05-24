class Solution {
public:
    void solve(int curr, int curr_ans, int &n, vector<string> &words, vector<int> &cnt, vector<int> &score, int &ans) {
        if(curr == n) {
            ans = max(ans, curr_ans);
            return;
        }
        solve(curr+1, curr_ans, n, words, cnt, score, ans);
        bool valid = 1;
        for(const char &c: words[curr]) {
            cnt[c-'a']--;
            curr_ans += score[c-'a'];
            if(cnt[c-'a'] < 0) valid = 0;
        }
        if(valid) {
            solve(curr+1, curr_ans, n, words, cnt, score, ans);
        }
        for(const char &c: words[curr]) {
            cnt[c-'a']++;
            curr_ans -= score[c-'a'];
        }
    }
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        vector<int> cnt(26, 0);
        int ans = 0, n = words.size();
        for(const char &c: letters) {
            cnt[c - 'a']++;
        }
        solve(0, 0, n, words, cnt, score, ans);
        return ans;
    }
};