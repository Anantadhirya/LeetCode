class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
        int cnt0, cnt1, ans = 0;
        dp[0][0] = 0;
        for(auto i: strs) {
            cnt0 = cnt1 = 0;
            for(auto c: i) {
                if(c == '0') cnt0++;
                else cnt1++;
            }
            for(int a = m; a >= cnt0; a--) {
                for(int b = n; b >= cnt1; b--) {
                    if(dp[a-cnt0][b-cnt1] != -1) {
                        dp[a][b] = max(dp[a][b], dp[a-cnt0][b-cnt1] + 1);
                        ans = max(ans, dp[a][b]);
                    }
                }
            }
        }
        return ans;
    }
};