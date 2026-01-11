int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

class Solution {
public:
    bool isRobotBounded(string instructions) {
        int x = 0, y = 0, d = 0;
        for(char c: instructions) {
            if(c == 'G') x += dx[d], y += dy[d];
            else if(c == 'L') d = (d+1)%4;
            else if(c == 'R') d = (d+3)%4;
        }
        return d != 0 || (x == 0 && y == 0);
    }
};