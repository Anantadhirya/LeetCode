class Solution {
public:
    int fp(int i, vector<int> &par) {
        if(par[i] == i) return i;
        return par[i] = fp(par[i], par);
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> par(n);
        int u, v;
        for(int i = 0; i < n; i++) par[i] = i;
        for(const auto &i: edges) {
            u = fp(i[0]-1, par);
            v = fp(i[1]-1, par);
            if(u != v) {
                par[u] = v;
            } else return i;
        }
        return {};
    }
};