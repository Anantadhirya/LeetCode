class Solution {
public:
    const int key = 461;
    const int MOD = 1e9 + 7;
    bool containsPattern(vector<int>& arr, int m, int k) {
        int keyM = 1;
        int n = arr.size();
        for(int i = 0; i < m; i++) {
            keyM = ((long long)keyM * key) % MOD;
        }
        vector<int> v(n, 0);
        v[0] = arr[0];
        for(int i = 1; i < n; i++) {
            v[i] = ((long long)key * v[i-1] % MOD + arr[i]) % MOD;
        }
        for(int i = n-1; i >= m; i--) {
            v[i] = ((long long)v[i] - (long long)v[i-m] * keyM % MOD + MOD) % MOD;
        }
        for(int i = m-1; i < n; i++) {
            arr[i] = 1 + (i-m >= m-1 && v[i-m] == v[i] ? arr[i-m] : 0);
            if(arr[i] >= k) return 1;
        }
        return 0;
    }
};