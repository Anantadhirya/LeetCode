func sumDivisibleByK(nums []int, k int) int {
    ans := 0
    m := make(map[int]int, len(nums))
    for _, i := range nums { m[i]++ }
    for i, c := range m {
        if c % k == 0 { ans += i*c }
    }
    return ans
}