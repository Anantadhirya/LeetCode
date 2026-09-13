class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        int ans = 0;
        auto overlap = [&](int dx, int dy) -> int {
            int ret = 0;
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                    if(0 <= i+dx && i+dx < n && 0 <= j+dy && j+dy < n && img2[i][j] == 1 && img1[i+dx][j+dy] == 1) ret++;
                }
            }
            return ret;
        };
        for(int dx = -n; dx <= n; dx++) {
            for(int dy = -n; dy <= n; dy++) {
                ans = max(ans, overlap(dx, dy));
            }
        }
        return ans;
    }
};