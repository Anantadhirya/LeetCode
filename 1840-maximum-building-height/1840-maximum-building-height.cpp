class Solution {
public:
    int f(int x, int y1, int y2) {
        x -= abs(y1-y2);
        return max(y1, y2) + x/2;
    }
    int maxBuilding(int n, vector<vector<int>>& restrictions) {
        sort(restrictions.begin(), restrictions.end());
        int cur = 1, h = 0, new_h;
        int ans = 0;
        for(int i = restrictions.size()-2; i >= 0; i--) {
            restrictions[i][1] = min(restrictions[i][1], restrictions[i+1][1] + (restrictions[i+1][0] - restrictions[i][0]));
        }
        for(auto &i: restrictions) {
            new_h = min(i[1], h + i[0]-cur);
            ans = max(ans, f(i[0]-cur, h, new_h));
            cur = i[0];
            h = new_h;
        }
        ans = max(ans, f(n-cur, h, h+n-cur));
        return ans;
    }
};