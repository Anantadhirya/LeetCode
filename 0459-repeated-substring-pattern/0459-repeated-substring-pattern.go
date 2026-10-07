func check(s string, k int) bool {
    for i := range s {
        if s[i] != s[i%k] { return false }
    }
    return true
}
func repeatedSubstringPattern(s string) bool {
    n := len(s)
    for i := 1; i*i <= n; i++ {
        if n % i != 0 { continue }
        if i != n && check(s, i) { return true }
        if i != 1 && check(s, n/i) { return true }
    }
    return false
}