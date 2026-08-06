class Solution {
public:
    int prod(int x) {
        int ret = 1;
        while(x > 0) {
            ret *= x%10;
            x /= 10;
        }
        return ret;
    }
    int smallestNumber(int n, int t) {
        while(prod(n) % t != 0) n++;
        return n;
    }
};