class Solution {
public:
    int minBitFlips(int start, int goal) {
        ios_base::sync_with_stdio(false); cin.tie(0);
        int x = start ^ goal;
        int ans = 0;
        while(x) {
            ans += (x&1);
            x /= 2;
        }
        return ans;
    }
};