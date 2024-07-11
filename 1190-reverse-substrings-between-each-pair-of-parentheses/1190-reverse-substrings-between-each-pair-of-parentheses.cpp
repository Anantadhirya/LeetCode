class Solution {
public:
    string solve(int l, int r, string &s) {
        for(int i = l; i <= r; i++) {
            if(s[i] == '(') {
                for(int j = i+1, t = 1; j <= r; j++) {
                    if(s[j] == '(') t++;
                    else if(s[j] == ')') t--;
                    if(t == 0) {
                        string ans = solve(i+1, j-1, s);
                        reverse(ans.begin(), ans.end());
                        return s.substr(l, i-l) + ans + solve(j+1, r, s);
                    }
                }
            }
        }
        return s.substr(l, r-l+1);
    }
    string reverseParentheses(string s) {
        return solve(0, s.size()-1, s);
    }
};