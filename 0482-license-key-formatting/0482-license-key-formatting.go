func licenseKeyFormatting(s string, k int) string {
    v := make([]rune, 0)
    for _, c := range strings.ToUpper(s) {
        if c == '-' { continue }
        v = append(v, c)
    }
    ans := make([]rune, 0)
    n := len(v)
    for i := 1; i <= n; i++ {
        ans = append(ans, v[n-i])
        if i % k == 0 && i != n { ans = append(ans, '-') }
    }
    slices.Reverse(ans)
    return string(ans)
}