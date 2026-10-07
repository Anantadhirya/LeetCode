func repeatedStringMatch(a string, b string) int {
    var s []rune
    for len(s) < len(b) {
        for _, c := range a {
            s = append(s, c)
        }
    }
    s2 := string(s)
    if strings.Contains(s2, b) { return len(s)/len(a) }
    for _, c := range a {
        s = append(s, c)
    }
    s2 = string(s)
    if strings.Contains(s2, b) { return len(s)/len(a) }
    return -1
}