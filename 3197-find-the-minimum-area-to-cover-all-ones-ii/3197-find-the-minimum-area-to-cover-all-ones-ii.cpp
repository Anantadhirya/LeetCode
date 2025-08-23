#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")
class Solution {
public:
    inline bool check(vector<int> &mni, vector<int> &mxi, vector<int> &mnj, vector<int> &mxj) {
        for(int i = 0; i < 3; i++) {
            for(int j = i+1; j < 3; j++) {
                if(!(mxi[i] < mni[j] || mxi[j] < mni[i] || mxj[i] < mnj[j] || mxj[j] < mnj[i])) return 0;
            }
        }
        return 1;
    }
    inline void solve(vector<vector<int>> &grid, int &ans) {
        int n = grid.size(), m = grid[0].size();
        int t;
        vector<int> mni, mxi, mnj, mxj;
        
        for(int i = 0; i < n; i++) {
            for(int j = i; j < n; j++) {
                mni = mnj = vector<int>(3, 40);
                mxi = mxj = vector<int>(3, -1);
                for(int ii = 0; ii < n; ii++) {
                    for(int jj = 0; jj < m; jj++) {
                        if(grid[ii][jj]) {
                            if(ii < i) t = 0;
                            else if(ii > j) t = 1;
                            else t = 2;
                            update(ii, jj, mni[t], mxi[t], mnj[t], mxj[t]);
                        }
                    }
                }
                if(mni[0] != -1 && mni[1] != -1 && mni[2] != -1 && check(mni, mxi, mnj, mxj)) {
                    ans = min(ans, calc(mni, mxi, mnj, mxj));
                }
            }
        }
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                // batas vertikal
                mni = mnj = vector<int>(3, 40);
                mxi = mxj = vector<int>(3, -1);
                for(int ii = 0; ii < n; ii++) {
                    for(int jj = 0; jj < m; jj++) {
                        if(grid[ii][jj]) {
                            if(ii <= i) t = 0;
                            else if(jj <= j) t = 1;
                            else t = 2;
                            update(ii, jj, mni[t], mxi[t], mnj[t], mxj[t]);
                        }
                    }
                }
                if(mni[0] != -1 && mni[1] != -1 && mni[2] != -1 && check(mni, mxi, mnj, mxj)) {
                    ans = min(ans, calc(mni, mxi, mnj, mxj));
                }
                // batas horizontal
                mni = mnj = vector<int>(3, 40);
                mxi = mxj = vector<int>(3, -1);
                for(int ii = 0; ii < n; ii++) {
                    for(int jj = 0; jj < m; jj++) {
                        if(grid[ii][jj]) {
                            if(jj <= j) t = 0;
                            else if(ii <= i) t = 1;
                            else t = 2;
                            update(ii, jj, mni[t], mxi[t], mnj[t], mxj[t]);
                        }
                    }
                }
                if(mni[0] != -1 && mni[1] != -1 && mni[2] != -1 && check(mni, mxi, mnj, mxj)) {
                    ans = min(ans, calc(mni, mxi, mnj, mxj));
                }
            }
        }
    }
    inline void update(int i, int j, int &mni, int &mxi, int &mnj, int &mxj) {
        mni = min(mni, i);
        mxi = max(mxi, i);
        mnj = min(mnj, j);
        mxj = max(mxj, j);
    }
    inline int calc(vector<int> &mni, vector<int> &mxi, vector<int> &mnj, vector<int> &mxj) {
        int ret = 0;
        for(int t = 0; t < 3; t++) {
            ret += (mxi[t] - mni[t] + 1) * (mxj[t] - mnj[t] + 1);
        }
        return ret;
    }
    int minimumSum(vector<vector<int>>& grid) {
        ios_base::sync_with_stdio(false); cin.tie(0);
        int n = grid.size(), m = grid[0].size();
        int ans = n * m;
        vector<vector<int>> tmpgrid;
        for(int k = 0; k < 4; k++) {
            solve(grid, ans);
            n = grid.size(), m = grid[0].size();
            tmpgrid.assign(m, vector<int>(n));
            for(int i = 0; i < m; i++) {
                for(int j = 0; j < n; j++) {
                    tmpgrid[i][j] = grid[n-j-1][i];
                }
            }
            grid = tmpgrid;
        }
        return ans;
    }
};