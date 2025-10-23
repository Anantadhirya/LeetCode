class Solution {
public:
    void mul(int &a, int &p, int val, int mod, bool inv) {
        int inv5[] = {0, 1, 3, 2, 4};
        while(val % mod == 0) {
            val /= mod;
            p += (!inv ? 1 : -1);
        }
        (a *= (!inv || mod == 2 ? val%mod : inv5[val%mod])) %= mod;
    }
    bool hasSameDigits(string s) {
        int n = s.size();
        int ans2 = 0, ans5 = 0;
        int C2 = 1, C5 = 1, p2 = 0, p5 = 0;
        for(int i = 0; i <= n-2; i++) {
            // ans += C * (s[i] - s[i+1])
            if(p2 == 0) (ans2 += C2 * ((s[i] - s[i+1])%2 + 2) % 2) %= 2;
            if(p5 == 0) (ans5 += C5 * ((s[i] - s[i+1])%5 + 5) % 5) %= 5;
            if(i == n-2) break;
            // C = C * (n-2-i) / (i+1)
            mul(C2, p2, n-2-i, 2, 0);
            mul(C2, p2, i+1, 2, 1);
            mul(C5, p5, n-2-i, 5, 0);
            mul(C5, p5, i+1, 5, 1);
        }
        return ans2 == 0 && ans5 == 0;
    }
};