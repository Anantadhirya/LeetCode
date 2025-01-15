class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int n = __builtin_popcount(num2);
        int ans = 0;
        for(int i = 30; i >= 0 && n > 0; i--) {
            if((num1>>i)&1) ans += (1<<i), n--;
        }
        for(int i = 0; i <= 30 && n > 0; i++) {
            if((ans>>i)&1) continue;
            ans += (1<<i), n--;
        }
        return ans;
    }
};