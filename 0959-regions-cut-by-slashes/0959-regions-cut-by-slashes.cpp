class Solution {
public:
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    void dfs(int i, int j, int &n, vector<vector<int>> &v) {
        v[i][j] = 1;
        for(int d = 0, ii, jj; d < 4; d++) {
            ii = i + dx[d];
            jj = j + dy[d];
            if(0 <= ii && ii < 3*n && 0 <= jj && jj < 3*n && v[ii][jj] == 0) {
                dfs(ii, jj, n, v);
            }
        }
    }
    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();
        vector<vector<int>> v(3*n, vector<int>(3*n, 0));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == ' ') continue;
                if(grid[i][j] == '/') {
                    v[3*i+2][3*j] = 1;
                    v[3*i+1][3*j+1] = 1;
                    v[3*i][3*j+2] = 1;
                } else {
                    v[3*i][3*j] = 1;
                    v[3*i+1][3*j+1] = 1;
                    v[3*i+2][3*j+2] = 1;
                }
            }
        }
        int ans = 0;
        for(int i = 0; i < 3*n; i++) {
            for(int j = 0; j < 3*n; j++) {
                if(v[i][j] == 0) {
                    ans++;
                    dfs(i, j, n, v);
                }
            }
        }
        return ans;
    }
};