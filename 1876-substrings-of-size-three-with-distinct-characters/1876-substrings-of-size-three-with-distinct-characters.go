func countGoodSubstrings(s string) int {
    n := len(s)
    ans := 0
    for i := 0; i+2 < n; i++ {
        if s[i] == s[i+1] || s[i] == s[i+2] || s[i+1] == s[i+2] { continue }
        ans++
    }
    return ans
}