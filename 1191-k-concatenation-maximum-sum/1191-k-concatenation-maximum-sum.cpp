class Solution {
public:
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        int n = arr.size();
        long long ans = 0;
        long long MOD = 1e9 + 7;
        vector<long long> pref(n+1, 0);
        for(int i = 1; i <= n; i++) {
            pref[i] = pref[i-1] + arr[i-1];
        }
        // Case 1: within the same duplicate
        long long mx = 0;
        for(int r = 1; r <= n; r++) {
            ans = max(ans, pref[r] + (pref[n] > 0 ? pref[n] * (k-1) : 0) + mx);
            mx = max(mx, -pref[r]);
        }
        // Case 2: from different duplicate
        if(k >= 2) {
            for(int r = 1; r <= n; r++) {
                ans = max(ans, pref[r] + pref[n] + (pref[n] > 0 ? pref[n] * (k-2) : 0) + mx);
                mx = max(mx, -pref[r]-pref[n]);
            }
        }
        return ans % MOD;
    }
};