func pangkat(a, b, MOD int64) int64 {
    if b == 0 { return int64(1) }
    if b % 2 == 0 { return pangkat(a*a%MOD, b>>1, MOD) }
    return a * pangkat(a*a%MOD, b>>1, MOD) % MOD
}

func sumDecoded(nums []int64) int {
    ans := int64(0)
    MOD := int64(1e9 + 7)
    for _, i := range nums {
        width := i % 10
        s := strconv.FormatInt(i, 10)
        x, _ := strconv.ParseInt(s[0:width], 10, 64)
        y, _ := strconv.ParseInt(s[width:], 10, 64)
        y /= 10
        ans += pangkat(x, y, MOD)
        ans %= MOD
    }
    return int(ans)
}