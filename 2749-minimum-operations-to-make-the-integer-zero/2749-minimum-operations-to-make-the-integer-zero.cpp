class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        // popcount(num1 - k*num2) <= k
        for(long long k = 1, x = num1 - num2; x >= 0; k++, x -= num2) {
            if(__builtin_popcountll(x) <= k && k <= x) return k;
        }
        return -1;
    }
};