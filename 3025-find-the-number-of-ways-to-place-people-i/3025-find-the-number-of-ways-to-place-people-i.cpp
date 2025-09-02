class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        bool valid;
        int ans = 0;
        for(int i = 0; i < points.size(); i++) {
            for(int j = 0; j < points.size(); j++) {
                if(i == j) continue;
                valid = points[i][0] <= points[j][0] && points[i][1] >= points[j][1];
                for(int k = 0; k < points.size() && valid; k++) {
                    if(k == i || k == j) continue;
                    if(points[i][0] <= points[k][0] && points[k][0] <= points[j][0] && points[i][1] >= points[k][1] && points[k][1] >= points[j][1]) {
                        valid = 0;
                    }
                }
                ans += valid;
            }
        }
        return ans;
    }
};