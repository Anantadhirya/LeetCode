class Solution {
public:
    char processStr(string s, long long k) {
        int n = s.size();
        s = " " + s;
        vector<long long> len(n+1, 0);
        for(int i = 1; i <= n; i++) {
            if(s[i] == '*') len[i] = max(len[i-1]-1, 0ll);
            else if(s[i] == '#') len[i] = len[i-1] * 2ll;
            else if(s[i] == '%') len[i] = len[i-1];
            else len[i] = len[i-1] + 1;
        }
        for(int i = n; i >= 1; i--) {
            if(k >= len[i]) return '.';
            
            if(s[i] == '*') continue;
            else if(s[i] == '#') {
                if(k >= len[i]/2) k -= len[i]/2;
            } else if(s[i] == '%') {
                k = len[i] - 1 - k;
            } else {
                if(k == len[i]-1) return s[i];
            }
        }
        return '.';
    }
};