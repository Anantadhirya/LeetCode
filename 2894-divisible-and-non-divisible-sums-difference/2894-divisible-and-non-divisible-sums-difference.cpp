class Solution {
public:
    int differenceOfSums(int n, int m) {
        int cnt = n/m;
        int num2 = (m + m*cnt) * cnt / 2;
        int num1 = n*(n+1)/2 - num2;
        return num1 - num2;
    }
};