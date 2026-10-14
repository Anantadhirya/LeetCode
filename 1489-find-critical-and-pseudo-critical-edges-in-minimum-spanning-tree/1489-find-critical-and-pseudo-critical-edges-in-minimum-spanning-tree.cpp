class Solution {
public:
    int fp(int i, vector<int> &par) {
        if(par[i] == i) return i;
        return par[i] = fp(par[i], par);
    }
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        vector<int> par(n);
        int u, v;
        int m = edges.size();
        vector<vector<int>> arr(m);
        for(int i = 0; i < m; i++) {
            arr[i] = {edges[i][2], edges[i][0], edges[i][1], i};
        }
        sort(arr.begin(), arr.end());

        auto mst = [&](int inc, int exc) -> int {
            int ret = 0;
            for(int i = 0; i < n; i++) {
                par[i] = i;
            }
            if(inc != -1) {
                ret += edges[inc][2];
                u = fp(edges[inc][0], par);
                v = fp(edges[inc][1], par);
                par[u] = v;
            }
            for(auto &i: arr) {
                if(i[3] == exc) continue;
                u = fp(i[1], par);
                v = fp(i[2], par);
                if(u != v) {
                    par[u] = v;
                    ret += i[0];
                }
            }
            for(int i = 0; i < n; i++) {
                if(fp(i, par) != fp(0, par)) return INT_MAX;
            }
            return ret;
        };

        int mn = mst(-1, -1);
        vector<vector<int>> ans(2);
        for(int i = 0, inc, exc; i < m; i++) {
            if(mst(-1, i) > mn) ans[0].push_back(i);
            else if(mst(i, -1) == mn) ans[1].push_back(i);
        }
        return ans;
    }
};