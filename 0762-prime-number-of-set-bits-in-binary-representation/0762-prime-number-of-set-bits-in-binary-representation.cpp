class Solution {
public:
    bool prime(int x) {
        if(x == 1) return 0;
        for(int i = 2; i*i <= x; i++) {
            if(x % i == 0) return 0;
        }
        return 1;
    }
    int countPrimeSetBits(int left, int right) {
        int ans = 0;
        for(int i = left; i <= right; i++) {
            ans += (prime(__builtin_popcount(i)));
        }
        return ans;
    }
};