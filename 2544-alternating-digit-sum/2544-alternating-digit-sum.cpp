class Solution {
public:
    int alternateDigitSum(int n) {
        ios_base::sync_with_stdio(false); cin.tie(0);
        int ans = 0;
        while(n) {
            ans = -ans + n%10;
            n /= 10;
        }
        return ans;
    }
};