class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.size();
        int m = s2.size();
        if(s3.size() != n+m) return 0;
        vector<vector<bitset<2>>> dp(n+1, vector<bitset<2>>(m+1, 0));
        dp[0][0][0] = dp[0][0][1] = 1;
        for(int i = 0; i <= n; i++) {
            for(int j = 0; j <= m; j++) {
                for(int p = 0; p <= 1; p++) {
                    if(!dp[i][j][p]) continue;
                    if(p == 0) {
                        for(int k = i+1; k <= n; k++) {
                            if(s3[k+j-1] != s1[k-1]) break;
                            dp[k][j][1-p] = 1;
                        }
                    } else {
                        for(int k = j+1; k <= m; k++) {
                            if(s3[i+k-1] != s2[k-1]) break;
                            dp[i][k][1-p] = 1;
                        }
                    }
                }
            }
        }
        return dp[n][m][0] || dp[n][m][1];
    }
};