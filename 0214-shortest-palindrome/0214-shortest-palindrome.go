func shortestPalindrome(s string) string {
    n := len(s)
    key := int64(461)
    MOD := int64(1e9 + 7)
    
    pangkat := make([]int64, n+5)
    pref := make([]int64, n+5)
    suff := make([]int64, n+5)
    pangkat[0] = 1
    for i := 1; i <= n; i++ {
        pangkat[i] = (pangkat[i-1] * key) % MOD
    }
    for i := 1; i <= n; i++ {
        pref[i] = pref[i-1]*key % MOD + int64(s[i-1]-'a')
        pref[i] %= MOD
    }
    for i := n; i >= 1; i-- {
        suff[i] = suff[i+1]*key % MOD + int64(s[i-1]-'a')
        suff[i] %= MOD
    }

    palindrome := func(l int, r int) bool {
        p := pangkat[r-l+1]
        return (pref[r] - pref[l-1]*p%MOD + MOD) % MOD == (suff[l] - suff[r+1]*p%MOD + MOD) % MOD
    }

    ans := 0
    for i := 1; i <= n; i++ {
        if palindrome(1, i) {
            ans = i
        }
    }
    add := make([]byte, 0, n)
    for i := n; i > ans; i-- {
        add = append(add, s[i-1])
    }
    return string(add) + s
}