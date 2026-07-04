class Solution {
public:
    int fp(int i, vector<int> &par) {
        if(par[i] == i) return i;
        return par[i] = fp(par[i], par);
    }
    int minScore(int n, vector<vector<int>>& roads) {
        vector<int> par(n), ans(n, INT_MAX);
        int u, v, w;
        for(int i = 0; i < n; i++) par[i] = i;
        for(auto &i: roads) {
            u = i[0]-1, v = i[1]-1, w = i[2];
            u = fp(u, par), v = fp(v, par);
            par[u] = v;
            ans[v] = min(ans[v], ans[u]);
            ans[v] = min(ans[v], w);
        }
        return ans[fp(0, par)];
    }
};