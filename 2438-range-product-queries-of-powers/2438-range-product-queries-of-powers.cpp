class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        const int MOD = 1e9 + 7;
        vector<int> p;
        for(int i = 1; i <= n; i <<= 1) {
            if(n&i) p.push_back(i%MOD);
        }
        int k = p.size();
        vector<vector<int>> v(k, vector<int>(k, 1));
        for(int i = 0; i < k; i++) {
            v[i][i] = p[i];
            for(int j = i+1; j < k; j++) {
                v[i][j] = (long long)v[i][j-1] * p[j] % MOD;
            }
        }
        int m = queries.size();
        vector<int> ans(m);
        for(int i = 0; i < m; i++) {
            ans[i] = v[queries[i][0]][queries[i][1]];
        }
        return ans;
    }
};