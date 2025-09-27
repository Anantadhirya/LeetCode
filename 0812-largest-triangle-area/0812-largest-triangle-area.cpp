class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        double ans = 0, tmp;
        int n = points.size();
        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                for(int k = j+1; k < n; k++) {
                    tmp = (points[i][0] - points[k][0])*(points[j][1] - points[k][1]) - (points[i][1] - points[k][1])*(points[j][0] - points[k][0]);
                    ans = max(ans, abs(tmp)/2);
                }
            }
        }
        return ans;
    }
};