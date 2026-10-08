func waysToMakeFair(nums []int) int {
    n := len(nums)
    suff := make([]int, n+1)
    for i := n-1; i >= 0; i-- {
        suff[i] = nums[i] - suff[i+1]
    }
    ans := 0
    for i, x := 0, 0; i < n; i++ {
        if i % 2 == 0 {
            x = suff[0] - suff[i] + suff[i+1]
        } else {
            x = suff[0] + suff[i] - suff[i+1]
        }
        if x == 0 { ans++ }
    }
    return ans
}