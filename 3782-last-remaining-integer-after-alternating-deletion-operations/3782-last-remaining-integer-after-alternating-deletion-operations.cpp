class Solution {
public:
    long long solve(long long n, bool left) {
        if(n == 1) return 1;
        long long x = solve((n+1)/2, 1-left);
        if(n % 2 == 1 || left) return 2*x-1;
        else return 2*x; 
    }
    long long lastInteger(long long n) {
        return solve(n, 1);
    }
};