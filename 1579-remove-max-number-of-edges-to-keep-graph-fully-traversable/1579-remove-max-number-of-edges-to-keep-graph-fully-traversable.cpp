class Solution {
public:
    int fp(int i, vector<int> &par) {
        if(par[i] == i) return i;
        return par[i] = fp(par[i], par);
    }
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        vector<vector<int>> par(3, vector<int>(n));
        int u, v;
        int ans = 0;
        for(int i = 0; i < n; i++) {
            par[0][i] = i;
        }
        for(const auto &i: edges) {
            if(i[0] == 3) {
                u = fp(i[1]-1, par[0]);
                v = fp(i[2]-1, par[0]);
                par[0][u] = v;
            }
        }
        for(int i = 0; i < n; i++) {
            if(fp(i, par[0]) == i) ans++;
        }
        par[1] = par[2] = par[0];
        for(const auto &i: edges) {
            if(i[0] == 1 || i[0] == 2) {
                u = fp(i[1]-1, par[i[0]]);
                v = fp(i[2]-1, par[i[0]]);
                par[i[0]][u] = v;
            }
        }
        for(int i = 0; i < n; i++) {
            if(fp(i, par[1]) != fp(0, par[1])) return -1;
            if(fp(i, par[2]) != fp(0, par[2])) return -1;
        }
        ans = (n - ans) + 2*(ans - 1);
        return edges.size() - ans;
    }
};