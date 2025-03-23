class Solution {
public:
    int fp(int i, vector<int> &par) {
        if(par[i] == i) return i;
        return par[i] = fp(par[i], par);
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<int> par(n), adj(n, 0), sz(n, 1);
        vector<bool> valid(n, 1);
        int u, v;
        int ans = 0;
        for(int i = 0; i < n; i++) {
            par[i] = i;
        }
        for(const auto &i: edges) {
            adj[i[0]]++;
            adj[i[1]]++;
            u = fp(i[0], par);
            v = fp(i[1], par);
            if(u != v) {
                par[u] = v;
                sz[v] += sz[u];
                sz[u] = 0;
            }
        }
        for(int i = 0, p; i < n; i++) {
            p = fp(i, par);
            if(adj[i] != sz[p] - 1) valid[p] = 0;
        }
        for(int i = 0; i < n; i++) {
            ans += (fp(i, par) == i && valid[i]);
        }
        return ans;
    }
};