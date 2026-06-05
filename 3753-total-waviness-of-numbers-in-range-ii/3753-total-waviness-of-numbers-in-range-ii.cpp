class Solution {
public:
    long long f(long long x) {
        if(x <= 0) return 0;
        string s = to_string(x);
        int n = s.size();
        long long ans = 0;
        vector<vector<vector<vector<long long>>>> dp(n+1, vector<vector<vector<long long>>>(2, vector<vector<long long>>(11, vector<long long>(11, 0))));
        vector<vector<long long>> dp2(n+1, vector<long long>(2, 0));
        dp2[n][0] = dp2[n][1] = 1;
        // cout << x << ":\n";
        for(int i = n-1, d; i >= 0; i--) {
            d = s[i]-'0';
            dp2[i][0] = 10 * dp2[i+1][0];
            dp2[i][1] = d * dp2[i+1][0] + dp2[i+1][1];
        }
        dp[0][1][10][10] = 1;
        for(int i = 0, d; i < n; i++) {
            d = s[i]-'0';
            for(int t = 0; t <= 1; t++) {
                for(int a = 0; a <= 10; a++) {
                    for(int b = 0; b <= 10; b++) {
                        if(dp[i][t][a][b] == 0) continue;
                        for(int c = 0, tt, cc; c <= 9; c++) {
                            if(t && c > d) continue;
                            cc = (b == 10 && c == 0 ? 10 : c);
                            tt = t && cc == d;
                            dp[i+1][tt][b][cc] += dp[i][t][a][b];
                            if(a != 10) {
                                if(a > b && b < c || a < b && b > c) {
                                    ans += dp[i][t][a][b] * dp2[i+1][tt];
                                    // cout << i << " " << a << b << c << " -> " << dp[i][t][a][b] << " * " << dp2[i+1][tt] << "\n";
                                }
                            }
                        }
                    }
                }
            }
        }
        return ans;
    }
    long long totalWaviness(long long num1, long long num2) {
        return f(num2) - f(num1-1);
    }
};