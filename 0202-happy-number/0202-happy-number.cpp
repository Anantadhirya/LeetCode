class Solution {
public:
    map<int, int> memo;
    bool isHappy(int n) {
        if(n == 1) return memo[n] = 1;
        if(memo.count(n)) return memo[n];
        memo[n] = 0;
        int sm = 0;
        while(n) {
            sm += (n%10)*(n%10);
            n /= 10;
        }
        return memo[n] = isHappy(sm);
    }
};