func prefixConnected(words []string, k int) int {
    m := make(map[string]int)
    ans := 0
    for _, word := range words {
        if len(word) < k { continue }
        word = word[:k]
        if m[word] == 1 { ans++ }
        m[word]++
    }
    return ans
}