class Solution {
public:
    int trailingZeroes(int n) {
        int p2 = 0, p5 = 0;
        for(int i = 1, x; i <= n; i++) {
            x = i;
            while(x % 2 == 0) x /= 2, p2++;
            while(x % 5 == 0) x /= 5, p5++;
        }
        return min(p2, p5);
    }
};