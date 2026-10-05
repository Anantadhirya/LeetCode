class Solution {
public:
    int solve(int l, int r, string &s) {
        if(r < l) return 0;
        if(l+1 == r) return 1;
        for(int i = l, c = 0; i <= r; i++) {
            if(s[i] == '(') c++;
            else c--;
            if(c == 0) {
                return solve(i+1, r, s) + (l+1 == i ? 1 : 2*solve(l+1, i-1, s));
            }
        }
        return -1;
    }
    int scoreOfParentheses(string s) {
        return solve(0, s.size()-1, s);
    }
};