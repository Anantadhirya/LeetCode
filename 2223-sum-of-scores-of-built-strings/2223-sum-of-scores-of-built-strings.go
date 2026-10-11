func sumScores(s string) int64 {
    n := len(s)
    z := make([]int, n)
    for i, l, r := 1, 0, 0; i < n; i++ {
        if i < r { z[i] = min(r-i, z[i-l]) }
        for i+z[i] < n && s[i+z[i]] == s[z[i]] { z[i]++ }
        if i+z[i] > r { l = i; r = i+z[i] }
    }
    z[0] = n
    ans := int64(0)
    for _, i := range z { ans += int64(i) }
    return ans
}