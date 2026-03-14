class Solution {
public:
    int longestString(int x, int y, int z) {
        x = min(x, y+1);
        y = min(y, x+1);
        return 2*(x+y+z);
    }
};