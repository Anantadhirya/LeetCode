func splitArray(nums []int) int64 {
    n := len(nums)
    suff_inc := make([]int, n)
    suff_dec := make([]int, n)
    suff := make([]int64, n+1)
    for i := n-1; i >= 0; i-- { suff[i] = suff[i+1] + int64(nums[i]) }
    for i := n-2; i >= 0; i-- {
        suff_inc[i] = suff_inc[i+1]
        suff_dec[i] = suff_dec[i+1]
        if nums[i] < nums[i+1] { suff_inc[i]++ }
        if nums[i] > nums[i+1] { suff_dec[i]++ }
    }
    inc := func(l, r int) bool {
        if l > r { return true }
        return suff_inc[l] - suff_inc[r] == r-l
    }
    dec := func(l, r int) bool {
        if l > r { return true }
        return suff_dec[l] - suff_dec[r] == r-l
    }
    sm := func(l, r int) int64 {
        return suff[l] - suff[r+1]
    }
    abs := func(x int64) int64 {
        if x >= 0 { return x } else { return -x }
    }
    inf := int64(math.MaxInt64)
    ans := int64(inf)
    for i := 0; i+1 < n; i++ {
        if inc(0, i) && dec(i+1, n-1) {
            ans = min(ans, abs(sm(0, i) - sm(i+1, n-1)))
        }
    }
    if ans == inf { return -1 }
    return ans
}