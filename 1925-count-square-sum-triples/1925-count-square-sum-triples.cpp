class Solution {
public:
    int countTriples(int n) {
        int ans = 0;
        for(int a = 1, c; a <= n; a++) {
            for(int b = 1; b <= n; b++) {
                c = sqrt(a*a + b*b);
                if(1 <= c && c <= n) ans += (a*a + b*b == c*c);
            }
        }
        return ans;
    }
};