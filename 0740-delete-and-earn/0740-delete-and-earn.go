func deleteAndEarn(nums []int) int {
    m := make(map[int]int, len(nums))
    for _, i := range nums { m[i]++ }
    v := make([][]int, 0, len(m))
    for i, c := range m { v = append(v, []int{i, c}) }
    slices.SortFunc(v, slices.Compare)
    n := len(v)
    dp := make([]int, n)
    for i := 0; i < n; i++ {
        dp[i] = v[i][0] * v[i][1]
        if i-1 >= 0 && v[i-1][0] < v[i][0]-1 { dp[i] = max(dp[i], v[i][0] * v[i][1] + dp[i-1]) }
        if i-2 >= 0 && v[i-2][0] < v[i][0]-1 { dp[i] = max(dp[i], v[i][0] * v[i][1] + dp[i-2]) }
        if i-1 >= 0 { dp[i] = max(dp[i], dp[i-1]) }
    }
    return dp[n-1]
}