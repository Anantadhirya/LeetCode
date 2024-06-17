class Solution {
public:
    bool judgeSquareSum(int c) {
        ios_base::sync_with_stdio(false); cin.tie(0);
        for(long long a = 0, b; a*a <= c; a++) {
            b = sqrt(c - a*a);
            if(a*a + b*b == c) return 1;
        }
        return 0;
    }
};