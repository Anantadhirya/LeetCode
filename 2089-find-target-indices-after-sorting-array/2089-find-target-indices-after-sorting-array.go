func targetIndices(nums []int, target int) []int {
    n := len(nums)
    ans := make([]int, 0, n)
    slices.Sort(nums)
    for i := 0; i < n; i++ {
        if nums[i] == target { ans = append(ans, i) }
    }
    return ans
}