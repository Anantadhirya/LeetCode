class Solution {
public:
    long long sumAndMultiply(int n) {
        string s = to_string(n);
        int x = 0, sm = 0;
        for(char &c: s) {
            if(c == '0') continue;
            x = x*10 + (c-'0');
            sm += (c-'0');
        }
        return (long long)x*sm;
    }
};