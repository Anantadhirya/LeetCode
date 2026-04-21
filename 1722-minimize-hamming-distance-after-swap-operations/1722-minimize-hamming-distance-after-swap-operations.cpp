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
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n = source.size();
        vector<int> par(n);
        vector<map<int, int>> cnt(n);
        int ans = 0;
        for(int i = 0; i < n; i++) par[i] = i;
        for(auto i: allowedSwaps) {
            join(i[0], i[1], par);
        }
        for(int i = 0; i < n; i++) {
            cnt[fp(i, par)][source[i]]++;
        }
        for(int i = 0; i < n; i++) {
            if(cnt[fp(i, par)][target[i]]-- > 0) continue;
            ans++;
        }
        return ans;
    }
};