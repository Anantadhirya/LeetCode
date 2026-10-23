func mostFrequentEven(nums []int) int {
    m := make(map[int]int, len(nums))
    for _, i := range nums { if i % 2 == 0 { m[i]++ } }
    mx := 0
    ans := -1
    for i, c := range m {
        if c > mx { mx = c; ans = i }
        if c == mx { ans = min(ans, i) }
    }
    return ans
}