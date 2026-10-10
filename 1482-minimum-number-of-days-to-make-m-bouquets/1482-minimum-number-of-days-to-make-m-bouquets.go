func minDays(b []int, m int, k int) int {
    ans := -1
    n := len(b)
    check := func(day int) bool {
        tot := 0
        for i, con := 0, 0; i < n; i++ {
            if b[i] <= day {
                con++
                if con >= k {
                    tot++
                    con = 0
                }
            } else {
                con = 0
            }
        }
        return tot >= m
    }
    for l, r, mid := 0, slices.Max(b), 0; l <= r; {
        mid = (l+r)/2
        if check(mid) {
            ans = mid
            r = mid - 1
        } else { l = mid + 1 }
    }
    return ans
}