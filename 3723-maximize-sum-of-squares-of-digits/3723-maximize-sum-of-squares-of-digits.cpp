class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        string ans(num, '0');
        for(int i = 0; i < num; i++) {
            ans[i] = min(9, sum) + '0';
            sum -= (ans[i] - '0');
        }
        return sum == 0 ? ans : "";
    }
};