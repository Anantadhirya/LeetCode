class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        map<pair<int, int>, bool> m;
        int dx[] = {0, 1, 0, -1};
        int dy[] = {1, 0, -1, 0};
        int d = 0, x = 0, y = 0, ans = 0;
        for(const auto &i: obstacles) {
            m[{i[0], i[1]}] = 1;
        }
        for(const auto &i: commands) {
            if(i == -2) d = (d-1+4)%4;
            else if(i == -1) d = (d+1)%4;
            else {
                for(int j = 0; j < i; j++) {
                    if(m[{x+dx[d], y+dy[d]}]) break;
                    x += dx[d];
                    y += dy[d];
                }
                ans = max(ans, x*x + y*y);
            }
        }
        return ans;
    }
};