class Solution {
public:
    string categorizeBox(int length, int width, int height, int mass) {
        long long l = length, w = width, h = height, m = mass;
        bool bulky = 0, heavy = 0;
        if(l >= 1e4 || w >= 1e4 || h >= 1e4 || l*w*h >= 1e9) bulky = 1;
        if(m >= 100) heavy = 1;
        if(bulky && heavy) return "Both";
        else if(!bulky && !heavy) return "Neither";
        else return bulky ? "Bulky" : "Heavy";
    }
};