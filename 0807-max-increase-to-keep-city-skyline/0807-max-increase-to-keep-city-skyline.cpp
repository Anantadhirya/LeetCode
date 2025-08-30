const auto init = []() { ios_base::sync_with_stdio(false); cin.tie(0); return nullptr; }();

class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> r(n, 0), c(n, 0);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                r[i] = max(r[i], grid[i][j]);
                c[j] = max(c[j], grid[i][j]);
            }
        }
        int ans = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                ans += min(r[i], c[j]) - grid[i][j];
            }
        }
        return ans;
    }
};