class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<int> ans = {-1, -1, -1};
        int tmp;
        for(int r = max(m, n); r >= 0; r--) {
            for(int i = r; i < n-r; i++) {
                for(int j = r; j < m-r; j++) {
                    tmp = 0;
                    for(int k = 0; k < r; k++) {
                        tmp += grid[i-r+k][j+k];
                        tmp += grid[i+k][j+r-k];
                        tmp += grid[i+r-k][j-k];
                        tmp += grid[i-k][j-r+k];
                    }
                    if(r == 0) tmp = grid[i][j];
                    if(tmp == ans[0] || tmp == ans[1] || tmp == ans[2]) continue;
                    ans[2] = max(ans[2], tmp);
                    if(ans[1] < ans[2]) swap(ans[1], ans[2]);
                    if(ans[0] < ans[1]) swap(ans[0], ans[1]);
                }
            }
        }
        while(ans.back() == -1) ans.pop_back();
        return ans;
    }
};