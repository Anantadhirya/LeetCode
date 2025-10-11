class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        int n = power.size();
        sort(power.begin(), power.end());
        map<int, int> m;
        for(int i: power) {
            m[i]++;
        }
        vector<long long> dp(n, 0);
        long long pref = 0, ans = 0;
        for(int i = 0, j = 0; i < n; i++) {
            while(j < i && power[j] < power[i] - 2) {
                pref = max(pref, dp[j]);
                j++;
            }
            dp[i] = (long long)power[i]*m[power[i]] + pref;
            // cout << i << " " << j << " " << pref << "\n";
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};