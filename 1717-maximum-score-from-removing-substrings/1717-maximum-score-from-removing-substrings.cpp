class Solution {
public:
    int maximumGain(string s, int x, int y) {
        ios_base::sync_with_stdio(false); cin.tie(0);
        string s1, s2;
        string p = (x >= y ? "ab" : "ba");
        if(y > x) swap(x, y);
        int ans = 0;
        for(const char &c: s) {
            if(!s1.empty() && s1.back() == p[0] && c == p[1]) {
                ans += x;
                s1.pop_back();
            } else s1.push_back(c);
        }
        for(const char &c: s1) {
            if(!s2.empty() && s2.back() == p[1] && c == p[0]) {
                ans += y;
                s2.pop_back();
            } else s2.push_back(c);
        }
        return ans;
    }
};