func removeOuterParentheses(s string) string {
    v := make([]rune, 0, len(s))
    x := 0
    for _, c := range s {
        if c == '(' {
            x++
            if x == 1 { continue }
        } else {
            x--
            if x == 0 { continue }
        }
        v = append(v, c)
    }
    return string(v)
}