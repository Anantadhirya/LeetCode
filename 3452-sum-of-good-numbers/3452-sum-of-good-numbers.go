func sumOfGoodNumbers(nums []int, k int) int {
    n := len(nums)
    good := false
    ans := 0
    for i := 0; i < n; i++ {
        good = true
        if i-k >= 0 && nums[i-k] >= nums[i] { good = false }
        if i+k < n && nums[i+k] >= nums[i] { good = false }
        if good { ans += nums[i] }
    }
    return ans
}