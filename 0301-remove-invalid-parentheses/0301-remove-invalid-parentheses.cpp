class Solution {
public:
    void solve(int i, int &x, string &cur, int &n, string &s, vector<string> &ans) {
        if(i == n) {
            if(x != 0) return;
            if(!ans.empty() && cur.size() > ans[0].size()) ans.clear();
            if(ans.empty() || cur.size() == ans[0].size()) ans.push_back(cur);
            return;
        }
        if(!ans.empty() && cur.size() + (n-i) < ans[0].size()) return;

        // Case 1: s[i] is not removed
        cur.push_back(s[i]);
        if(s[i] == '(') x++;
        else if(s[i] == ')') x--;
        if(x >= 0) solve(i+1, x, cur, n, s, ans);
        cur.pop_back();
        if(s[i] == '(') x--;
        else if(s[i] == ')') x++;

        // Case 2: s[i] is removed
        solve(i+1, x, cur, n, s, ans);
        
    }
    vector<string> removeInvalidParentheses(string s) {
        int n = s.size();
        int x = 0;
        string cur;
        vector<string> ans;
        solve(0, x, cur, n, s, ans);
        set<string> tmp(ans.begin(), ans.end());
        return vector<string>(tmp.begin(), tmp.end());
    }
};