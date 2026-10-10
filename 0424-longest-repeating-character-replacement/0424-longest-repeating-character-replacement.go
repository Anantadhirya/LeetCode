func characterReplacement(s string, k int) int {
    ans := 0
    n := len(s)
    for c := 0; c < 26; c++ {
        for i, j, cnt := 0, 0, 0; i < n; i++ {
            if int(s[i]-'A') != c { cnt++ }
            for cnt > k {
                if int(s[j]-'A') != c { cnt-- }
                j++
            }
            ans = max(ans, i-j+1)
        }
    }
    return ans
}