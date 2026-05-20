class Solution {
public:
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
        vector<vector<bool>> grid(n, vector<bool>(n, 1));
        for(auto i: mines) {
            grid[i[0]][i[1]] = 0;
        }
        int ans = 0;
        bool valid;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 0) continue;
                valid = 1;
                ans = max(ans, 1);
                for(int k = 1; k < n; k++) {
                    if(i+k >= n || grid[i+k][j] == 0) valid = 0;
                    if(j+k >= n || grid[i][j+k] == 0) valid = 0;
                    if(i-k < 0 || grid[i-k][j] == 0) valid = 0;
                    if(j-k < 0 || grid[i][j-k] == 0) valid = 0;
                    if(valid) ans = max(ans, k+1);
                    else break;
                }
            }
        }
        return ans;
    }
};