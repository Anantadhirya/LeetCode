class Solution {
public:
    bool hasSameDigits(string s) {
        int n = s.size();
        for(char &c: s) c -= '0';
        for(int i = n-2; i >= 1; i--) {
            for(int j = 0; j <= i; j++) {
                s[j] = (s[j] + s[j+1]) % 10;
            }
        }
        return s[0] == s[1];
    }
};