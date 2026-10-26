func sumOfLargestPrimes(s string) int64 {
    prime := func(x int64) bool {
        if x == 1 { return false }
        for i := int64(2); i*i <= x; i++ {
            if x % i == 0 { return false }
        }
        return true
    }

    n := len(s)
    cur := int64(0)
    ans := [3]int64{0, 0, 0}
    for i := 0; i < n; i++ {
        cur = 0
        for j := i; j < n; j++ {
            cur = 10*cur + int64(s[j]-'0')
            if prime(cur) {
                if cur == ans[0] || cur == ans[1] || cur == ans[2] { continue }
                if cur > ans[2] { ans[2] = cur }
                if ans[2] > ans[1] { ans[1], ans[2] = ans[2], ans[1] }
                if ans[1] > ans[0] { ans[0], ans[1] = ans[1], ans[0] }
            }
        }
    }
    return ans[0] + ans[1] + ans[2]
}