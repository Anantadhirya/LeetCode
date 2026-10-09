func minInsertions(s string) int {
    n := len(s)
    ans := 0
    x := 0
    for i := 0; i < n; i++ {
        if s[i] == '(' {
            x++
        } else {
            if i+1 < n && s[i+1] == ')' { i++ } else { ans++ }
            x--
            if x < 0 { x++; ans++ }
        }
    }
    ans += 2*x
    return ans
}