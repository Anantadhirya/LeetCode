func countWordOccurrences(chunks []string, queries []string) []int {
    s := strings.Join(chunks, "")
    n := len(s)
    cnt := make(map[string]int)
    tmp := make([]byte, 0)
    isAlpha := func(c byte) bool {
        return 'a' <= c && c <= 'z'
    }
    for i := 0; i < n; i++ {
        if isAlpha(s[i]) {
            tmp = append(tmp, s[i])
        } else if s[i] == '-' && i-1 >= 0 && i+1 < n && isAlpha(s[i-1]) && isAlpha(s[i+1]) {
            tmp = append(tmp, s[i])
        } else if len(tmp) > 0 {
            cnt[string(tmp)]++
            tmp = tmp[:0]
        }
    }
    if len(tmp) > 0 { cnt[string(tmp)]++ }
    ans := make([]int, len(queries))
    for i, s := range queries {
        ans[i] = cnt[s]
    }
    return ans
}