func minimizeSum(nums []int) int {
    slices.Sort(nums)
    ans := math.MaxInt
    for i := 0; i <= 2; i++ {
        ans = min(ans, nums[len(nums)-3+i] - nums[i])
    }
    return ans
}