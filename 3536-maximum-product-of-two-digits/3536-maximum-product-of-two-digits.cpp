class Solution {
public:
    int maxProduct(int n) {
        int mx = 0, ans = 0;
        while(n > 0) {
            ans = max(ans, n%10 * mx);
            mx = max(mx, n%10);
            n /= 10;
        }
        return ans;
    }
};