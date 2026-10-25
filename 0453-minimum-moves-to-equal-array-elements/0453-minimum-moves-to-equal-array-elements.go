func minMoves(nums []int) int {
    n := len(nums)
    slices.Sort(nums)
    ans := 0
    for i := n-2; i >= 0; i-- {
        ans += (nums[i+1]-nums[i]) * (n-1-i)
    }
    return ans
}