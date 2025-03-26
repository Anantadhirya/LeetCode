class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> v;
        for(const auto &row: grid) {
            for(const int &i: row) {
                v.push_back(i);
                if(i % x != v[0] % x) return -1;
            }
        }
        int n = v.size();
        vector<int> pref(n+1, 0);
        int ans = INT_MAX;
        sort(v.begin(), v.end());
        for(int i = 0; i < n; i++) {
            v[i] /= x;
            pref[i+1] = v[i] + pref[i];
        }
        for(int i = 1; i <= n; i++) {
            ans = min(ans, (i * v[i-1] - pref[i]) + (pref[n] - pref[i] - (n - i) * v[i-1]));
        }
        return ans;
    }
};