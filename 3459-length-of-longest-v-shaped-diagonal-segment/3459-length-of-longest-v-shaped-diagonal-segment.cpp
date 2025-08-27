class Solution {
public:
    int lenOfVDiagonal(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> v1, v2, v3, v4;
        v1 = v2 = v3 = v4 = vector<vector<int>>(n, vector<int>(m, 0));
        int ans = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1) continue;
                if(i-1 >= 0 && j-1 >= 0 && grid[i-1][j-1] + grid[i][j] == 2) v1[i][j] += v1[i-1][j-1] + 1;
                if(i-1 >= 0 && j+1 < m && grid[i-1][j+1] + grid[i][j] == 2) v2[i][j] += v2[i-1][j+1] + 1;
            }
        }
        for(int i = n-1; i >= 0; i--) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1) continue;
                if(i+1 < n && j-1 >= 0 && grid[i+1][j-1] + grid[i][j] == 2) v3[i][j] += v3[i+1][j-1] + 1;
                if(i+1 < n && j+1 < m && grid[i+1][j+1] + grid[i][j] == 2) v4[i][j] += v4[i+1][j+1] + 1;
            }
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] != 1) continue;
                ans = max(ans, 1);
                for(int ii = i+1, jj = j+1; 0 <= ii && ii < n && 0 <= jj && jj < m && grid[ii][jj] != 1 && grid[ii][jj] != grid[ii-1][jj-1]; ii++, jj++) {
                    if(ii == i+1 && grid[ii][jj] != 2) break;
                    ans = max(ans, 1+(ii-i)+v3[ii][jj]);
                }
                for(int ii = i-1, jj = j-1; 0 <= ii && ii < n && 0 <= jj && jj < m && grid[ii][jj] != 1 && grid[ii][jj] != grid[ii+1][jj+1]; ii--, jj--) {
                    if(ii == i-1 && grid[ii][jj] != 2) break;
                    ans = max(ans, 1+(i-ii)+v2[ii][jj]);
                }
                for(int ii = i+1, jj = j-1; 0 <= ii && ii < n && 0 <= jj && jj < m && grid[ii][jj] != 1 && grid[ii][jj] != grid[ii-1][jj+1]; ii++, jj--) {
                    if(ii == i+1 && grid[ii][jj] != 2) break;
                    ans = max(ans, 1+(ii-i)+v1[ii][jj]);
                }
                for(int ii = i-1, jj = j+1; 0 <= ii && ii < n && 0 <= jj && jj < m && grid[ii][jj] != 1 && grid[ii][jj] != grid[ii+1][jj-1]; ii--, jj++) {
                    if(ii == i-1 && grid[ii][jj] != 2) break;
                    ans = max(ans, 1+(i-ii)+v4[ii][jj]);
                }
            }
        }
        return ans;
    }
};