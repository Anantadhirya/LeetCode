func findLonely(nums []int) []int {
    m := make(map[int]int, len(nums))
    ans := make([]int, 0, len(nums))
    for _, i := range nums { m[i]++ }
    for _, i := range nums {
        if m[i] == 1 && m[i-1] == 0 && m[i+1] == 0 { ans = append(ans, i) }
    }
    return ans
}