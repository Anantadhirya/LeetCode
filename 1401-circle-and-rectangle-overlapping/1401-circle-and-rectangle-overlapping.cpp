class Solution {
public:
    int dist(int x1, int y1, int x2, int y2) {
        return (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
    }
    int closest(int x1, int y1, int x2, int y2, int xC, int yC) {
        int x, y;
        if(y1 == y2) {
            y = y1;
            x = xC;
            x = max(x, x1);
            x = min(x, x2);
        } else {
            x = x1;
            y = yC;
            y = max(y, y1);
            y = min(y, y2);
        }
        return dist(xC, yC, x, y);
    }
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        if(x1 <= xCenter && xCenter <= x2 && y1 <= yCenter && yCenter <= y2) return 1;
        if(closest(x1, y1, x2, y1, xCenter, yCenter) <= radius*radius) return 1;
        if(closest(x1, y2, x2, y2, xCenter, yCenter) <= radius*radius) return 1;
        if(closest(x1, y1, x1, y2, xCenter, yCenter) <= radius*radius) return 1;
        if(closest(x2, y1, x2, y2, xCenter, yCenter) <= radius*radius) return 1;
        return 0;
    }
};