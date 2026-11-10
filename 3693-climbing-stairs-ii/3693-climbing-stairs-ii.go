func climbStairs(n int, costs []int) int {
    inf := math.MaxInt
    dp := make([]int, n+1)
    for i := 1; i <= n; i++ {
        dp[i] = inf
        for j := i-3; j <= i-1; j++ {
            if j >= 0 { dp[i] = min(dp[i], costs[i-1] + dp[j] + (i-j)*(i-j)) }
        }
    }
    return dp[n]
}