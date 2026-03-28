class Solution {
public:
    int fp(int i, vector<int> &par) {
        if(par[i] == i) return i;
        return par[i] = fp(par[i], par);
    }
    void join(int u, int v, vector<int> &par) {
        u = fp(par[u], par);
        v = fp(par[v], par);
        par[u] = v;
    }
    string findTheString(vector<vector<int>>& lcp) {
        int n = lcp.size();
        vector<int> par(n);
        vector<int> c(n, -1);
        int t = 0;
        string ans(n, ' ');
        for(int i = 0; i < n; i++) par[i] = i;
        
        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                for(int k = 0; k < lcp[i][j]; k++) {
                    if(j+k >= n) return "";
                    join(i+k, j+k, par);
                }
            }
        }
        for(int i = 0, j; i < n; i++) {
            j = fp(i, par);
            if(c[j] == -1) {
                if(t >= 26) return "";
                c[j] = t++;
            }
            ans[i] = 'a'+c[j];
        }
        // cout << ans << "\n";
        for(int i = n-1; i >= 0; i--) {
            for(int j = n-1; j >= 0; j--) {
                t = (ans[i] == ans[j] ? 1 + (i+1 < n && j+1 < n ? lcp[i+1][j+1] : 0) : 0);
                if(lcp[i][j] != t) return "";
            }
        }
        return ans;
    }
};