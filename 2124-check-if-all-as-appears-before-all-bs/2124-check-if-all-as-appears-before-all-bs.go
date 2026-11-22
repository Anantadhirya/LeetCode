func checkString(s string) bool {
    lstA := -1
    fiB := -1
    for i := range s {
        if s[i] == 'a' { lstA = i }
        if s[i] == 'b' && fiB == -1 { fiB = i }
    }
    return fiB == -1 || lstA < fiB
}