int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

const auto init = []() { ios_base::sync_with_stdio(false); cin.tie(0); return NULL; }();

class Solution {
public:
    int fp(int i, vector<int> &par) {
        if(par[i] == i) return i;
        return par[i] = fp(par[i], par);
    }
    void join(int u, int v, vector<int> &par, vector<int> &sz) {
        u = fp(u, par), v = fp(v, par);
        if(u != v) {
            par[u] = v;
            sz[v] += sz[u];
            sz[u] = 0;
        }
    }
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int k = n*n;
        vector<int> par(k), sz(k);
        int ans = 0, tmp;
        unordered_set<int> s;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                par[n*i+j] = n*i+j;
                sz[n*i+j] = grid[i][j];
            }
        }
        for(int i = 0; i < k; i++) {
            par[i] = i;
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(!grid[i][j]) continue;
                if(j+1 < n && grid[i][j+1]) join(n*i + j, n*i + (j+1), par, sz);
                if(i+1 < n && grid[i+1][j]) join(n*i + j, n*(i+1) + j, par, sz);
            }
        }
        for(int i = 0; i < k; i++) {
            if(fp(i, par) == i) ans = max(ans, sz[i]);
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j]) continue;
                tmp = 1;
                s.clear();
                for(int d = 0, ii, jj, idx, group; d < 4; d++) {
                    ii = i + dx[d];
                    jj = j + dy[d];
                    idx = n*ii + jj;
                    if(0 <= ii && ii < n && 0 <= jj && jj < n && grid[ii][jj]) {
                        group = fp(idx, par);
                        if(s.count(group)) continue;
                        tmp += sz[group];
                        s.insert(group);
                    }
                }
                ans = max(ans, tmp);
            }
        }
        return ans;
    }
};