func maximumSaleItems(items [][]int, budget int) int {
    n := len(items)
    w := make([]int, n)
    for i := 0; i < n; i++ {
        for j := 0; j < n; j++ {
            if items[j][0] % items[i][0] == 0 { w[i]++ }
        }
    }
    dp := make([][2]int, budget+1)
    for i := 0; i < n; i++ {
        for j := 0; j <= budget; j++ {
            if j - items[i][1] >= 0 {
                dp[j][1] = max(dp[j][1], dp[j-items[i][1]][0] + w[i])
                dp[j][1] = max(dp[j][1], dp[j-items[i][1]][1] + 1)
            }
        }
        for j := 0; j <= budget; j++ {
            dp[j][0] = max(dp[j][0], dp[j][1])
            dp[j][1] = 0
        }
    }
    return dp[budget][0]
}