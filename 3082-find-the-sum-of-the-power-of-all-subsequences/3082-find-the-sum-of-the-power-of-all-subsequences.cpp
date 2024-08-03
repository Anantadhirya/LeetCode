class Solution {
public:
    int sumOfPower(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(false); cin.tie(0);
        const long long MOD = 1e9 + 7;
        int n = nums.size();
        vector<long long> p(n+5);
        vector<vector<long long>> dp(k+5, vector<long long>(n+5, 0));
        p[0] = 1;
        for(int i = 1; i <= n; i++) {
            p[i] = (p[i-1] * 2) % MOD;
        }
        long long ans = 0;
        dp[0][0] = 1;
        for(const int &x: nums) {
            if(x <= k) {
                for(int i = 0; i < n; i++) {
                    (ans += dp[k-x][i] * p[n-(i+1)] % MOD) %= MOD;
                }
            }
            for(int i = n; i >= 1; i--) {
                for(int j = k; j >= x; j--) {
                    (dp[j][i] += dp[j-x][i-1]) %= MOD;
                }
            }
        }
        return ans;
    }
};