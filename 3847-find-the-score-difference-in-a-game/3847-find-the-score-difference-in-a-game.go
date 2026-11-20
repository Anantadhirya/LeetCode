func scoreDifference(nums []int) int {
    ans := 0
    cur := 0
    for i := range nums {
        if nums[i] % 2 == 1 { cur = 1-cur }
        if i % 6 == 5 { cur = 1-cur }
        if cur == 0 { ans += nums[i] } else { ans -= nums[i] }
    }
    return ans
}