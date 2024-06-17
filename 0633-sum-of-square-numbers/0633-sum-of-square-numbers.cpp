class Solution {
public:
    bool judgeSquareSum(int c) {
        for(long long a = 0, b; a*a <= c; a++) {
            b = sqrt(c - a*a);
            if(a*a + b*b == c) return 1;
        }
        return 0;
    }
};