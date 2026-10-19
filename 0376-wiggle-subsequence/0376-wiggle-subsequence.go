func wiggleMaxLength(nums []int) int {
    n := len(nums)
    st1 := make([]int, n)
    st2 := make([]int, n)
    top1 := -1
    top2 := -1
    dp := make([][2]int, n)
    ans := 0
    for i := 0; i < n; i++ {
        for top1 != -1 && nums[st1[top1]] <= nums[i] { top1-- }
        for top2 != -1 && nums[st2[top2]] >= nums[i] { top2-- }
        dp[i] = [2]int{1, 1}
        if top1 != -1 { dp[i][0] = max(dp[i][0], 1 + dp[st1[top1]][1]); dp[i][1] = max(dp[i][1], dp[st1[top1]][1]) }
        if top2 != -1 { dp[i][1] = max(dp[i][1], 1 + dp[st2[top2]][0]); dp[i][0] = max(dp[i][0], dp[st2[top2]][0]) }
        top1++
        top2++
        st1[top1] = i
        st2[top2] = i
        ans = max(ans, dp[i][0], dp[i][1])
    }
    return ans
}