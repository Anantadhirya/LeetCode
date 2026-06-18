class Solution {
public:
    double angleClock(int hour, int minutes) {
        double h = hour / 12.0 * 360.0 + minutes / 60.0 * 30.0;
        double m = minutes / 60.0 * 360.0;
        double diff = abs(m - h);
        return min(diff, 360.0 - diff);
    }
};