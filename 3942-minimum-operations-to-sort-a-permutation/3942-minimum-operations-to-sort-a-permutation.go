func minOperations(nums []int) int {
    n := len(nums)
    idx := -1
    for i := 0; i < n; i++ { if nums[i] == 0 { idx = i }}
    inc_valid := true
    dec_valid := true
    for i := 0; i+1 < n; i++ {
        if nums[(idx+i)%n] > nums[(idx+i+1)%n] { inc_valid = false }
        if nums[(idx-i+n)%n] > nums[(idx-i-1+n)%n] { dec_valid = false }
    }
    inf := math.MaxInt
    ans := inf
    if inc_valid { ans = min(ans, idx, 1 + ((n-1-idx)+1) + 1) }
    if dec_valid { ans = min(ans, idx+1 + 1, 1 + (n-1-idx)) }
    if ans == inf { return -1 }
    return ans
}