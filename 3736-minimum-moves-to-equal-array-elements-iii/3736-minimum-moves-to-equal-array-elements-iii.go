func minMoves(nums []int) int {
    mx := slices.Max(nums)
    ans := 0
    for _, i := range nums {
        ans += mx - i
    }
    return ans
}