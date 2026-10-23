func sortPermutation(nums []int) int {
    n := len(nums)
    v := slices.Clone(nums)
    slices.Sort(v)
    ans := -1
    for i := 0; i < n; i++ {
        if v[i] == nums[i] { continue }
        if ans == -1 { ans = nums[i] } else { ans = ans & nums[i] }
    }
    if ans == -1 { return 0 }
    return ans
}