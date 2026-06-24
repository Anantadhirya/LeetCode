class Solution {
public:
    const int MOD = 1e9 + 7;
    vector<vector<int>> mul(int m, vector<vector<int>> &a, vector<vector<int>> &b) {
        vector<vector<int>> ret(m, vector<int>(m, 0));
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < m; j++) {
                for(int k = 0; k < m; k++) {
                    (ret[i][j] += (long long)a[i][k] * b[k][j] % MOD) %= MOD;
                }
            }
        }
        return ret;
    }
    vector<vector<int>> matpow(int m, vector<vector<int>> &mat, int x) {
        vector<vector<int>> ret(m, vector<int>(m, 0));
        for(int i = 0; i < m; i++) ret[i][i] = 1;
        while(x > 0) {
            if(x&1) ret = mul(m, ret, mat);
            mat = mul(m, mat, mat);
            x /= 2;
        }
        return ret;
    }
    int zigZagArrays(int n, int l, int r) {
        int m = (r-l+1);
        vector<vector<int>> v(2*m, vector<int>(2*m, 0)), ans;

        for(int i = 0, ii, pi; i < 2*m; i++) {
            ii = i % m, pi = i >= m;
            for(int j = 0, jj, pj; j < 2*m; j++) {
                jj = j % m, pj = j >= m;
                if(ii == jj) continue;
                if(pj != (ii > jj)) continue;
                if(pi == pj) continue;
                v[i][j] = 1;
            }
        }

        ans = matpow(2*m, v, n-1);
        int ret = 0;
        for(int i = 0; i < 2*m; i++) {
            for(int j = 0; j < 2*m; j++) {
                (ret += ans[i][j]) %= MOD;
            }
        }
        return ret;
    }
};