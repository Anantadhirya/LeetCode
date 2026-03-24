class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        const int MOD = 12345;
        vector<int> r, rpref, rsuff;
        vector<vector<int>> cpref, csuff;
        r = rpref = rsuff = vector<int>(n, 1);
        cpref = csuff = vector<vector<int>>(n, vector<int>(m, 1));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) cpref[i][j] = ((long long)grid[i][j] * (j-1 >= 0 ? cpref[i][j-1] : 1)) % MOD;
            for(int j = m-1; j >= 0; j--) csuff[i][j] = ((long long)grid[i][j] * (j+1 < m ? csuff[i][j+1] : 1)) % MOD;
            r[i] = cpref[i][m-1];
            rpref[i] = ((long long)r[i] * (i-1 >= 0 ? rpref[i-1] : 1)) % MOD;
        }
        for(int i = n-1; i >= 0; i--) {
            rsuff[i] = ((long long)r[i] * (i+1 < n ? rsuff[i+1] : 1)) % MOD;
            for(int j = 0; j < m; j++) {
                grid[i][j] = 1;
                if(i-1 >= 0) grid[i][j] = ((long long)grid[i][j] * rpref[i-1]) % MOD;
                if(i+1 < n) grid[i][j] = ((long long)grid[i][j] * rsuff[i+1]) % MOD;
                if(j-1 >= 0) grid[i][j] = ((long long)grid[i][j] * cpref[i][j-1]) % MOD;
                if(j+1 < m) grid[i][j] = ((long long)grid[i][j] * csuff[i][j+1]) % MOD;
            }
        }
        return grid;
    }
};