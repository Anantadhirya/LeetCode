class Solution {
public:
    bool check(int x, string &s) {
        if(x == s.size()) return 0;
        for(int i = s.size()-1; i >= 0; i--) {
            if(s[i] != s[i%x]) return 0;
        }
        return 1;
    }
    bool repeatedSubstringPattern(string s) {
        int n = s.size();
        for(int i = 1; i*i <= n; i++) {
            if(n % i != 0) continue;
            if(check(i, s) || check(n/i, s)) return 1;
        }
        return 0;
    }
};