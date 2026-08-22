class Solution {
public:
    bool checkDivisibility(int n) {
        int sm = 0, prod = 1;
        for(int x = n; x > 0; x /= 10) {
            sm += x%10;
            prod *= x%10;
        }
        return n % (sm + prod) == 0;
    }
};