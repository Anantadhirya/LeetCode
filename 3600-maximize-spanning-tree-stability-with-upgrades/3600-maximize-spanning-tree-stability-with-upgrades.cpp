class Solution {
public:
    int fp(int i, vector<int> &par) {
        if(par[i] == i) return i;
        return par[i] = fp(par[i], par);
    }
    int maxStability(int n, vector<vector<int>>& edges, int k) {
        int l = 0, r = 2e5, mid, ans = -1;
        int u, v, s, m;
        vector<int> par(n);
        for(auto &i: edges) {
            swap(i[0], i[2]);
            if(i[3] == 1) r = min(r, i[0]);
        }
        sort(edges.rbegin(), edges.rend());

        auto check = [&](int x) -> bool {
            int up = 0, e = 0;
            for(int i = 0; i < n; i++) par[i] = i;
            for(auto &i: edges) {
                s = i[0], u = fp(i[1], par), v = fp(i[2], par), m = i[3];
                if(m == 1) {
                    if(u == v) return 0;
                    par[u] = v;
                    e++;
                }
            }
            for(auto &i: edges) {
                s = i[0], u = fp(i[1], par), v = fp(i[2], par), m = i[3];
                if(m == 1 || u == v) continue;
                if(2*s >= x) {
                    if(s < x) up++;
                    par[u] = v;
                    e++;
                }
            }
            return e == n-1 && up <= k;
        };

        while(l <= r) {
            mid = (l+r)/2;
            if(check(mid)) {
                ans = mid;
                l = mid + 1;
            } else r = mid - 1;
        }
        return ans;
    }
};