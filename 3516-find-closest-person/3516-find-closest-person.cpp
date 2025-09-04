class Solution {
public:
    int findClosest(int x, int y, int z) {
        x = abs(x-z);
        y = abs(y-z);
        if(x == y) return 0;
        if(x < y) return 1;
        return 2;
    }
};