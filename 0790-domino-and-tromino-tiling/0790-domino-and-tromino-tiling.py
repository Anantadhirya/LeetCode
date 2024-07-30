class Solution:
    def numTilings(self, n: int) -> int:
        mod = int(1e9 + 7)
        dp = [[0 for _ in range(2)] for i in range(n+5)]
        dp[0][0] = 1
        for i in range(n):
            dp[i+1][0] += dp[i][0] + 2*dp[i][1]
            dp[i+1][0] %= mod
            
            dp[i+1][1] += dp[i][1]
            dp[i+1][1] %= mod
            
            dp[i+2][0] += dp[i][0]
            dp[i+2][0] %= mod
            
            dp[i+2][1] += dp[i][0]
            dp[i+2][0] %= mod
        return dp[n][0]