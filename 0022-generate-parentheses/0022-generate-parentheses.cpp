class Solution {
public:
    void solve(int open, int close, string &s, vector<string> &ans) {
        if(open == 0 && close == 0) {
            ans.push_back(s);
            return;
        }
        if(open) {
            s += '(';
            solve(open-1, close+1, s, ans);
            s.pop_back();
        }
        if(close) {
            s += ')';
            solve(open, close-1, s, ans);
            s.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string s;
        solve(n, 0, s, ans);
        return ans;
    }
};