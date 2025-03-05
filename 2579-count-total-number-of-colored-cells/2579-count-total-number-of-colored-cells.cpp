class Solution {
public:
    long long coloredCells(int n) {
        return (long long)4*(n)*(n-1)/2 + 1;
    }
};