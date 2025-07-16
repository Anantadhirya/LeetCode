class Solution {
public:
    int concatenatedBinary(int n) {
        int ans = 0;
        const int MOD = 1e9 + 7;
        for(int i = n, x, tmp = 1; i >= 1; i--) {
            for(x = i; x > 0; x /= 2) {
                if(x&1) ans = (ans + tmp) % MOD;
                tmp = 2*tmp % MOD; 
            }
        }
        return ans;
    }
};