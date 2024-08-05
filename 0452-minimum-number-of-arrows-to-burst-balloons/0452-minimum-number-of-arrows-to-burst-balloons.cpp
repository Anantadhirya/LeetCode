class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        ios_base::sync_with_stdio(false); cin.tie(0);
        sort(points.begin(), points.end());
        long long lst = LLONG_MAX;
        int ans = 0;
        for(int i = points.size()-1; i >= 0; i--) {
            if(points[i][1] < lst) {
                lst = points[i][0];
                ans++;
            }
        }
        return ans;
    }
};