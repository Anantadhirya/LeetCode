class Solution {
public:
    int f(int x) {
        return (x+1)/2;
    }
    int countOdds(int low, int high) {
        return f(high) - f(low-1);
    }
};