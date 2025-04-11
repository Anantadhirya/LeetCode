class Solution {
public:
    int solve(int x) {
        int ret = 0;
        // 2-digit
        for(int i = 1; i <= 9; i++) {
            ret += (10*i + i <= x);
        }
        // 4-digit
        for(int i = 10, sm; i <= 99; i++) {
            if(100*i > x) continue;
            sm = i/10 + i%10;
            for(int j = 0, k; j <= 9; j++) {
                k = sm - j;
                if(k < 0 || k > 9) continue;
                if(100*i + 10*j + k <= x) ret++;
            }
        }
        return ret;
    }
    int countSymmetricIntegers(int low, int high) {
        return solve(high) - solve(low-1);
    }
};