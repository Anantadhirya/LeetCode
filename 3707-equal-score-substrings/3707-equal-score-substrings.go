func scoreBalance(s string) bool {
    n := len(s)
    pref := make([]int, n)
    pref[0] = int(s[0]-'a'+1)
    for i := 1; i < n; i++ {
        pref[i] = pref[i-1] + int(s[i]-'a'+1)
    }
    for i := 0; i < n; i++ {
        if pref[i] == pref[n-1] - pref[i] { return true }
    }
    return false
}