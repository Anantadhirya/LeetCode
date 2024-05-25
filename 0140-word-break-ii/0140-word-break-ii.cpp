class Solution {
public:
    void solve(int curr, int &n, string &s, map<string, bool> &m, vector<string> &tmp, vector<string> &ans) {
        if(curr == n) {
            ans.push_back("");
            for(const string &i: tmp) {
                ans.back() += i + " ";
            }
            ans.back().pop_back();
            return;
        }
        string tmp_word = "";
        for(int i = curr; i < n; i++) {
            tmp_word += s[i];
            if(m[tmp_word]) {
                tmp.push_back(tmp_word);
                solve(i+1, n, s, m, tmp, ans);
                tmp.pop_back();
            }
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        map<string, bool> m;
        vector<string> tmp, ans;
        for(const string &i: wordDict) {
            m[i] = 1;
        }
        solve(0, n, s, m, tmp, ans);
        return ans;
    }
};