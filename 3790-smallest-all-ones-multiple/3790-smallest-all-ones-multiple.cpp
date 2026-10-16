class Solution {
public:
    int minAllOneMultiple(int k) {
        // 10*n+1
        int n = 1;
        for(int i = 1; i <= k+5; i++) {
            if(n == 0) return i;
            n = (10*n+1)%k;
        }
        return -1;
    }
};