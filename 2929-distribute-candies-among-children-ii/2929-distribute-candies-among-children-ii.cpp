class Solution {
public:
    long long f(long long n) {
        if(n < 0) return 0;
        return (n+2) * (n+1) / 2;
    }
    long long distributeCandies(int n, int limit) {
        limit++;
        return f(n) - 3*f(n - limit) + 3*f(n - 2*limit) - f(n - 3*limit);
    }
};