class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        for(auto &i: points) {
            i[1] = -i[1];
        }
        sort(points.begin(), points.end());
        for(auto &i: points) {
            i[1] = -i[1];
        }
        int ans = 0, y;
        for(int i = 0; i < points.size(); i++) {
            y = -INT_MAX;
            for(int j = i+1; j < points.size(); j++) {
                if(y < points[j][1] && points[j][1] <= points[i][1]) {
                    y = points[j][1];
                    ans++;
                }
            }
        }
        return ans;
    }
};