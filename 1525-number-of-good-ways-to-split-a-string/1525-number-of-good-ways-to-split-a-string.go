func numSplits(s string) int {
    freq1 := make([]int, 26)
    freq2 := make([]int, 26)
    cnt1, cnt2 := 0, 0
    n := len(s)
    ans := 0
    for _, i := range s {
        c := int(i-'a')
        freq2[c]++
        if freq2[c] == 1 { cnt2++ }
    }
    for i := 0; i <= n-2; i++ {
        c := int(s[i]-'a')
        freq2[c]--
        if freq2[c] == 0 { cnt2-- }
        freq1[c]++
        if freq1[c] == 1 { cnt1++ }
        if cnt1 == cnt2 { ans++ }
    }
    return ans
}