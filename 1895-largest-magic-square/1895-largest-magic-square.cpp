class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> pref, pref2;
        pref = pref2 = vector<vector<int>>(n, vector<int>(m, 0));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                pref[i][j] = grid[i][j] + (i-1 >= 0 ? pref[i-1][j] : 0);
                pref2[i][j] = grid[i][j] + (j-1 >= 0 ? pref2[i][j-1] : 0);
            }
        }
        int sm, tmp;
        auto check = [&](int r, int c, int k) -> bool {
            sm = tmp = 0;
            for(int i = 0; i < k; i++) {
                sm += grid[r+i][c+i];
                tmp += grid[r+i][c+k-1-i];
            }
            if(tmp != sm) return 0;
            for(int i = 0; i < k; i++) {
                if(pref[r+k-1][c+i] - (r-1 >= 0 ? pref[r-1][c+i] : 0) != sm) return 0;
                if(pref2[r+i][c+k-1] - (c-1 >= 0 ? pref2[r+i][c-1] : 0) != sm) return 0;
            }
            return 1;
        };
        for(int k = min(n, m); k >= 1; k--) {
            for(int i = 0; i+k-1 < n; i++) {
                for(int j = 0; j+k-1 < m; j++) {
                    if(check(i, j, k)) return k;
                }
            }
        }
        return -1;
    }
};