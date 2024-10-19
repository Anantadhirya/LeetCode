class Solution {
public:
    char findKthBit(int n, int k) {
        int ans = 0;
        for(int i = (1<<20); i > 1; i >>= 1) {
            if(k > i) {
                ans ^= 1;
                k = i - (k-i);
            } else if(k == i) {
                ans ^= 1;
                break;
            }
        }
        return '0' + ans;
    }
};