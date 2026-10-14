class Solution {
public:
    int fp(int i, vector<int> &par) {
        if(par[i] == i) return i;
        return par[i] = fp(par[i], par);
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<array<int, 3>> edges;
        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                edges.push_back({abs(points[i][0]-points[j][0]) + abs(points[i][1]-points[j][1]), i, j});
            }
        }
        sort(edges.begin(), edges.end());
        vector<int> par(n);
        int ans = 0;
        for(int i = 0; i < n; i++) par[i] = i;
        for(auto &[w, u, v]: edges) {
            u = fp(u, par);
            v = fp(v, par);
            if(u != v) {
                par[u] = v;
                ans += w;
            }
        }
        return ans;
    }
};