func integerBreak(n int) int {
    if n == 2 { return 1 }
    if n == 3 { return 2 }
    dp := make([]int, n+1)
    dp[0] = 1
    for i := 1; i <= n; i++ {
        for j := 1; j <= i; j++ {
            dp[i] = max(dp[i], j * dp[i-j])
        }
    }
    return dp[n]
}