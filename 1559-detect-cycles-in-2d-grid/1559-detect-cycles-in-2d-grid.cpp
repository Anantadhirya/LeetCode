class Solution {
public:
    int fp(int i, vector<int> &par) {
        if(par[i] == i) return i;
        return par[i] = fp(par[i], par);
    }
    bool join(int u, int v, vector<int> &par) {
        u = fp(u, par);
        v = fp(v, par);
        if(u == v) return 0;
        par[u] = v;
        return 1;
    }
    bool containsCycle(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<int> par(n*m);
        for(int i = 0; i < n*m; i++) {
            par[i] = i;
        }
        auto idx = [&](int i, int j) -> int {
            return i*m + j;
        };
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(i+1 < n && grid[i][j] == grid[i+1][j]) if(!join(idx(i, j), idx(i+1, j), par)) return 1;
                if(j+1 < m && grid[i][j] == grid[i][j+1]) if(!join(idx(i, j), idx(i, j+1), par)) return 1;
            }
        }
        return 0;
    }
};