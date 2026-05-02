class Solution {
public:
    bool good(int x) {
        bool valid = 0;
        for(; x > 0; x /= 10) {
            if(x%10 == 0 || x%10 == 1 || x%10 == 8) continue;
            if(x%10 == 2 || x%10 == 5 || x%10 == 6 || x%10 == 9) valid = 1;
            else return 0;
        }
        return valid;
    }
    int rotatedDigits(int n) {
        int ans = 0;
        for(int i = 1; i <= n; i++) {
            ans += good(i);
        }
        return ans;
    }
};