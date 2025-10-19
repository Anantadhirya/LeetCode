class Solution {
public:
    string findLexSmallestString(string s, int a, int b) {
        int n = s.size();
        string ans = s, tmp;
        for(int odd = 0; odd < 10; odd++) {
            for(int even = 0; even < 10; even++) {
                if((b % n) % 2 == 0 && even) continue;
                for(int cyc = 0; cyc < n; cyc++) {
                    tmp = s;
                    for(int i = 0; i < n; i++) {
                        tmp[i] = (s[(i+cyc*b) % n] - '0' + (i&1 ? odd : even) * a) % 10 + '0';
                    }
                    ans = min(ans, tmp);
                }
            }
        }
        return ans;
    }
};