func smallestUniqueSubarray(nums []int) int {
    n := len(nums)
    key := int64(461)
    mod := int64(1e9+7)
    suff := make([]int64, n+1)
    p := make([]int64, n+1)
    p[0] = 1
    for i := 1; i <= n; i++ { p[i] = p[i-1] * key % mod }
    for i := n-1; i >= 0; i-- {
        suff[i] = (suff[i+1] * key % mod + int64(nums[i]-'0'))
    }
    check := func(len int) bool {
        m := make(map[int64]int, n)
        for i, tmp := 0, int64(0); i+len-1 < n; i++ {
            tmp = (suff[i] - suff[i+len] * p[len] % mod + mod) % mod
            m[tmp]++
        }
        for _, c := range m {
            if c == 1 { return true }
        }
        return false
    }
    ans := n
    for l, r, mid := 1, n, 0; l <= r; {
        mid = (l+r)/2
        if check(mid) {
            ans = mid
            r = mid - 1
        } else { l = mid + 1 }
    }
    return ans
}