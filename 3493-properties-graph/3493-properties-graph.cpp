class Solution {
public:
    int fp(int i, vector<int> &par) {
        if(par[i] == i) return i;
        return par[i] = fp(par[i], par);
    }
    int numberOfComponents(vector<vector<int>>& properties, int k) {
        int n = properties.size();
        int ans = 0;
        vector<bitset<100>> b(n);
        vector<int> par(n);
        for(int i = 0, u, v; i < n; i++) {
            par[i] = i;
            for(const auto &j: properties[i]) {
                b[i].set(j-1);
            }
            for(int j = 0; j < i; j++) {
                if((b[i] & b[j]).count() >= k) {
                    u = fp(i, par);
                    v = fp(j, par);
                    par[u] = v;
                }
            }
        }
        for(int i = 0; i < n; i++) {
            ans += fp(i, par) == i;
        }
        return ans;
    }
};