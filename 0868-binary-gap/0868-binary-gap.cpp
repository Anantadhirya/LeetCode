class Solution {
public:
    int binaryGap(int n) {
        int ans = 0, cur = -1;
        while(n > 0) {
            if(n&1) {
                ans = max(ans, cur);
                cur = 1;
            } else if(cur != -1) cur++;
            n >>= 1;
        }
        return ans;
    }
};