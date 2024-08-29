class Solution {
public:
    int fp(int i, vector<int> &par) {
        if(par[i] == i) return i;
        return par[i] = fp(par[i], par);
    }
    void join(int u, int v, vector<int> &par) {
        u = fp(u, par);
        v = fp(v, par);
        par[u] = v;
    }
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        vector<int> par(n);
        for(int i = 0; i < n; i++) {
            par[i] = i;
        }
        unordered_map<int, int> rr, cc;
        for(int i = 0, r, c; i < n; i++) {
            r = stones[i][0];
            c = stones[i][1];
            if(rr.count(r)) join(i, rr[r], par);
            if(cc.count(c)) join(i, cc[c], par);
            rr[r] = i;
            cc[c] = i;
        }
        int ans = n;
        for(int i = 0; i < n; i++) {
            if(fp(i, par) == i) ans--;
        }
        return ans;
    }
};