class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        ios_base::sync_with_stdio(false); cin.tie(0);
        int n = grid.size();
        int m = grid[0].size();
        auto check = [&](int i, int j) {
            vector<int> sr(3, 0), sc(3, 0), d(2, 0);
            bitset<9> b = 0;
            for(int ii = 0; ii < 3; ii++) {
                for(int jj = 0; jj < 3; jj++) {
                    if(grid[i+ii][j+jj] < 1 || grid[i+ii][j+jj] > 9) return 0;
                    b[grid[i+ii][j+jj] - 1] = 1;
                    sr[ii] += grid[i+ii][j+jj];
                    sc[jj] += grid[i+ii][j+jj];
                    if(ii == jj) d[0] += grid[i+ii][j+jj];
                    if(ii == 2-jj) d[1] += grid[i+ii][j+jj];
                }
            }
            for(int ii = 0; ii < 9; ii++) {
                if(b[ii] == 0) return 0;
            }
            for(int ii = 0; ii < 3; ii++) {
                if(sr[ii] != sr[0]) return 0;
                if(sc[ii] != sr[0]) return 0;
            }
            if(d[0] != sr[0] || d[1] != sr[0]) return 0;
            return 1;
        };
        int ans = 0;
        for(int i = 0; i+2 < n; i++) {
            for(int j = 0; j+2 < m; j++) {
                ans += check(i, j);
            }
        }
        return ans;
    }
};