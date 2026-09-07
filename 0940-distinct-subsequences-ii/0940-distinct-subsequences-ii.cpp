#define LL long long
class Solution {
public:
    int distinctSubseqII(string s) {
        const LL MOD = 1e9 + 7;
        vector<LL> lst(26, 0);
        LL ans = 1, tmp;
        for(char &c: s) {
            c -= 'a';
            tmp = ans;
            ans = (2*ans - lst[c] + MOD) % MOD;
            lst[c] = tmp;
        }
        return (ans-1+MOD) % MOD;
    }
};