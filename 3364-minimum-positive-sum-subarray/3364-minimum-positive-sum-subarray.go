func minimumSumSubarray(nums []int, l int, r int) int {
    inf := math.MaxInt
    ans := inf
    n := len(nums)
    for i := 0; i < n; i++ {
        for j, sm := i, 0; j < n; j++ {
            sm += nums[j]
            if sm > 0 && l <= j-i+1 && j-i+1 <= r { ans = min(ans, sm) }
        }
    }
    if ans == inf { return -1 }
    return ans 
}