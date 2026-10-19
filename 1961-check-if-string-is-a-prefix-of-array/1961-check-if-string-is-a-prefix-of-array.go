func isPrefixString(s string, words []string) bool {
    cur := make([]rune, 0)
    for len(cur) < len(s) {
        if len(words) == 0 { return false }
        for _, c := range words[0] {
            cur = append(cur, c)
        }
        words = words[1:]
    }
    return string(cur) == s
}