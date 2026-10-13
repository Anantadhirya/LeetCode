func maxAlternatingSum(nums []int) int64 {
    for i := range nums {
        if nums[i] < 0 { nums[i] = -nums[i] }
    }
    slices.Sort(nums)
    n := len(nums)
    ans := int64(0)
    for i := 0; i < n; i++ {
        if i < n/2 {
            ans -= int64(nums[i]) * int64(nums[i])
        } else { ans += int64(nums[i]) * int64(nums[i]) }
    }
    return ans
}