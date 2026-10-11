func minMoves2(nums []int) int {
    n := len(nums)
    suff := make([]int64, n+1)
    slices.Sort(nums)
    for i := n-1; i >= 0; i-- {
        suff[i] = suff[i+1] + int64(nums[i])
    }
    ans := int64(math.MaxInt64)
    for i := 0; i < n; i++ {
        ans = min(ans, int64(nums[i])*int64(i) - (suff[0] - suff[i]) + suff[i] - int64(nums[i])*int64(n-i))
    }
    return int(ans)
}