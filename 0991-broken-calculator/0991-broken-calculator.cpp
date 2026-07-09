class Solution {
public:
    int brokenCalc(int startValue, int target) {
        int tmp = 0, ans = 0;
        long long x = startValue;
        while(x < target) tmp++, x *= 2;
        x -= target;
        ans = tmp;
        for(int i = 0; i < tmp; i++) {
            if(x&1) ans++;
            x >>= 1;
        }
        return ans + x;
    }
};