func divisibilityArray(word string, m int) []int {
    n := len(word)
    ans := make([]int, n)
    cur := 0
    for i := 0; i < n; i++ {
        cur = (10*cur + int(word[i]-'0')) % m
        if cur == 0 { ans[i] = 1 } else { ans[i] = 0 }
    }
    return ans
}