func longestPrefix(s string) string {
    n := len(s)
    z := make([]int, n)
    for i, l, r := 1, 0, 0; i < n; i++ {
        if i < r { z[i] = min(r-i, z[i-l]) }
        for i + z[i] < n && s[z[i]] == s[i + z[i]] { z[i]++ }
        if i + z[i] > r { l = i; r = i + z[i] }
    }
    ans := n
    for i := n-1; i >= 1; i-- {
        if z[i] == n-i { ans = i }
    }
    return s[ans:]
}