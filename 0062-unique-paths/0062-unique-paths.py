class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        dp = [[0 for j in range(m+5)] for i in range(n+5)]
        dp[0][0] = 1
        for i in range(n):
            for j in range(m):
                dp[i+1][j] += dp[i][j]
                dp[i][j+1] += dp[i][j]
        return dp[n-1][m-1]