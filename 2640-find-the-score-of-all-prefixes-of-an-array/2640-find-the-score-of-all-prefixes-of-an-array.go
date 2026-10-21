func findPrefixScore(nums []int) []int64 {
    n := len(nums)
    ans := make([]int64, n)
    mx := 0
    sm := int64(0)
    for i := 0; i < n; i++ {
        mx = max(mx, nums[i])
        nums[i] = nums[i] + mx
        sm = sm + int64(nums[i])
        ans[i] = sm
    }
    return ans
}