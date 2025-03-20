class Solution {
public:
    int fp(int i, vector<int> &par) {
        if(par[i] == i) return i;
        return par[i] = fp(par[i], par);
    }
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        const int inf = (1<<25) - 1;
        vector<int> par(n), ans(n);
        vector<int> ret;
        for(int i = 0; i < n; i++) {
            par[i] = i;
            ans[i] = inf;
        }
        for(auto &i: edges) {
            int u = i[0], v = i[1], w = i[2];
            u = fp(u, par);
            v = fp(v, par);
            par[u] = v;
            ans[v] = ans[u] & ans[v] & w;
        }
        for(auto &i: query) {
            int s = i[0], t = i[1];
            if(s == t) {
                ret.push_back(0);
                continue;
            }
            s = fp(s, par);
            t = fp(t, par);
            if(s == t) {
                ret.push_back(ans[s]);
            } else ret.push_back(-1);
        }
        return ret;
    }
};