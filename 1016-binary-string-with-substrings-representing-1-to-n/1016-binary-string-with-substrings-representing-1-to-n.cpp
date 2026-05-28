class Solution {
public:
    bool queryString(string s, int n) {
        const int MX = 31 * 1000 + 10;
        if(n >= MX) return 0;
        int m = s.size();
        bitset<MX> b;
        for(int i = 0; i < m; i++) {
            for(int j = 0, x = 0; j < 31 && i+j < m; j++) {
                x = 2*x + (s[i+j] == '1');
                if(x < MX) b[x] = 1;
            }
        }
        for(int i = 1; i <= n; i++) {
            if(!b[i]) return 0;
        }
        return 1;
    }
};