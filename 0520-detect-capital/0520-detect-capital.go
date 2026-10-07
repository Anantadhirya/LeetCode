func detectCapitalUse(word string) bool {
    cap := 0
    lst := -1
    for i, c := range word {
        if 'A' <= c && c <= 'Z' {
            cap++
            lst = i
        }
    }
    return cap == 0 || cap == len(word) || (cap == 1 && lst == 0)
}